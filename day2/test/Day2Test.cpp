#include <gtest/gtest.h>
#include <fstream>
#include <day2.h>
#include <config.h>
#include <stdio.h>

TEST(Day2Test, Part1InstructionsExample) {
  std::cout << "file_dir: " << config::test_resource_dir << "\n";
  std::string test_file(config::test_resource_dir);
  test_file.append("/example_input.txt");
  std::fstream example_input(test_file); 
  int horizontal;
  int depth;
  std::tie(horizontal, depth) = horizontal_and_depth(example_input);
  EXPECT_EQ(horizontal, 15);
  EXPECT_EQ(depth, 10);
}

TEST(Day2Test, Part2InstructionsExample) {
  std::string test_file(config::test_resource_dir);
  test_file.append("/example_input.txt");
  std::fstream example_input(test_file); 
  int horizontal;
  int depth;
  std::tie(horizontal, depth) = horizontal_and_aimed_depth(example_input);
  EXPECT_EQ(horizontal, 15);
  EXPECT_EQ(depth, 60);
}
