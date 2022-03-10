#include <gtest/gtest.h>
#include <fstream>
#include <day3.h>
#include <config.h>
#include <stdio.h>

TEST(Day3Test, Part1InstructionsExample) {
  std::string test_file(config::test_resource_dir);
  test_file.append("/example_input.txt");
  std::fstream example_input(test_file); 
  Rates rates = get_rates(example_input);
  EXPECT_EQ(rates.gamma, 22);
  EXPECT_EQ(rates.epsilon, 9);
}

TEST(Day3Test, Part2InstructionsExample) {
  std::string test_file(config::test_resource_dir);
  test_file.append("/example_input.txt");
  std::fstream example_input(test_file); 
  Ratings ratings = get_ratings(example_input);
  EXPECT_EQ(ratings.oxygen_generator, 23);
  EXPECT_EQ(ratings.co2_scrubber, 10);
}
