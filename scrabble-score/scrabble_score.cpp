#include "scrabble_score.h"

#include <map>
#include <string>

namespace scrabble_score {
std::map<char, int> scoring = {
    {'a', 1}, {'e', 1}, {'i', 1}, {'o', 1},  {'u', 1},  {'l', 1}, {'n', 1},
    {'r', 1}, {'s', 1}, {'t', 1}, {'d', 2},  {'g', 2},  {'b', 3}, {'c', 3},
    {'m', 3}, {'p', 3}, {'f', 4}, {'h', 4},  {'v', 4},  {'w', 4}, {'y', 4},
    {'k', 5}, {'j', 8}, {'x', 8}, {'q', 10}, {'z', 10},
};

int score(std::string word) {
  int score_ = 0;

  for (size_t i = 0; i < word.size(); ++i) {
    int char_score = scoring.at(std::tolower(word[i]));

    score_ += char_score;
  }

  return score_;
}
} // namespace scrabble_score
