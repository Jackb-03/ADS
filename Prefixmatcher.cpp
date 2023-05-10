#include "PrefixMatcher.h"
Trie::Trie() { root = new TrieNode(); }

void Trie::insert(const std::string &address, int routerNumber) {
  TrieNode *current = root;
  for (char c : address) {
    if (current->children.find(c) == current->children.end()) {
      current->children[c] = new TrieNode();
    }
    current = current->children[c];
  }
  current->routerNumber = routerNumber;
}

int Trie::selectRouter(const std::string &networkAddress) const {
  TrieNode *current = root;
  int routerNumber = -1;
  for (char c : networkAddress) {
    if (current->children.find(c) == current->children.end()) {
      break;
    }
    current = current->children[c];
    if (current->routerNumber != -1) {
      routerNumber = current->routerNumber;
    }
  }
  return routerNumber;
}

void PrefixMatcher::insert(const std::string &address, int routerNumber) {
  trie.insert(address, routerNumber);
}

int PrefixMatcher::selectRouter(const std::string &networkAddress) const {
  return trie.selectRouter(networkAddress);
}
