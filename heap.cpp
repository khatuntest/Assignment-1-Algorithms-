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

void heap::MaxHeapify(int *arr, int size, int index) {
    int largest=index;
    int left=(2*index)+1;
    int right=(2*index)+2;
    if(left<size&&arr[left]>arr[largest]){
        largest=left;
    }
    if(right<size&&arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=index){
        swap(arr[largest],arr[index]);
        MaxHeapify(arr,size,largest);
    }

}

void heap::BuildMaxHeap(int *arr, int size) {
int node=(size/2)-1;
    for (int i = node; i >=0 ; --i) {
        MaxHeapify(arr,size,i);
    }
}

void heap::print(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout<<arr[i]<<" ";
    }
}

void heap::HeapSort(int *arr, int size) {
    BuildMaxHeap(arr,size);
    for (int i = size-1; i >=1 ; i--) {
        swap(arr[0],arr[i]);
       int k=(size-=1);
        MaxHeapify(arr,k,0);
    }
}
