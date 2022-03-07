#include <stdio.h>
#include <fstream>
#include <array>
#include <algorithm>

int windowed_increase_count(std::fstream& depths) {

    int depth;
    // TODO not sure what the difference is here
    // thought this declared an std::array<int, 4>
    // but window.begin() not a member for it
    // int window [4]; 
    std::array<int, 4> window;

    // read in first four ints
    for (int i=0; i<4; i++) {
        depths >> window[i];
    }


    int increase_count = 0;
    if (window[0] < window[3]) {
        increase_count += 1;
    }

    while (depths >> depth) {
        
        // manual shitf approach
        // window[0] = window[1];
        // window[1] = window[2];
        // window[2] = window[3];
        // window[3] = depth;

        // std::rotate approach for generic length window
        std::rotate(window.begin(), window.begin() + 1, window.end());
        window[3] = depth;

        if (window[0] < window[3]) {
            increase_count += 1;
        }
    }

    return increase_count;
}
