#include "Truckloads.h"

#include <iostream>
#include <string>
using namespace std;

Truckloads::Truckloads(/* args */) {}

Truckloads::~Truckloads() {}

int Truckloads::numTrucks(int numCrates, int loadSize) {
  // use recursion
  // if curloadsize>loadsize numTrucks until curloadsize<=loadsize

  if (numCrates <= loadSize) {
    return 1;
  }
  return numTrucks((numCrates / 2), loadSize) +
         numTrucks(numCrates - (numCrates / 2), loadSize);
};
