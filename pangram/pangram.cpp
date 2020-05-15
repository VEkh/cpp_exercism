#include "pangram.h"
#include <algorithm>
#include <string>

namespace pangram {
bool is_pangram(std::string input) {
  std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
  std::string::iterator letter_position;

  for (char letter : input) {
    letter_position =
        std::find(alphabet.begin(), alphabet.end(), tolower(letter));

    if (letter_position != alphabet.end()) {
      alphabet.erase(letter_position);
    }
  }

  return alphabet.empty();
}
} // namespace pangram
