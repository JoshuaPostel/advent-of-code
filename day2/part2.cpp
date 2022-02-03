#include <stdio.h>
#include <fstream>

int main() {
    std::ifstream commands("input.txt");

    int depth = 0;
    int horizontal = 0;
    int aim = 0;

    for (std::string line; std::getline(commands, line);) {
        int pos = line.find(" ");
        std::string command = line.substr(0, pos);
        int amount = std::stoi(line.substr(pos + 1));

        if (command == "forward") {
            horizontal += amount;
            depth += aim * amount;
        } else if (command == "up") {
            aim -= amount;
        } else if (command == "down") {
            aim += amount;
        } else {
            printf("unexpected command: %s", command.c_str());
        }
    }
    printf("horizontal: %d, depth: %d\n", horizontal, depth);
    printf("product: %d\n", horizontal * depth);

    return 0;
}
