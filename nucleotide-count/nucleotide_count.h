#if !defined(NUCLEOTIDE_COUNT_H)
#define NUCLEOTIDE_COUNT_H

#include <map>
#include <regex>
#include <string>

namespace nucleotide_count {
class counter {
private:
  std::string nucleotides;
  std::map<char, int> tally;

public:
  static std::regex NUCLEOTIDE_REGEX;

  counter(std::string value);
  int count(char) const;
  std::map<char, int> nucleotide_counts() const;
};
} // namespace nucleotide_count

#endif // NUCLEOTIDE_COUNT_H
