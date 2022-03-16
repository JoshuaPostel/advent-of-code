#include <gtest/gtest.h>
#include <fstream>
#include <config.h>
#include <stdio.h>
#include <day4.h>
#include "rust_bingo.h"


TEST(Day4Test, ParseInput) {
  std::string test_file(config::test_resource_dir);
  test_file.append("/example_input.txt");
  std::fstream example_input(test_file); 
  std::vector<int> draws;
  std::vector<Bingo> boards;
  std::tie(draws, boards) = parse_input(example_input);

  std::vector<int> expected_draws = {7,4,9,5,11,17,23,2,0,14,21,24,10,16,13,6,15,25,12,22,18,20,8,19,3,26,1};

  std::array<bool, 5> empty = {false, false, false, false, false};
  std::array<uint8_t, 5> row1 = {22, 13, 17, 11, 0};
  std::array<uint8_t, 5> row2 = {8, 2, 23, 4, 24};
  std::array<uint8_t, 5> row3 = {21, 9, 14, 16, 7};
  std::array<uint8_t, 5> row4 = {6, 10, 3, 18, 5};
  std::array<uint8_t, 5> row5 = {1, 12, 20, 15, 19};
  Bingo expected_first_board;
  expected_first_board.board = {row1, row2, row3, row4, row5};
  expected_first_board.marked = {empty, empty, empty, empty, empty};
  
  EXPECT_EQ(draws, expected_draws);
  EXPECT_EQ(boards[0].board, expected_first_board.board);
  EXPECT_EQ(boards[0].marked, expected_first_board.marked);
}

TEST(Day4Test, Part1InstructionsExample) {
  std::string test_file(config::test_resource_dir);
  test_file.append("/example_input.txt");
  std::fstream example_input(test_file); 
  std::vector<int> draws;
  std::vector<Bingo> boards;
  std::tie(draws, boards) = parse_input(example_input);
  std::array<int, 2> solution = run_bingo(draws, boards);

  EXPECT_EQ(solution[0], 4512);
}
