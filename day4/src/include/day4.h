#pragma once
#include <stdint.h>
#include <memory>
#include <vector>

struct Bingo;

std::vector<int> get_draws(std::fstream&);
Bingo get_board(std::fstream&);
std::tuple<std::vector<int>, std::vector<Bingo>> parse_input(std::fstream&);
std::array<int, 2> run_bingo(std::vector<int>, std::vector<Bingo>);

//int32_t plus_two(int32_t);
//Bingo new_board();
