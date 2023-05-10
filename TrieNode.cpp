#include "TrieNode.h"

TrieNode::TrieNode() {
  isEndOfWord = false;
  routerNumber = -1;
}

TrieNode::~TrieNode() {
  for (auto& child : children) {
    delete child.second;
  }
}
