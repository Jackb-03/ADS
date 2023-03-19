#include "Truckloads.h"

#include <iostream>
#include <string>
using namespace std;

Truckloads::Truckloads(/* args */) {}

Truckloads::~Truckloads() {}

int Truckloads::numTrucks(int numCrates, int loadSize) {
  // use recursion
  // if curloadsize>loadsize numTrucks until curloadsize<=loadsize

  if (numCrates > loadSize) {
    if (numCrates % 2 == 0) {
      numTrucks(numCrates / 2, loadSize);
      numTrucks(numCrates / 2, loadSize);

    } else {
      numTrucks(numCrates / 2, loadSize);
      numTrucks(numCrates / 2 + 1, loadSize);
    }
  } else {
    this->trucks++;
    cout << this->trucks;
    return this->trucks;
  }

  return 0;
};
