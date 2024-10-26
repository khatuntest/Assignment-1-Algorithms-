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
     heap h2;
    deque<int> arr = {12, 11, 13, 5, 6, 7};

    h2.BuildMaxHeap(arr);
    cout << "Max heap:";
    h2.print();

    h2.HeapSort();
    cout << "Sorted heap: ";
    h2.print();
    return 0;
}
