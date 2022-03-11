#include <config.h>
#include <day3.h>
#include <fstream>
#include <gtest/gtest.h>
#include <stdio.h>

TEST(Day3Test, Part1InstructionsExample) {
  std::string test_file(config::test_resource_dir);
  // using full_input.txt because I wrote the code before the tests and used
  // arrays/bitsets instead of vectors (example is 5 bits, question is 12 bits)
  test_file.append("/full_input.txt");
  std::fstream example_input(test_file);
  Rates rates = get_rates(example_input);
  EXPECT_EQ(rates.gamma, 2601);
  EXPECT_EQ(rates.epsilon, 1494);
}

TEST(Day3Test, Part2InstructionsExample) {
  std::string test_file(config::test_resource_dir);
  // using full_input.txt because I wrote the code before the tests and used
  // arrays/bitsets instead of vectors (example is 5 bits, question is 12 bits)
  test_file.append("/full_input.txt");
  std::fstream example_input(test_file);
  Ratings ratings = get_ratings(example_input);
  EXPECT_EQ(ratings.oxygen_generator, 3775);
  EXPECT_EQ(ratings.co2_scrubber, 1159);
}
