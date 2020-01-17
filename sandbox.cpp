#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

int main() {
  std::string str = "foobar";
  std::stringstream reversed;
  int length = static_cast<int>(str.length());

  for (int i = length - 1; i >= 0; --i) {
    reversed << str[i] << "\n";
    std::cout << str[i] << "\n";
  }

  std::cout << reversed.str() << "\n";

  /*   char str[] = {'I'}; */
  /*   std::cout << str << "\n"; */
}
