#include <iostream>
#include <regex>
#include <string>

int main() {
  std::regex r("[a-z]");

  if (std::regex_match(std::string(1, 'f'), r)) {
    std::cout << "matches\n";
  }
}
