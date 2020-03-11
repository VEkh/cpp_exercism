#include "binary.h"

#include <cmath>
#include <regex>
#include <string>

namespace binary {
int convert(std::string input) {
  int decimal = 0;

  if (std::regex_search(input, std::regex("\\D+"))) {
    return decimal;
  }

  for (int power = 0, i = (int)input.length() - 1; i >= 0; ++power, --i) {
    int multiplier = std::stoi(std::string(1, input[i]));
    decimal += multiplier * pow(2, power);
  }

  return decimal;
}
} // namespace binary
