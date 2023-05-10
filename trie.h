// trie.h

#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class TrieNode {
 public:
  std::unordered_map<char, TrieNode *> children;
  bool isEndOfWord;
  TrieNode() : isEndOfWord(false) {}
};

class Trie {
 public:
  Trie();
  void insert(const std::string &word);
  std::vector<std::string> getSuggestions(const std::string &partialWord) const;

 private:
  TrieNode *root;
  void getSuggestionsHelper(TrieNode *node, std::string current,
                            const std::string &partialWord,
                            std::vector<std::string> &suggestions) const;
};

#endif  // TRIE_H
