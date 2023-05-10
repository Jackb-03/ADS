#include <iostream>
#include <string>
#include <vector>

#include "Autocomplete.h"

int main() {
  Autocomplete autocomplete;
  autocomplete.insert("bin");
  autocomplete.insert("ball");
  autocomplete.insert("ballet");

  std::vector<std::string> suggestions;

  suggestions = autocomplete.getSuggestions("b");
  for (const auto &s : suggestions) {
    std::cout << s << " ";
  }
  std::cout << std::endl;

  suggestions = autocomplete.getSuggestions("ba");
  for (const auto &s : suggestions) {
    std::cout << s << " ";
  }
  std::cout << std::endl;

  suggestions = autocomplete.getSuggestions("bal");
  for (const auto &s : suggestions) {
    std::cout << s << " ";
  }
  std::cout << std::endl;

  suggestions = autocomplete.getSuggestions("balle");
  for (const auto &s : suggestions) {
    std::cout << s << " ";
  }
  std::cout << std::endl;

  return 0;
}
