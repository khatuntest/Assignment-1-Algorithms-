#include <iostream>
#include <vector>
#include <climits>
#include "Priority_queue.h"

using namespace std;

Priority_queue::Priority_queue() {
    heapsize = 0;
}

void Priority_queue::heapify(vector<int> &heap, int index, int heapsize) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < heapsize && heap[left] > heap[largest]) {
        largest = left;
    }
    if (right < heapsize && heap[right] > heap[largest]) {
        largest = right;
    }

    if (largest != index) {
        swap(heap[index], heap[largest]);
        heapify(heap, largest, heapsize);
    }
}

int Priority_queue::heap_maxmium() {
    if (heapsize == 0) {
        cout << "Heap is empty!" << endl;
        return INT_MIN; // Handle empty heap case
    }
    return heap[0];
}

void Priority_queue::increase_key(int index, int key) {
    if (key < heap[index]) {
        cout << "New key is smaller than current key!" << endl;
        return;
    }
    heap[index] = key;
    while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
        swap(heap[(index - 1) / 2], heap[index]);
        index = (index - 1) / 2;
    }
}

void Priority_queue::insert(int key) {
    heap.push_back(INT_MIN); // Add a new element at the end
    heapsize++;
    increase_key(heapsize - 1, key); // Update its key
}

int Priority_queue::heap_extract() {
    if (heapsize == 0) {
        cout << "Heap is empty!" << endl;
        return INT_MIN; // Handle empty heap case
    }
    int max = heap[0];
    heap[0] = heap[heapsize - 1];
    heapsize--;
    heap.pop_back();
    heapify(heap, 0, heapsize);
    return max;
}


