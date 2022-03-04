#include <gtest/gtest.h>
#include <fstream>
#include <day1.h>

TEST(Day1Test, InstructionsExample) {
  // TODO how to reference this file location?
  std::fstream example_input("resources/input.txt"); 
  int result = increase_count(example_input);
  EXPECT_EQ(result, 7);
  EXPECT_EQ(1, 1);
}
