#include "collatz_conjecture.h"
#include <stdexcept>

namespace collatz_conjecture {
int steps(int input) {
  if (input < 1) {
    throw std::domain_error("Must be at least one");
  }

  if (input == 1) {
    return 0;
  }

  if (input % 2 == 0) {
    return 1 + steps(input / 2);
  }

  return 1 + steps(3 * input + 1);
}
} // namespace collatz_conjecture
