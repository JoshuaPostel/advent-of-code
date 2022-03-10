#include <fstream>
#include <tuple>

struct Rates {
  unsigned long int gamma;
  unsigned long int epsilon;
};

struct Ratings {
  unsigned long int oxygen_generator;
  unsigned long int co2_scrubber;
};

Rates get_rates(std::fstream&);
Ratings get_ratings(std::fstream&);
