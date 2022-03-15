#include "day4.h"
#include "rust_bingo.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> get_draws(std::fstream &input_file) {
  std::vector<int> draws;
  std::string first_line;
  std::getline(input_file, first_line);
  std::cout << "first line: " << first_line << "\n";
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
  //  for (size_t i = 0; i < draws.size(); i += 1) {
  //    std::cout << "first line vec: " << draws[i] << "\n";
  //  }
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

int run_bingo(std::vector<int> draws, std::vector<Bingo> boards) {
  // TODO investigate: cannot mutate inner forloop
  // without this approach we are playing out all the boards even though we can
  // stop after the first winning round
  //  for (int draw : draws) {
  //    std::cout << "draw: " << draw << "\n";
  //    for (Bingo board : boards) {

  std::cout << "n_boards: " << boards.size() << "\n";
  std::vector<int> turns;
  std::vector<int> scores;
  for (Bingo board : boards) {
    int turn_counter = 0;
    for (int draw : draws) {
      turn_counter += 1;
      // std::cout << "draw: " << draw << "\n";

      // std::cout << "before\n";
      //board.print();
      int score = board.mark(draw);
      // std::cout << "after\n";
      // board.print();
      //std::cout << "\n";
      if (score != 0) {
        // std::cout << "done\n";
        turns.push_back(turn_counter);
        scores.push_back(score);
        break;
      }
    }
  }
  for (size_t i = 0; i < turns.size(); i += 1) {
    std::cout << "board " << i << ": turn: " << turns[i]
              << " score: " << scores[i] << "\n";
  }
  auto winning_turn = *std::min_element(turns.begin(), turns.end());
  std::cout << "winnin_turn: " << winning_turn << "\n";
  // TODO do this the smarter way
  std::vector<int> won_on_winning_turn;
  for (size_t i = 0; i < turns.size(); i += 1) {
    if (turns[i] == winning_turn) {
      won_on_winning_turn.push_back(scores[i]);
    }
  }
  auto winning_score = *std::max_element(won_on_winning_turn.begin(), won_on_winning_turn.end());
  return winning_score;
  //return 0;
}

int main() {
  //  int a = 4;
  //  std::cout << "a: " << a << "\n";
  //  std::cout << "a plus two: " << plus_two(a) << "\n";
  //  std::cout << "a rust plus one: " << plus_one(a) << "\n";
  //  std::cout << "a rust times two: " << times_two(a) << "\n";
  // TODO why does commenting this out mess up imports?
  Bingo my_board = new_board();
  //  my_board.print();
  //  std::cout << "mark: " << my_board.mark(0) << "\n";
  //  my_board.print();
  //  std::cout << "mark: " << my_board.mark(1) << "\n";
  //  my_board.print();

//  std::fstream input_file(
//      "/home/jp/proj/aoc/day4/test/resources/example_input.txt");
  std::fstream input_file(
      "/home/jp/proj/aoc/day4/test/resources/full_input.txt");
  std::vector<int> draws;
  std::vector<Bingo> boards;
  std::tie(draws, boards) = parse_input(input_file);
  int answer = run_bingo(draws, boards);
  std::cout << "answer: " << answer << "\n";
  //  std::vector<int> draws = get_draws(input_file);
  //  std::string skip_line;
  //  std::getline(input_file, skip_line);
  //  Bingo bingo = get_board(input_file);
  //  bingo.print();
}
