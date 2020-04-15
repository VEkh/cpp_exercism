#include <iostream>
#include <map>
#include <regex>
#include <string>

int main() {
  std::string str = "foo bars do-not stop,ever";
  std::smatch match;
  std::regex word_char_regex("(\\b\\w)\\w+");

  std::regex_search(str, match, word_char_regex);
  std::cout << "match size: " << match.size() << std::endl;
  std::cout << "match match: " << match[0] << std::endl;
  std::cout << "match capture: " << match[1] << std::endl;
  std::cout << "match suffix: " << match.suffix() << std::endl;
  std::cout << "match string: " << match.str()[0] << std::endl;

  while (std::regex_search(str, match, word_char_regex)) {
    std::cout << match[1] << std::endl;
    str = match.suffix();
  }
}
