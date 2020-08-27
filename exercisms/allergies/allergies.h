#if !defined(ALLERGIES_H)
#define ALLERGIES_H
#include <string>
#include <unordered_set>

namespace allergies {
class allergy_test {
private:
  int score_;
  std::unordered_set<std::string> allergies;
  void init_allergies();

public:
  allergy_test(int);

  std::unordered_set<std::string> get_allergies();
  bool is_allergic_to(std::string);
};
} // namespace allergies

#endif // ALLERGIES_H
