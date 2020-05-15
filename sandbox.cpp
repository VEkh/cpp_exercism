#include <iostream>
#include <string>

int main() {
  std::string str = "foo";
  str += "b";
  std::cout << str << std::endl;
  std::cout << str.size() << std::endl;
}
