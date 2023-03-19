#include "Reverser.h"

#include <iostream>
#include <string>
using namespace std;

Reverser::Reverser(/* args */) {}

Reverser::~Reverser() {}

int Reverser::reverseDigit(int value) {
  string str = to_string(value);
  string strRev = this->reverseString(str);
  return (stoi(strRev));
};

string Reverser::reverseString(string characters) {
  if (characters.length() <= 1) {
    return characters;  // since empty or 1 character in a char array cannot be
                        // reversed
  }

  return reverseString(characters.substr(1)) +
         characters[0];  // create a new string with all characters other then
                         // the first
  // using the first char of the character string append it to the end given the
  // returned value
};
