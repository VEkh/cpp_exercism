#include "acronym.h"
#include <regex>
#include <string>

namespace acronym {

std::string acronym(std::string phrase) {
  std::string result = "";
  std::string suffix = phrase;
  std::smatch match;
  const std::regex regexp("(\\b\\w)\\w+");

  while (std::regex_search(suffix, match, regexp)) {
    result += toupper(match.str()[0]);
    suffix = match.suffix();
  }

  return result;
}
} // namespace acronym
