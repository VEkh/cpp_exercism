#include <iostream>
#include <regex>
#include <string>

int main() {
  std::regex codon_regex("\\w{3}");
  std::string str = "foob";
  std::smatch match;
  std::regex_search(str, match, codon_regex);

  std::cout << "match: " << match.str() << std::endl;
  std::cout << "suffix: " << match.prefix() << std::endl;
}
