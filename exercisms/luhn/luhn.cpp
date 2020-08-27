#include "luhn.h"
#include <iostream>
#include <regex>
#include <string>

namespace luhn {
bool valid(std::string input) {
  std::regex invalid_input("\\D");
  std::regex whitespace_regex("\\s+");

  std::string trimmed_input = std::regex_replace(input, whitespace_regex, "");

  if (trimmed_input.length() <= 1 ||
      std::regex_search(trimmed_input, invalid_input)) {
    return false;
  }

  std::string::reverse_iterator it = trimmed_input.rbegin();
  int i = 0;
  int sum = 0;

  while (it != trimmed_input.rend()) {
    int digit = std::stoi(std::string(1, *it));

    if (i % 2 == 1) {
      int doubled = digit * 2;
      sum += doubled > 9 ? doubled - 9 : doubled;
    } else {
      sum += digit;
    }

    it++;
    i++;
  }

  return sum % 10 == 0;
}
} // namespace luhn
