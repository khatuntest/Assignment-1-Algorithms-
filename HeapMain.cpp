#include <iostream>
#include "heap.h"
using namespace std;

int main() {
    heap h;
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(30);
    h.insert(25);
    cout<<"Max element: "<<h.getMax()<<"\n";
    cout<<"Min element: "<<h.getMin()<<"\n";
    return 0;
}