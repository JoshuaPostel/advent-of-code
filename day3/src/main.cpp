#include <iostream>
#include <fstream>
#include "day3.h"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "usage: " << argv[0] << " my_filename.txt\n";
  } else {
    std::fstream part1_input(argv[1]);
    Rates rates = get_rates(part1_input);
    std::cout << "day3 part 1 solution: " << rates.gamma * rates.epsilon << "\n";

    std::fstream part2_input(argv[1]);
    Ratings ratings = get_ratings(part2_input);
    std::cout << "day3 part 1 solution: " << ratings.oxygen_generator * ratings.co2_scrubber << "\n";
  }
  return 0;
}
