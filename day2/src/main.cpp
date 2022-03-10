#include <iostream>
#include <fstream>
#include "day2.h"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "usage: " << argv[0] << " my_filename.txt\n";
  } else {
    std::fstream part1_input(argv[1]);
    int horizontal;
    int depth;
    std::tie(horizontal, depth) = horizontal_and_depth(part1_input);
    std::cout << "day2 part 1 solution: " << horizontal * depth << "\n";

    std::fstream part2_input(argv[1]);
    std::tie(horizontal, depth) = horizontal_and_aimed_depth(part2_input);
    std::cout << "day2 part 1 solution: " << horizontal * depth << "\n";
  }
  return 0;
}
