#include <stdio.h>
#include <fstream>
#include <iostream>
#include <bitset>
#include <array>
// TODO seems circular? 
// is this the proper way?
#include "day3.h"

Rates get_rates(std::fstream& bytes) {

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

    std::bitset<size> epsilon= ~gamma;

    struct Rates rates;
    rates.gamma = gamma.to_ulong();
    rates.epsilon = epsilon.to_ulong();
    return rates;
}
