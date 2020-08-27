#include "pascals_triangle.h"
#include <vector>

namespace pascals_triangle {
int fetch(std::vector<int> map, int index) {
  if (index < 0 || index >= (int)map.size()) {
    return 0;
  }

  return map.at(index);
}

std::vector<std::vector<int>> generate_rows(int height) {
  if (height < 1) {
    return {};
  }

  std::vector<std::vector<int>> rows = {{1}};

  for (int i = 1; i < height; i++) {
    std::vector<int> previous_row = rows.at(i - 1);
    std::vector<int> current_row = {1};

    for (int j = 1; j < i + 1; j++) {
      int value = fetch(previous_row, j - 1) + fetch(previous_row, j);
      current_row.push_back(value);
    }

    rows.push_back(current_row);
  }

  return rows;
}
} // namespace pascals_triangle
