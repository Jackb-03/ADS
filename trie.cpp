// trie.cpp

#include "trie.h"

Trie::Trie() {
    root = new TrieNode();
}

void Trie::insert(const std::string &word) {
    TrieNode* current = root;
    for (char c : word) {
        if (current->children.find(c) == current->children.end()) {
            current->children[c] = new TrieNode();
        }
        current = current->children[c];
    }
    current->isEndOfWord = true;
}

std::vector<std::string> Trie::getSuggestions(const std::string &partialWord) const {
    std::vector<std::string> suggestions;
    TrieNode* current = root;
    for (char c : partialWord) {
        if (current->children.find(c) == current->children.end()) {
            return suggestions;
        }
        current = current->children[c];
    }
    getSuggestionsHelper(current, partialWord, partialWord, suggestions);
    return suggestions;
}

void Trie::getSuggestionsHelper(TrieNode* node, std::string current, const std::string &partialWord, std::vector<std::string> &suggestions) const {
    if (node->isEndOfWord) {
        suggestions.push_back(current);
    }
    for (auto &child : node->children) {
        current.push_back(child.first);
        getSuggestionsHelper(child.second, current, partialWord, suggestions);
        current.pop_back();
    }
}
