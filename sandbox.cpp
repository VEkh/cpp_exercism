#include <iostream>
#include <regex>
#include <vector>

int main() {
  std::regex open_bracket_regex("\\(|\\[|\\{");
  std::cout << std::regex_match(std::string(1, '{'), open_bracket_regex)
            << std::endl;

  std::vector<char> chars;
  // chars.push_back('a');
  // chars.push_back('b');

  std::cout << chars.back() << std::endl;
}
