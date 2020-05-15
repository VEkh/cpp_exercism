#include <iostream>
#include <regex>
#include <string>

int main() {
  std::regex reg("\\D");
  std::string str = "059a";
  std::cout << std::regex_search(str, reg) << std::endl;
}
