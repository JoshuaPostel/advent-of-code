#include <iostream>
#include "day4.h"
#include "rust_bingo.h"

int main() {
  int a = 4;
  std::cout << "a: " << a << "\n";
  std::cout << "a plus two: " << plus_two(a) << "\n";
  std::cout << "a rust plus one: " << plus_one(a) << "\n";
  std::cout << "a rust times two: " << times_two(a) << "\n";
  Bingo my_board = new_board();
  my_board.print();
  std::cout << "score: " << my_board.score() << "\n";
  std::cout << "mark: " << my_board.mark(0) << "\n";
  my_board.print();
  std::cout << "mark: " << my_board.mark(1) << "\n";
  my_board.print();
}
