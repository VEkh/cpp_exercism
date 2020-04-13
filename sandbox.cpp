#include <iostream>
#include <map>
#include <string>

int main() {
  std::string str = "foo";
  std::map<char, int> dict = {{'c', 100}};

  std::cout << std::string(1, dict.at(tolower('C'))) + "bar" << std::endl;

  for (char c : str) {
    std::cout << std::string(1, tolower(c)) << std::endl;
    std::cout << std::string(1, toupper(c)) << std::endl;
  }
}
