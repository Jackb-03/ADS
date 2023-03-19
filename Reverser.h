#ifndef Reverser_h
#define Reverser_h
#include <iostream>
#include <string>

class Reverser {
 private:
 public:
  Reverser(/* args */);
  ~Reverser();
  int reverseDigit(int value);
  std::string reverseString(std::string characters);
};

#endif