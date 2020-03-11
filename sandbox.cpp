#include <iostream>
#include <regex>
#include <string>

int main() {
  std::string str = "1100101b";
  std::regex reg("\\D+");

  std::cout << "there's a non-digit? " << std::regex_search(str, reg)
            << std::endl;
}
