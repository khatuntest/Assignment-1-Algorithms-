#include <iostream>
#include "heap.h"
using namespace std;
int heap:: parent(int i) {
    return (i - 1) / 2;
}
int heap :: leftChild(int i) {
    return 2 * i + 1;
}
int heap :: rightChild(int i) {
    return 2 * i + 2;
}
void heap:: heapifyDown(int i){// important in deletion
    int large =i,
    left= leftChild(i),
    right = rightChild(i);
    if (left < heapSize && heapList[left] > heapList[i])
        large = left;
    if (right  < heapSize && heapList[right] > heapList[i])
        large = right ;
    if (large != i){
        swap(heapList[large] , heapList[i]);
        heapifyDown(large);
    }
}
void heap ::  heapifyUp(int i){
    while (i != 0 && heapList[parent(i)] < heapList[i]){
        swap(heapList[parent(i)] , heapList[i]);
        i= parent(i);
    }
}
void heap ::  insert(int element){
    heapList.push_back(element);
    heapSize++;
    heapifyUp(heapSize-1);
}

int heap :: getMax() const{
    if (heapSize == 0)
        throw out_of_range("Heap is Empty");
    return heapList[0];
}
int heap :: getMin() const{
    if (heapSize == 0)
        throw out_of_range("Heap is Empty");
    int minItem=heapList[heapSize/2];
    for (int i= heapSize/2 ; i<heapSize ; ++i){
        if (heapList[i] < minItem)
            minItem = heapList[i];
    }
    return minItem;
}
bool heap :: isEmpty() const {
    return (heapSize == 0);
}
int heap :: size() const{
    return heapSize;
}

void heap::MaxHeapify(int index) {
    int largest = index;
    int left = leftChild(index);
    int right = rightChild(index);

    if (left < heapSize && heapList[left] > heapList[largest]) {
        largest = left;
    }
    if (right < heapSize && heapList[right] > heapList[largest]) {
        largest = right;
    }
    if (largest != index) {
        swap(heapList[largest], heapList[index]);
        MaxHeapify(largest);
    }
}


void heap::BuildMaxHeap(const deque<int>& arr)  {
    heapList = arr;
    heapSize = arr.size();
    int node =(heapSize/2)-1;
    for (int i = node; i >=0 ; --i) {
        MaxHeapify(i);
    }
}

void heap::print() {
    for (int i = 0; i < heapSize; ++i) {
        cout<<heapList[i]<<" ";
    }
}

void heap::HeapSort() {
    BuildMaxHeap(heapList);
    int size=heapSize;
    for (int i = heapSize-1; i >=1 ; i--) {
        swap(heapList[0], heapList[i]);
       heapSize--;
        MaxHeapify(0);
    }
    heapSize=size;
}
