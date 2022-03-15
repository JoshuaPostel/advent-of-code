#include <fstream>
#include <vector>
#include <iostream>
#include "day4.h"
#include "rust_bingo.h"

std::vector<int> get_draws(std::fstream& input_file) {
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
  for (size_t i = 0; i < draws.size(); i += 1) {
    std::cout << "first line vec: " << draws[i] << "\n";
  }
  return draws;
}

int main() {
  int a = 4;
  std::cout << "a: " << a << "\n";
  std::cout << "a plus two: " << plus_two(a) << "\n";
  std::cout << "a rust plus one: " << plus_one(a) << "\n";
  std::cout << "a rust times two: " << times_two(a) << "\n";
  Bingo my_board = new_board();
  my_board.print();
  std::cout << "mark: " << my_board.mark(0) << "\n";
  my_board.print();
  std::cout << "mark: " << my_board.mark(1) << "\n";
  my_board.print();




  std::fstream input_file("/home/jp/proj/aoc/day4/test/resources/example_input.txt");
  get_draws(input_file);
}

