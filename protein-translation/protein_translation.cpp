#include "protein_translation.h"
#include <map>
#include <regex>
#include <string>
#include <vector>

namespace protein_translation {

const std::regex CODON_REGEX("\\w{3}");

std::map<std::vector<std::string>, std::string> GROUPED_PROTEINS = {
    {{"AUG"}, "Methionine"},      {{"UUU", "UUC"}, "Phenylalanine"},
    {{"UUA", "UUG"}, "Leucine"},  {{"UCU", "UCC", "UCA", "UCG"}, "Serine"},
    {{"UAU", "UAC"}, "Tyrosine"}, {{"UGU", "UGC"}, "Cysteine"},
    {{"UGG"}, "Tryptophan"},      {{"UAA", "UAG", "UGA"}, "STOP"},
};

std::map<std::string, std::string> protein_dictionary;

void build_protein_dictionary() {
  std::map<std::vector<std::string>, std::string>::iterator
      grouped_proteins_it = GROUPED_PROTEINS.begin();

  while (grouped_proteins_it != GROUPED_PROTEINS.end()) {
    std::vector<std::string> nucleotides = grouped_proteins_it->first;
    std::string protein = grouped_proteins_it->second;

    for (std::string nucleotide : nucleotides) {
      protein_dictionary[nucleotide] = protein;
    }

    grouped_proteins_it++;
  }
}

std::vector<std::string> proteins(std::string sequence) {
  build_protein_dictionary();

  std::smatch sm;
  std::string sequence_remainder = sequence;
  std::vector<std::string> proteins;

  while (sequence_remainder != "") {
    std::regex_search(sequence_remainder, sm, CODON_REGEX);

    std::string codon = sm.str();
    std::string protein = protein_dictionary[codon];

    if (protein == "STOP") {
      return proteins;
    }

    proteins.push_back(protein);
    sequence_remainder = sm.suffix();
  }

  return proteins;
}

} // namespace protein_translation
