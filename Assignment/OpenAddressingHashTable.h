#include <bits/stdc++.h>
#include <iostream>
#include "Hashing.h"
using namespace std;

#ifndef ASSIGNMENT_OPENADDRESSINGHASHTABLE_H
#define ASSIGNMENT_OPENADDRESSINGHASHTABLE_H


class OpenAddressingHashTable {
private:
    Hashing hashFunction;
    vector<int>table;
    int count=0;
    int size;
    int Empty=-1;
    int Deleted=-2;
    string  method;
public:
    OpenAddressingHashTable(int size,string method);
    int LinerProbing(int key,int i);
    int quadraticProbing(int key,int i);
    int doubleHashing(int key,int i);
    double loadFactor();
    void rehash();
    void insert(int key);
    void Delete(int key);
    void search(int key);
    void Display();


};


#endif //ASSIGNMENT_OPENADDRESSINGHASHTABLE_H
