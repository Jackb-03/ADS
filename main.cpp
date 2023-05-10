#include <iostream>

#include "Autocomplete.h"
#include "PrefixMatcher.h"

int main() {
  Autocomplete autocomplete;
  autocomplete.insert("bin");
  autocomplete.insert("ball");
  autocomplete.insert("ballet");

  std::vector<std::string> suggestions = autocomplete.getSuggestions("b");
  for (const std::string& word : suggestions) {
    std::cout << word << std::endl;
  }
  std::cout << std::endl;

  PrefixMatcher prefixMatcher;
  prefixMatcher.insert("110011011101", 1);
  prefixMatcher.insert("110011011", 2);
  prefixMatcher.insert("11001101", 3);

  std::string destinationAddress = "11001101110";
  int router = prefixMatcher.selectRouter(destinationAddress);
  std::cout << "The longest matching router for address " << destinationAddress
            << " is Router " << router << std::endl;

  return 0;
}
