#include <iostream>
#include <regex>
#include <string>

int main() {
  bool is_valid = std::regex_match(
      ("foobar"), std::regex(".*foo.*", std::regex_constants::icase));
  std::cout << "is valid: " << is_valid << std::endl;
}
