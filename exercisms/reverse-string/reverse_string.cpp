#include "reverse_string.h"

#include <string>

namespace reverse_string {
std::string reverse_string(std::string str) {
  std::string reversed = "";
  int length = static_cast<int>(str.length());

  for (int i = length - 1; i >= 0; --i) {
    reversed = reversed + str[i];
  }

  return reversed;
}
} // namespace reverse_string
