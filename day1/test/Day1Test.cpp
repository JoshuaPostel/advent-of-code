#include <gtest/gtest.h>
#include <fstream>
#include <day1.h>
#include <config.h>
#include <stdio.h>

TEST(Day1Test, Part1InstructionsExample) {
  std::cout << "file_dir: " << config::test_resource_dir << "\n";
  std::string test_file(config::test_resource_dir);
  test_file.append("/example_input.txt");
  std::cout << "file_path: " << test_file << "\n";
  std::fstream example_input(test_file); 
  int result = increase_count(example_input);
  EXPECT_EQ(result, 7);
}

TEST(Day1Test, Part2InstructionsExample) {
  std::string test_file(config::test_resource_dir);
  test_file.append("/example_input.txt");
  std::fstream example_input(test_file); 
  int result = windowed_increase_count(example_input);
  EXPECT_EQ(result, 5);
}
