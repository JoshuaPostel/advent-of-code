#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include "day4.h"
#include "rust_bingo.h"

std::vector<int> get_draws(std::fstream &input_file) {
  std::vector<int> draws;
  std::string first_line;
  std::getline(input_file, first_line);
  size_t pos = 0;
  while ((pos = first_line.find(",")) != std::string::npos) {
    std::string number = first_line.substr(0, pos);
    int draw = std::stoi(number);
    draws.push_back(draw);
    first_line.erase(0, pos + 1);
  }
  // capture last number
  int draw = std::stoi(first_line);
  draws.push_back(draw);
  return draws;
}

Bingo get_board(std::fstream &input_file) {
  std::array<std::array<uint8_t, 5>, 5> board;
  for (int i = 0; i < 5; i += 1) {
    std::string line;
    std::getline(input_file, line);
    for (int j = 0; j < 5; j += 1) {
      board[i][j] = std::stoi(line.substr(j * 3, (j + 1) * 3));
    }
  }
  Bingo bingo;
  bingo.board = board;
  std::array<bool, 5> empty = {false, false, false, false, false};
  bingo.marked = {empty, empty, empty, empty, empty};
  return bingo;
}

std::tuple<std::vector<int>, std::vector<Bingo>>
parse_input(std::fstream &input_file) {
  std::vector<int> draws = get_draws(input_file);
  std::vector<Bingo> bingos;

  while (input_file.peek() != EOF) {
    std::string skip_line;
    std::getline(input_file, skip_line);
    Bingo bingo = get_board(input_file);
    //bingo.print();
    bingos.push_back(bingo);
  }

  return {draws, bingos};
}

std::array<int, 2> run_bingo(std::vector<int> draws, std::vector<Bingo> boards) {
  std::vector<int> turns;
  std::vector<int> scores;
  for (Bingo board : boards) {
    int turn_counter = 0;
    for (int draw : draws) {
      turn_counter += 1;
      int score = board.mark(draw);
      if (score != 0) {
        turns.push_back(turn_counter);
        scores.push_back(score);
        break;
      }
    }
  }
  auto winning_turn = *std::min_element(turns.begin(), turns.end());
  auto loosing_turn = *std::max_element(turns.begin(), turns.end());
  std::vector<int> bingo_on_winning_turn;
  std::vector<int> bingo_on_loosing_turn;
  for (size_t i = 0; i < turns.size(); i += 1) {
    if (turns[i] == winning_turn) {
      bingo_on_winning_turn.push_back(scores[i]);
    } else if (turns[i] == loosing_turn) {
      bingo_on_loosing_turn.push_back(scores[i]);
    }
  }
  auto winning_score = *std::max_element(bingo_on_winning_turn.begin(), bingo_on_winning_turn.end());
  auto loosing_score = *std::min_element(bingo_on_loosing_turn.begin(), bingo_on_loosing_turn.end());
  return {winning_score, loosing_score};
}

Bingo new_board() {
  std::array<uint8_t, 5> one = {1, 0, 0, 0, 0};
  std::array<uint8_t, 5> two = {2, 0, 0, 0, 0};
  std::array<bool, 5> empty = {false, false, false, false, false};
  Bingo my_bingo;
  my_bingo.board = {one, two, two, two, two};
  my_bingo.marked = {empty, empty, empty, empty, empty};

  return my_bingo;
}

int32_t Bingo::score(int32_t just_called) const noexcept {
  int total = 0;
  for (std::size_t i = 0; i < this->board.size(); i += 1) {
    for (std::size_t j = 0; j < this->board[i].size(); j += 1) {
      if (!this->marked[i][j]) {
        total += this->board[i][j];
      }
    }
  }
  return total * just_called;
}
