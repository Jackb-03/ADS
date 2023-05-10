// autocomplete.h

#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <string>
#include <vector>

#include "trie.h"

class Autocomplete {
 public:
  void insert(const std::string &word);
  std::vector<std::string> getSuggestions(const std::string &partialWord) const;

 private:
  Trie trie;
};

#endif  // AUTOCOMPLETE_H
