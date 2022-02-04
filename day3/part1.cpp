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

    // if we need to reverse
//    for (int i=size-1; i>=0; i--) {
//        printf("i: %d\n", i);
//    }

    while (bytes >> bits) {
        for (int i=size-1; i>=0; i--) {
            on_bit_counter[i] += bits[i];
        }
        total_bits += 1;
    }

    std::string byte_string = "";
    for (int i=0; i<size; i++) {
        //printf("i: %d, v: %d\n", i, on_bit_counter[i]);    
        if (on_bit_counter[i] > total_bits / 2) {
            byte_string.push_back('1');
        } else {
            byte_string.push_back('0');
            // TODO 
            // there appears to be a difference between "" and ''
            // figure out what the type differnce is and why
            //byte_string.push_back("0");
        }
    }

    std::bitset<size> gamma;
    printf("byte_string: %s\n", byte_string.c_str());





//
//
//
//    int depth = 0;
//    int horizontal = 0;
//
//    for (std::string line; std::getline(commands, line);) {
//        int pos = line.find(" ");
//        std::string command = line.substr(0, pos);
//        int amount = std::stoi(line.substr(pos + 1));
//
//        if (command == "forward") {
//            horizontal += amount;
//        } else if (command == "up") {
//            depth -= amount;
//        } else if (command == "down") {
//            depth += amount;
//        } else {
//            printf("unexpected command: %s", command.c_str());
//        }
//    }
//    printf("horizontal: %d, depth: %d\n", horizontal, depth);
//    printf("product: %d\n", horizontal * depth);

    return 0;
}
