#include "triangle.h"

#include <set>
#include <stdexcept>

namespace triangle {
flavor kind(double a, double b, double c) {
  double sides[] = {a, b, c};
  int sides_count = sizeof(sides) / sizeof(*sides);

  validate(sides);

  int comparisons_count = 0;
  int equal_sides_count = 0;

  for (int i = 0; i < sides_count; ++i) {
    double current_side = sides[i];

    for (int ti = i + 1; ti < sides_count; ++ti) {
      if (current_side == sides[ti]) {
        ++equal_sides_count;
      }

      ++comparisons_count;
    }
  }

  return (flavor)equal_sides_count;
}

void validate(double (&sides)[3]) {
  validate_non_negative(sides);
  validate_non_zero(sides);
  validate_length(sides);
}

void validate_length(double (&sides)[3]) {
  std::set<double> ordered_sides;
  double side_sum = 0;

  ordered_sides.insert(sides, sides + 3);

  double largest_side = *ordered_sides.rbegin();

  for (double side : sides) {
    side_sum += side;
  }

  if (side_sum - largest_side < largest_side) {
    throw std::domain_error("Sides are not long enough");
  }
}

void validate_non_negative(double (&sides)[3]) {
  for (double side : sides) {
    if (side < 0) {
      throw std::domain_error("Can't have negative length sides");
    }
  }
}

void validate_non_zero(double (&sides)[3]) {
  for (double side : sides) {
    if (side == 0) {
      throw std::domain_error("Can't have zero-length sides");
    }
  }
}

} // namespace triangle
