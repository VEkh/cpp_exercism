#include "trinary.h"
#include <cmath>
#include <regex>
#include <string>

namespace trinary {
int to_decimal(std::string input) {
  int decimal = 0;

  if (std::regex_search(input, std::regex("\\D+"))) {
    return decimal;
  }

  for (int power = 0, i = (int)input.length() - 1; i >= 0; ++power, --i) {
    int multiplier = std::stoi(std::string(1, input[i]));
    decimal += multiplier * pow(3, power);
  }

  return decimal;
}
} // namespace trinary
