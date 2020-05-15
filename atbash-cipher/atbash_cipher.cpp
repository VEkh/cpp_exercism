#include "atbash_cipher.h"
#include <iostream>
#include <regex>
#include <string>

namespace atbash_cipher {
char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                   'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                   's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int index_of(char list[], char character) {
  for (int index = 0; list[index]; index++) {
    if (character == list[index]) {
      return index;
    }
  }

  return -1;
}

const std::regex number_regexp("\\d");
bool is_number(char character) {
  const char search[] = {character};
  return std::regex_search(search, number_regexp);
}

std::string parse(std::string input, bool with_space) {
  const int alphabet_length = sizeof(alphabet) / sizeof(*alphabet);

  std::string result = "";
  int result_length = 0;
  int l = input.length();

  for (int i = 0; i < l; i++) {
    const char c = tolower(input[i]);
    const int index = index_of(alphabet, c);

    const bool is_char = index > -1;
    const bool is_num = is_number(c);

    if (is_char || is_num) {
      const int decoded_index = alphabet_length - index - 1;

      if (with_space && result_length > 0 && result_length % 5 == 0) {
        result += " ";
      }

      if (is_char) {
        result += alphabet[decoded_index];
      } else if (is_num) {
        result += c;
      }

      result_length++;
    }
  }

  return result;
}

std::string decode(std::string input) { return parse(input, false); }

std::string encode(std::string input) { return parse(input, true); }
} // namespace atbash_cipher
