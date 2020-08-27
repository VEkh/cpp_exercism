#include "difference_of_squares.h"
#include <math.h>

namespace difference_of_squares {
int difference(int max) { return square_of_sum(max) - sum_of_squares(max); }

int square_of_sum(int max) {
  int sum = 0;

  for (int i = 1; i <= max; ++i) {
    sum = sum + i;
  }

  return pow(sum, 2);
}

int sum_of_squares(int max) {
  int sum = 0;

  for (int i = 1; i <= max; ++i) {
    sum = sum + pow(i, 2);
  }

  return sum;
}
} // namespace difference_of_squares
