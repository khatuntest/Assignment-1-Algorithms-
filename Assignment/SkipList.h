#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int MAX_LEVEL = 10;
const float PROBABILITY = 0.5;

#ifndef ASSIGNMENT_SKIPLIST_H
#define ASSIGNMENT_SKIPLIST_H


struct Node{
    int key;
    Node**forward; //Array of pointer to point in next node in diff levels
    Node(int key,int levels){
        this->key=key;
        forward=new Node*[levels+1];
        for (int i = 0; i <= levels; ++i) {
            forward[i]= nullptr;

        }
    }
    ~Node(){
        delete[] forward;
    }

};

class SkipList {
private:
    int  maxLevel;
    int currentLevel;
    int randomLevel();
public:
    SkipList();
    ~SkipList();
    void insert(int key);
    void print();
    void Delete(int value);
    bool Search(int value);
    Node*header;
};

#endif //ASSIGNMENT_SKIPLIST_H
