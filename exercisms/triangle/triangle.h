#if !defined(TRIANGLE_H)
#define TRIANGLE_H

namespace triangle {
enum struct flavor { scalene = 0, isosceles = 1, equilateral = 3 };

flavor kind(double, double, double);

void validate(double (&)[3]);

void validate_length(double (&)[3]);

void validate_non_negative(double (&)[3]);

void validate_non_zero(double (&)[3]);
} // namespace triangle

#endif // TRIANGLE_H
