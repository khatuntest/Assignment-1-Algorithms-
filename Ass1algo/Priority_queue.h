#include<iostream>
#include<vector>
using namespace std;
#ifndef NEW_PRIORITY_QUEUE_H
#define NEW_PRIORITY_QUEUE_H
class Priority_queue{
    vector<int>heap;
    int heapsize;
public:
    Priority_queue();

    void heapify(vector<int>&heap,int index,int heapsize);
    /*void build_heap(vector<int>&heap,int index,int heapsize);*/
    int heap_maxmium();
    void insert(int key);
    void increase_key(int index,int key);
    int heap_extract();
    void print();


};

#endif //NEW_PRIORITY_QUEUE_H
