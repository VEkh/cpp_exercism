#include "raindrops.h"
#include <map>
#include <string>

namespace raindrops {
std::string convert(int number) {
  std::map<int, std::string> factors = {
      {3, "Pling"}, {5, "Plang"}, {7, "Plong"}};

  std::string result = "";

  std::map<int, std::string>::iterator it;
  for (it = factors.begin(); it != factors.end(); ++it) {
    if (number % it->first == 0) {
      result += it->second;
    }
  }

  return result.empty() ? std::to_string(number) : result;
}
} // namespace raindrops
