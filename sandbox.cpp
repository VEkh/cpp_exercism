#include <algorithm>
#include <iostream>
#include <string>

int main() {
  std::string str = "foo";

  std::string::iterator it = std::find(str.begin(), str.end(), 'a');
  std::cout << (it == str.end()) << std::endl;
}
