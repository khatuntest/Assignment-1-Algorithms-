#include <iostream>
#include <deque>
#include "heap.h"
using namespace std;

int main() {
    heap myHeap;
    deque<int> initialArray = {15, 10, 20, 17, 25, 30};
    myHeap.BuildMaxHeap(initialArray);
    std::cout << "Heap after building from array using BuildMaxHeap: ";
    myHeap.print();
    myHeap.insert(35);
    std::cout << "Heap after inserting 35: ";
    myHeap.print();
    std::cout << "Extracted max element: " << myHeap.extractMax() << std::endl;
    std::cout << "Heap after extracting max: ";
    myHeap.print();

    return 0;
}