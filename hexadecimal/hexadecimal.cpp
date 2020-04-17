#include "hexadecimal.h"
#include <cmath>
#include <map>
#include <string>

namespace hexadecimal {
std::map<char, int> to_decimal = {
    {'0', 0},  {'1', 1},  {'2', 2},  {'3', 3},  {'4', 4}, {'5', 5},
    {'5', 5},  {'6', 6},  {'7', 7},  {'8', 8},  {'9', 9}, {'a', 10},
    {'b', 11}, {'c', 12}, {'d', 13}, {'e', 14}, {'f', 15}};

int convert(std::string input) {
  int power = 0;
  int result = 0;
  std::string::reverse_iterator it = input.rbegin();

  while (it != input.rend()) {
    if (to_decimal.find(*it) == to_decimal.end()) {
      return 0;
    }

    int summand = to_decimal.at(*it) * pow(16, power);
    result += summand;

    it++;
    power++;
  }

  return result;
}
} // namespace hexadecimal
