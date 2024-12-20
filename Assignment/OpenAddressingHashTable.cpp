
#include "OpenAddressingHashTable.h"


OpenAddressingHashTable::OpenAddressingHashTable(int size,string method) {
    this->size=size;
    table.resize(size,Empty);
    this->method=method;
}
int OpenAddressingHashTable::LinerProbing(int key, int i) {
    int res= (hashFunction.DivisionHash(key,size)+i)% size;
    return res;
}

int OpenAddressingHashTable::quadraticProbing(int key, int i) {
    int res=((hashFunction.DivisionHash(key,size))+(i*i))% size;
    return res;
}

int OpenAddressingHashTable::doubleHashing(int key, int i) {
    int h1=hashFunction.DivisionHash(key,size);
    int h2=3-(key%3);
    int res=( h1+(i*h2))%size;
    return res;
}

void OpenAddressingHashTable::insert(int key) {
    if(loadFactor()>0.5){
        rehash();
    }
    for (int i = 0; i < size; ++i) {
        int index;
        if (method == "linear") {
            index = LinerProbing(key, i);
        } else if (method == "quadratic") {
            index = quadraticProbing(key, i);
        } else if (method == "double") {
            index = doubleHashing(key, i);
        } else {
            throw invalid_argument("Unknown probing method.");
        }
        if(table[index]==Empty||table[index]==Deleted){
            table[index]=key;
            count++;
            return;
        }

    }

}

double OpenAddressingHashTable::loadFactor() {
    double res=(static_cast<double>(count)/size);
    return res;
}

void OpenAddressingHashTable::rehash() {
    cout << "Rehashing triggered! Current size: " << size << ", Load factor: " << loadFactor() << endl;
    vector<int>oldTable=table;
    size*=2;
    count=0;
    table.clear();
    table.resize(size,Empty);
    for(int key:oldTable){
        if(key!=Empty&&key!=Deleted){
            insert(key);
        }
    }
    cout << "Rehashing completed! New size: " << size << endl;

}

void OpenAddressingHashTable::Delete(int key) {
    for (int i = 0; i < size; ++i) {
        int index;
        if (method == "linear") {
            index = LinerProbing(key, i);
        } else if (method == "quadratic") {
            index = quadraticProbing(key, i);
        } else if (method == "double") {
            index = doubleHashing(key, i);
        } else {
            throw invalid_argument("Unknown probing method.");
        }
        if(table[index]==Empty){
            cout << "Key not found: " << key << endl;
            return;
        }
        if(table[index]==key){
            table[index]=Deleted;
            count--;
            cout << "Key deleted: " << key << endl;
            return;
        }
    }
    cout << "Key not found: " << key << endl;
}

void OpenAddressingHashTable::search(int key) {
    for (int i = 0; i < size; ++i) {
        int index;
        if (method == "linear") {
            index = LinerProbing(key, i);
        } else if (method == "quadratic") {
            index = quadraticProbing(key, i);
        } else if (method == "double") {
            index = doubleHashing(key, i);
        } else {
            throw invalid_argument("Unknown probing method.");
        }
        if(table[index]==Empty){
            cout << "Key not found: " << key << endl;
            return;
        }
        if(table[index]==key){
            cout << "Key : "<<key<<" "<< "found in index : " << index << endl;
            return;
        }
    }
    cout << "Key not found: " << key << endl;
}

void OpenAddressingHashTable::Display() {
    for (int i = 0; i < size; ++i) {
        if (table[i] == Empty)
            cout << i << ": EMPTY" << endl;
        else if (table[i] == Deleted)
            cout << i << ": DELETED" << endl;
        else
            cout << i << ": " << table[i] << endl;
    }
};



