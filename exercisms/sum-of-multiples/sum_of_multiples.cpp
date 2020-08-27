#include "sum_of_multiples.h"

#include <set>

namespace sum_of_multiples {
int to(std::vector<int> range, int max) {
  int sum = 0;
  std::set<int> products;

  for (size_t i = 0; i < range.size(); ++i) {
    int base = range[i];
    int multiplier = 1;

    while (base * multiplier < max) {
      int product = base * multiplier;
      products.insert(product);
      ++multiplier;
    }
  }

  std::set<int>::iterator it;

  for (it = products.begin(); it != products.end(); ++it) {
    sum += *it;
  }

  return sum;
}
} // namespace sum_of_multiples
