#include <stdio.h>
#include <fstream>
#include <tuple>

std::tuple<int, int> horizontal_and_depth(std::fstream& commands) {

    int depth = 0;
    int horizontal = 0;

    for (std::string line; std::getline(commands, line);) {
        int pos = line.find(" ");
        std::string command = line.substr(0, pos);
        int amount = std::stoi(line.substr(pos + 1));

        if (command == "forward") {
            horizontal += amount;
        } else if (command == "up") {
            depth -= amount;
        } else if (command == "down") {
            depth += amount;
        } else {
            printf("unexpected command: %s", command.c_str());
        }
    }
    return {horizontal, depth};
}
