#include "armstrong_numbers.h"
#include <cmath>
#include <string>

namespace armstrong_numbers {
bool is_armstrong_number(int number) {
  std::string number_string = std::to_string(number);

  int power = number_string.size();
  int sum = 0;

  for (char digit : number_string) {
    int digit_num = std::stoi(std::string(1, digit));
    sum += pow(digit_num, power);
  }

  return sum == number;
}
} // namespace armstrong_numbers
