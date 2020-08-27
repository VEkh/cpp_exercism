#include "hamming.h"
#include <stdexcept>
#include <string>

namespace hamming {
int compute(std::string a, std::string b) {
  if (a.length() != b.length()) {
    throw std::domain_error("DNA sequences must have equal length");
  }

  int distance = 0;

  for (size_t i = 0; i < a.length(); ++i) {
    if (a[i] != b[i]) {
      ++distance;
    }
  }

  return distance;
}
} // namespace hamming
