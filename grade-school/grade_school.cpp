#include "grade_school.h"

#include <algorithm>
#include <map>
#include <vector>

namespace grade_school {
school::school() { roster_ = {}; }

void school::add(std::string name, int grade) {
  std::map<int, std::vector<std::string>>::iterator roster_iterator;
  std::vector<std::string> students = {};

  roster_iterator = roster_.find(grade);

  if (roster_.find(grade) != roster_.end()) {
    students = roster_iterator->second;
  }

  students.push_back(name);

  std::sort(students.begin(), students.end());

  roster_[grade] = students;
}

std::vector<std::string> school::grade(int grade_) const {
  if (roster_.find(grade_) == roster_.end()) {
    return {};
  }

  return roster_.at(grade_);
}

std::map<int, std::vector<std::string>> school::roster() const {
  return roster_;
}
} // namespace grade_school
