#include "matching_brackets.h"
#include <iostream>
#include <map>
#include <regex>
#include <string>
#include <vector>

namespace matching_brackets {
std::map<char, char> lookup = {
    {'(', ')'},
    {'[', ']'},
    {'{', '}'},
};

std::regex close_bracket_regex("\\)|\\]|\\}");
std::regex open_bracket_regex("\\(|\\[|\\{");

bool check(std::string str) {
  std::vector<char> open_brackets;

  for (char c : str) {
    char char_string[] = {c};

    if (std::regex_match(char_string, open_bracket_regex)) {
      open_brackets.push_back(c);
      continue;
    }

    if (std::regex_match(char_string, close_bracket_regex) &&
        !open_brackets.empty()) {
      if (c == lookup.at(open_brackets.back())) {
        open_brackets.pop_back();
        continue;
      } else {
        return false;
      }
    }
  }

  return open_brackets.size() == 0;
}
} // namespace matching_brackets
