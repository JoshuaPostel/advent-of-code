#include <fstream>
#include <stdio.h>

int increase_count(std::fstream& depths) {

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

  return increase_count;

}
