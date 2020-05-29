#include "two_fer.h"

#include <sstream>
#include <string>

namespace two_fer {
std::string two_fer() { return "One for you, one for me."; }

std::string two_fer(std::string name) {
  std::stringstream output;

  output << "One for " << name << ", one for me.";

  return output.str();
}
} // namespace two_fer
