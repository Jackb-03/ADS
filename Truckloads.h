#ifndef Truckloads_h
#define Truckloads_h
#include <iostream>
#include <string>

class Truckloads {
 private:
 public:
  int trucks = 0;

  Truckloads(/* args */);
  ~Truckloads();
  int numTrucks(int numCrates, int loadSize);
};

#endif