#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include "day4.h"
#include "rust_bingo.h"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "usage: " << argv[0] << " my_filename.txt\n";
  } else {
    std::fstream input_file(argv[1]);
    std::vector<int> draws;
    std::vector<Bingo> boards;
    std::tie(draws, boards) = parse_input(input_file);
    std::array<int, 2> solution = run_bingo(draws, boards);
    std::cout << "day4 part 1 solution: " << solution[0] << "\n";
    std::cout << "day4 part 2 solution: " << solution[1] << "\n";
  }
  return 0;
}
