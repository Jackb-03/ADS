#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H

#include <iostream>
#include <string>
#include <unordered_map>

class TrieNode {
 public:
  std::unordered_map<char, TrieNode *> children;
  int routerNumber;
  TrieNode() : routerNumber(-1) {}
};

class Trie {
 public:
  Trie();
  void insert(const std::string &address, int routerNumber);
  int selectRouter(const std::string &networkAddress) const;

 private:
  TrieNode *root;
};

class PrefixMatcher {
 public:
  void insert(const std::string &address, int routerNumber);
  int selectRouter(const std::string &networkAddress) const;

 private:
  Trie trie;
};

#endif
