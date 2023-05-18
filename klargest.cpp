#include <queue>
#include <stdexcept>
#include <vector>

int kth_largest(std::vector<int> values, int k) {
  if (k <= 0 || k > values.size()) {
    throw std::invalid_argument("k is out of range");
  }

  // Create a min heap of size k
  std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap(
      values.begin(), values.begin() + k);

  // For remaining elements, if element > top of heap, pop heap and push element
  for (int i = k; i < values.size(); ++i) {
    if (values[i] > min_heap.top()) {
      min_heap.pop();
      min_heap.push(values[i]);
    }
  }

  // The root of the heap is the k-th largest element
  return min_heap.top();
}
