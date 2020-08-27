#include "rna_transcription.h"
#include <map>
#include <string>

namespace rna_transcription {
std::map<char, char> dictionary = {
    {'a', 'u'}, {'c', 'g'}, {'g', 'c'}, {'t', 'a'}};

char to_rna(char nucleotide) {
  char transcribed_nucleotide = dictionary.at(tolower(nucleotide));
  return toupper(transcribed_nucleotide);
}

std::string to_rna(std::string dna) {
  std::string transcription = "";

  for (char nucleotide : dna) {
    transcription += std::string(1, to_rna(nucleotide));
  }

  return transcription;
}
} // namespace rna_transcription
