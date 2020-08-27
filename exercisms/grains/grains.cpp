#include "grains.h"
#include <cmath>

namespace grains {
unsigned long long square(int _square) { return std::pow(2, _square - 1); }
unsigned long long total() {
  unsigned long long sum = 0;

  for (int i = 1; i <= 64; ++i) {
    sum += square(i);
  }

  return sum;
}
} // namespace grains
