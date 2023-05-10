#ifndef TRIENODE_H
#define TRIENODE_H

#include <string>
#include <unordered_map>
#include <vector>

class TrieNode {
 public:
  TrieNode();
  ~TrieNode();
  bool isEndOfWord;
  std::unordered_map<char, TrieNode*> children;
  int routerNumber;
};

#endif  // TRIENODE_H
