#include <cmath>
#include <iostream>
#include <regex>
#include <string>

int main() {
  double power = log(0 % 256) / log(2);
  std::cout << power << std::endl;
  std::cout << pow(2, power) << std::endl;
}
