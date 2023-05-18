#ifndef HEAP_H
#define HEAP_H

#include <cmath>  // for floor()
#include <iostream>
#include <vector>

template <typename T>
class Heap {
 private:
  std::vector<T> values;
  void heapify(int);

 public:
  Heap();  // constructs an empty heap

  // constructs a heap with the values from the given vector
  // the type T MUST provide comparison operators <, >, ==
  Heap(std::vector<T>);

  void insert(T);
  void remove(T);
  T getMin();
};

/*******************************/
// default constructor
/*******************************/

template <typename T>
Heap<T>::Heap() {}

/*******************************/
// constructs a heap with the values in the given vector
// the type T MUST provide comparison operators <, >, ==
/*******************************/

template <typename T>
Heap<T>::Heap(std::vector<T> start_values) {
  // copy the values into our heap vector
  for (int i = 0; i < start_values.size(); i++) {
    values.push_back(start_values.at(i));
  }

  // starting from last non-leaf node (last parent), heapify each
  // of the parents
  int initial_parent_index = floor((values.size() - 1) / 2);
  for (int parent_index = initial_parent_index; parent_index >= 0;
       parent_index--) {
    heapify(parent_index);
  }
}

/*******************************/
// add values to the heap
/*******************************/

template <typename T>
void Heap<T>::insert(T value) {
  // Add the value at the end of the heap
  values.push_back(value);

  // The index of the inserted value
  int index = values.size() - 1;

  // Sift up to maintain heap property
  while (index > 0) {
    int parent_index = (index - 1) / 2;
    if (values[parent_index] > values[index]) {
      // Swap parent and child
      std::swap(values[parent_index], values[index]);
      index = parent_index;
    } else {
      break;
    }
  }
}

/*******************************/
/* delete values from the heap */
/*******************************/

template <typename T>
void Heap<T>::remove(T value) {
  // Find the value to be removed
  auto it = std::find(values.begin(), values.end(), value);
  if (it == values.end()) {
    // The value is not in the heap
    throw std::runtime_error("Value not found in the heap");
  }

  // Index of the value to be removed
  int index = it - values.begin();

  // Swap the value with the last element in the heap and remove it
  std::swap(values[index], values.back());
  values.pop_back();

  // Sift down the swapped value to maintain the heap property
  int parent_index = index;
  while (true) {
    int left_child_index = 2 * parent_index + 1;
    int right_child_index = 2 * parent_index + 2;
    int smallest = parent_index;

    if (left_child_index < values.size() &&
        values[left_child_index] < values[smallest]) {
      smallest = left_child_index;
    }

    if (right_child_index < values.size() &&
        values[right_child_index] < values[smallest]) {
      smallest = right_child_index;
    }

    if (smallest != parent_index) {
      // Swap parent and the smallest child
      std::swap(values[parent_index], values[smallest]);
      parent_index = smallest;
    } else {
      break;
    }
  }
}

/*******************************/
// find the smallest value in the heap
/*******************************/

template <typename T>
T Heap<T>::getMin() {
  if (values.empty()) {
    throw std::runtime_error("Heap is empty");
  }
  // The root of the tree (first element of the vector) is always the minimum in
  // a min heap
  return values[0];
}

/*******************************/
// private function to heapify a given 'node'
/*******************************/

template <typename T>
void Heap<T>::heapify(int parent_index) {
  // if we're outside the index range, return
  if (parent_index < 0 || parent_index >= values.size()) return;

  // find children indexes
  int left_child_index = parent_index * 2 + 1;
  int right_child_index = parent_index * 2 + 2;

  // if parent is larger than child, swap with smallest child
  int index_of_smallest = parent_index;

  // check if left child exists and if exists, is smallest value there
  if (left_child_index < values.size() &&
      values.at(left_child_index) < values.at(index_of_smallest)) {
    // make this index the current smallest
    index_of_smallest = left_child_index;
  }

  // check if left child exists and if exists, is smallest value there
  if (right_child_index < values.size() &&
      values.at(right_child_index) < values.at(index_of_smallest)) {
    // make this index the current smallest
    index_of_smallest = right_child_index;
  }

  // if parent is not smallest, swap with smallest child
  if (index_of_smallest != parent_index) {
    T temp = values.at(parent_index);
    values.at(parent_index) = values.at(index_of_smallest);
    values.at(index_of_smallest) = temp;

    // heapify the swapped index - it may need to move
    // further down the 'tree'
    heapify(index_of_smallest);
  }
}

#endif