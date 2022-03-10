#include <iostream>
#include <fstream>
#include "day1.h"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "usage: " << argv[0] << " my_filename.txt\n";
  } else {
    
    std::fstream part1_input_file(argv[1]);
    int part1_answer = increase_count(part1_input_file);
    std::cout << "day1 part1 solution: " << part1_answer << "\n";
  
    std::fstream part2_input_file(argv[1]);
    int part2_answer = windowed_increase_count(part2_input_file);
    std::cout << "day1 part2 solution: " << part2_answer << "\n";

  }

  return 0;
}
