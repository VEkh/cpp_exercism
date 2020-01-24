#include "etl.h"
#include <map>
#include <string>

namespace etl {
std::map<char, int> transform(std::map<int, std::vector<char>> original) {
  std::map<char, int> transformed = {};
  std::map<int, std::vector<char>>::iterator iterator;

  for (iterator = original.begin(); iterator != original.end(); ++iterator) {
    int old_key = iterator->first;
    std::vector<char> values = iterator->second;

    for (size_t i = 0; i < values.size(); ++i) {
      char new_key = std::tolower(values[i]);

      transformed[new_key] = old_key;
    }
  }

  return transformed;
}
} // namespace etl
