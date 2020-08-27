#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H

#include <map>
#include <vector>

namespace grade_school {
class school {
private:
  std::map<int, std::vector<std::string>> roster_;

public:
  school();

  void add(std::string, int);
  std::vector<std::string> grade(int) const;
  std::map<int, std::vector<std::string>> roster() const;
};
} // namespace grade_school

#endif // GRADE_SCHOOL_H
