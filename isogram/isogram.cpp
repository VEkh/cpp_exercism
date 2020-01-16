#include <iostream>
#include <map>
#include <regex>
#include <string>

#include "isogram.h"

namespace isogram {
bool is_isogram(std::string value) {
  std::map<char, bool> acc;

  for (size_t i = 0; i < value.length(); ++i) {
    char character = std::tolower(value[i]);
    bool is_word_character =
        std::regex_match(std::string(1, character), std::regex("[a-z]"));

    if (!is_word_character) {
      continue;
    }

    if (acc[character]) {
      return false;
    }

    acc[character] = true;
  }

  return true;
}
} // namespace isogram
