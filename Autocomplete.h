#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <string>
#include <vector>

#include "TrieNode.h"

class Autocomplete {
 public:
  Autocomplete();
  ~Autocomplete();
  std::vector<std::string> getSuggestions(std::string partialWord);
  void insert(std::string word);

 private:
  TrieNode* root;
  void getSuggestionsHelper(TrieNode* node, std::string partialWord,
                            std::vector<std::string>& suggestions);
};

#endif  // AUTOCOMPLETE_H
