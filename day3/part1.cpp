#include <stdio.h>
#include <fstream>
#include <iostream>
#include <bitset>
#include <array>

int main() {
    std::ifstream bytes("input.txt");

    const int size = 12;
    int total_bits = 0;
    std::array<int, size> on_bit_counter = { 0 };

    // bitset store the bits in little edian order
    std::bitset<size> bits;

    while (bytes >> bits) {
        for (int i=size-1; i>=0; i--) {
            on_bit_counter[i] += bits[i];
        }
        total_bits += 1;
    }


    std::bitset<size> gamma;
    for (int i=0; i<size; i++) {
        if (on_bit_counter[i] > total_bits / 2) {
            gamma[i] = 1;
        } else {
            gamma[i] = 0;
        }
    }


    std::cout << "gamma: " << gamma << "\n";
    printf("gamma: %lu\n", gamma.to_ulong());

    std::bitset<size> epsilon= ~gamma;
    printf("epsilon: %lu\n", epsilon.to_ulong());

    printf("answer: %lu\n", gamma.to_ulong() * epsilon.to_ulong());

    return 0;
}

// unused code
// std::string byte_string = "";
// for (int i=0; i<size; i++) {
//     if (on_bit_counter[i] > total_bits / 2) {
//         byte_string.push_back('1');
//     } else {
//         byte_string.push_back('0');
//         // TODO 
//         // there appears to be a difference between "" and ''
//         // figure out what the type differnce is and why
//         //byte_string.push_back("0");
//     }
//    }
