#include <iostream>
#include <string>
#include <vector>

#include "Heap.cpp"

int main(int argc, char const *argv[]) {
  std::vector<int> heapData = {1, 2, 3, 9, 8, 5};
  Heap<int> testHeap(heapData);
  testHeap.insert(4);

  return 0;
}
