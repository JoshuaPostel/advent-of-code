#include <stdint.h>
#include "rust_bingo.h"

int32_t plus_two(int32_t val) {
  return val + 2;
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

int32_t Bingo::score() const noexcept {
  int total = 0;
//  for (const auto& row: this->board ) {
//    for (const auto& element: row) {
//      total += element;
//    }
//  }
  for (std::size_t i = 0; i < this->board.size(); i += 1) {
    for (std::size_t j = 0; j < this->board[i].size(); j += 1) {
      if (this->marked[i][j]) {
        total += this->board[i][j];
      }
    }
  }
  return total;
}
