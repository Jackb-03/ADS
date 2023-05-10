// autocomplete.cpp

#include "autocomplete.h"

void Autocomplete::insert(const std::string &word) { trie.insert(word); }

std::vector<std::string> Autocomplete::getSuggestions(
    const std::string &partialWord) const {
  return trie.getSuggestions(partialWord);
}
