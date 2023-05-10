#include "PrefixMatcher.h"

PrefixMatcher::PrefixMatcher() { root = new TrieNode(); }

PrefixMatcher::~PrefixMatcher() { delete root; }

void PrefixMatcher::insert(std::string address, int routerNumber) {
  TrieNode* current = root;
  for (char c : address) {
    if (current->children.find(c) == current->children.end()) {
      current->children[c] = new TrieNode();
    }
    current = current->children[c];
  }
  current->routerNumber = routerNumber;
}

int PrefixMatcher::selectRouter(std::string networkAddress) {
  TrieNode* current = root;
  int longestMatchingRouter = -1;

  for (char c : networkAddress) {
    if (current->children.find(c) == current->children.end()) {
      break;
    }
    current = current->children[c];
    if (current->routerNumber != -1) {
      longestMatchingRouter = current->routerNumber;
    }
  }

  return longestMatchingRouter;
}
