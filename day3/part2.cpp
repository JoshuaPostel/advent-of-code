#include <stdio.h>
#include <fstream>
#include <iostream>
#include <bitset>
#include <array>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

const int size = 12;

tuple<vector<bitset<size>>, vector<bitset<size>>> seperate(vector<bitset<size>> bytes_vec, int index) {
    vector<bitset<size>> zeros;
    vector<bitset<size>> ones;
    for (bitset<size> bits : bytes_vec) {
        //bitset is little edian order so reverse index
        if (bits[(size - 1) - index] == 0) {
            zeros.push_back(bits);
        } else {
            ones.push_back(bits);
        }
    }
    return make_tuple(zeros, ones);
}

//TODO can we make this generic? std::bitset<N>
vector<bitset<size>> keep_most_common(vector<bitset<size>> bytes_vec, int index) {
    // vector<bitset<size>> zeros;
    // vector<bitset<size>> ones;
    // tie(zeros, ones) = seperate(bytes_vec, index);
    auto [zeros, ones] = seperate(bytes_vec, index);

    if (ones.size() >= zeros.size()) {
        return ones;
    } else {
        return zeros;
    }
}

vector<bitset<size>> keep_least_common(vector<bitset<size>> bytes_vec, int index) {
    auto [zeros, ones] = seperate(bytes_vec, index);

    if (zeros.size() <= ones.size()) {
        return zeros;
    } else {
        return ones;
    }
}

int main() {
    ifstream bytes("input.txt");

    array<int, size> on_bit_counter = { 0 };
    vector<bitset<size>> bytes_vec;

    // bitset store the bits in little edian order
    std::bitset<size> bits;
    while (bytes >> bits) {
        for (int i=size-1; i>=0; i--) {
            on_bit_counter[i] += bits[i];
        }
        bytes_vec.push_back(bits);
    }

    vector<bitset<size>> bytes_vec2 = bytes_vec;

    int index = 0;
    while (bytes_vec.size() > 1) {
        bytes_vec = keep_most_common(bytes_vec, index);
        index += 1;
    }
    long int oxygen_generator_rating = bytes_vec.back().to_ulong();
    printf("oxygen generator rating: %li\n", oxygen_generator_rating);

    index = 0;
    while (bytes_vec2.size() > 1) {
        bytes_vec2 = keep_least_common(bytes_vec2, index);
        index += 1;
    }
    long int co2_scrubber_rating = bytes_vec2.back().to_ulong();
    printf("co2 scrubber rating: %li\n", co2_scrubber_rating);

    printf("solution: %li\n", co2_scrubber_rating * oxygen_generator_rating);

    return 0;
}
