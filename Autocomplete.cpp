#include "Autocomplete.h"

Autocomplete::Autocomplete() { root = new TrieNode(); }

Autocomplete::~Autocomplete() { delete root; }

void Autocomplete::insert(std::string word) {
  TrieNode* current = root;
  for (char c : word) {
    if (current->children.find(c) == current->children.end()) {
      current->children[c] = new TrieNode();
    }
    current = current->children[c];
  }
  current->isEndOfWord = true;
}

std::vector<std::string> Autocomplete::getSuggestions(std::string partialWord) {
  std::vector<std::string> suggestions;
  TrieNode* current = root;

  for (char c : partialWord) {
    if (current->children.find(c) == current->children.end()) {
      return suggestions;
    }
    current = current->children[c];
  }

  getSuggestionsHelper(current, partialWord, suggestions);
  return suggestions;
}

void Autocomplete::getSuggestionsHelper(TrieNode* node, std::string partialWord,
                                        std::vector<std::string>& suggestions) {
  if (node->isEndOfWord) {
    suggestions.push_back(partialWord);
  }

  for (auto& child : node->children) {
    getSuggestionsHelper(child.second, partialWord + child.first, suggestions);
  }
}
