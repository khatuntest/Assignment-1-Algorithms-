#include <iostream>
#include <deque>
using namespace std;


#ifndef ADVANSED_DS_HEAP_H
#define ADVANSED_DS_HEAP_H


class heap {
private:
    deque<int>heapList;
    int heapSize;
public:
    heap() : heapSize(0) {}
    // Helper functions
    int parent(int i) ;// return the index of the parent node
    int leftChild(int i); // return the index of left node
    int rightChild(int i);// return the index of right node
    void heapifyDown(int i); // Heapify down to maintain the max-heap property
    void heapifyUp(int i);// Heapify up to maintain the max-heap property after insertion
    void insert(int element);// Insert a new element into the heap
    int extractMax();// Extract the maximum element (for max-heap)
    int extractMin();// Extract the minimum element (requires a separate method)
    int getMax() const; // Get the maximum element without extracting it
    int getMin() const;// Get the minimum element without extracting it
    bool isEmpty() const ;// Check if the heap is empty
    int size() const ;// Get the size of the heap
 void MaxHeapify(int index);
  void BuildMaxHeap(const deque<int>& arr) ;
  void print();
  void  HeapSort();

};


#endif //ADVANSED_DS_HEAP_H
