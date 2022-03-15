#include <fstream>
#include <vector>
#include <iostream>
#include <stdint.h>
#include "rust_bingo.h"



//std::vector<int> get_draws(std::fstream& input_file) {
//  std::string first_line;
//  std::getline(input_file, first_line);
//  std::cout << "first line: " << first_line << "\n";
//}

//std::vector<Bingo> get_boards(std::fstream& input_file) {
//  
//}

//std::tuple<std::vector<int>, std::vector<Bingo>> parse_file(fstream& input_file) {
//  while ()
//}

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

int32_t plus_two(int32_t val) {
  return val + 2;
}
