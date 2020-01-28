#include "nucleotide_count.h"

#include <map>
#include <regex>
#include <stdexcept>
#include <string>

namespace nucleotide_count {
std::regex counter::NUCLEOTIDE_REGEX =
    std::regex(".*[^acgt].*", std::regex_constants::icase);

counter::counter(std::string value) {
  bool is_invalid_sequence = std::regex_match(value, NUCLEOTIDE_REGEX);

  if (is_invalid_sequence) {

    throw std::invalid_argument(
        "Nucleotides must only be composed of As, Gs, Cs, and Ts");
  } else {
    nucleotides = value;
  }
}

int counter::count(char key) const {
  bool is_invalid_key = std::regex_match(std::string(1, key), NUCLEOTIDE_REGEX);

  if (is_invalid_key) {
    throw std::invalid_argument(
        "Nucleotides must only be composed of As, Gs, Cs, and Ts");
  }

  std::map<char, int> tally = nucleotide_counts();
  return tally[key];
}

std::map<char, int> counter::nucleotide_counts() const {
  std::map<char, int> tally = {{'A', 0}, {'T', 0}, {'C', 0}, {'G', 0}};

  for (size_t i = 0; i < nucleotides.size(); ++i) {
    char nucleotide = std::toupper(nucleotides[i]);
    tally[nucleotide] = tally[nucleotide] + 1;
  }

  return tally;
}
} // namespace nucleotide_count
