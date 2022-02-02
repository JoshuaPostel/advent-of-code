#include <stdio.h>
#include <fstream>

int main() {
    std::ifstream depths("input.txt");

    int depth;
    int previous_depth;

    // read in first depth
    depths >> previous_depth;

    int increase_count = 0;
    while (depths >> depth) {
        if (depth > previous_depth) {
            increase_count += 1;
        }
        previous_depth = depth;
    }
    printf("increase_count: %d\n", increase_count);

    return 0;
}

// unused code:
// std::ofstream measurements("output.txt");

// char first_char = depths.get(); 
// printf("input.txt first character: %c\n", first_char);
//
// printf("first depth: %d\n", previous_depth);
// measurements << previous_depth << " (N/A - no previous measurement)\n";
