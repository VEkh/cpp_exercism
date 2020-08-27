#include "allergies.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_set>

namespace allergies {
std::string ALLERGENS[] = {
    "eggs",     "peanuts",   "shellfish", "strawberries",
    "tomatoes", "chocolate", "pollen",    "cats",
};

int start_count_from(int score) {
  if (score < 1) {
    return -1;
  }

  return floor(log(score) / log(2));
}

allergy_test::allergy_test(int score) {
  score_ = score % 256;
  init_allergies();
}

std::unordered_set<std::string> allergy_test::get_allergies() {
  return allergies;
}

bool allergy_test::is_allergic_to(std::string allergenic) {
  return std::find(allergies.begin(), allergies.end(), allergenic) !=
         allergies.end();
}

void allergy_test::init_allergies() {
  int consumed_score = score_;
  int index = start_count_from(score_);

  while (index >= 0) {
    int allergen_score = pow(2, index);

    if (consumed_score - allergen_score >= 0) {
      allergies.insert(ALLERGENS[index]);
      consumed_score -= allergen_score;
    }

    index--;
  }
}

} // namespace allergies
