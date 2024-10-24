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
