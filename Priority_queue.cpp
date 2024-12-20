//
// Created by Ts on 25/10/2024.
//
#include <iostream>
using namespace std;
#include<vector>
#include"Priority_queue.h"


Priority_queue::Priority_queue() {
    heapsize=0;
}

void Priority_queue::heapify(vector<int> &heap, int index, int heapsize) {
    int left=index*2;
    int right=index*2+1;
    int largest=INT_MIN;
    if(left<heapsize && heap[index]>heap[left]){
        largest=index;
    }else{
        largest=left;
    }
    if(right<heapsize && heap[largest]>heap[right]){
        largest=heap[right];
    }

    if(largest!=index){
        swap(heap[index],heap[largest]);
        heapify(heap,largest,heapsize);
    }
}

/*void Priority_queue::build_heap(vector<int> &heap, int index, int heapsize) {
    for(int i=heapsize/2;i<1;i--){
        heapify(heap,i,heapsize);
    }
}*/

int Priority_queue::heap_maxmium() {
    return heap[0];
}
void Priority_queue::increase_key(int index, int key) {
    heap[index]=key;
    int i=index;
    while(i!=1 && heap[i/2]<heap[i]){
        heap[i]=heap[i/2];
        i=i/2;
    }
}

void Priority_queue::insert(int key) {
    heapsize++;
    heap[heapsize-1]=INT_MIN;
    increase_key(heapsize-1,key);
}

int Priority_queue::heap_extract() {
    int max=heap[0];
    heap[0]=heap[heapsize-1];

    heapify(heap,0,heapsize-1);
}


