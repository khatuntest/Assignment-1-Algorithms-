#include <iostream>
#include "Priority_queue.h"

using namespace std;

int main() {
    Priority_queue pq;

    pq.insert(15);
    pq.insert(10);
    pq.insert(30);
    pq.insert(40);
    pq.insert(5);


    cout << "Maximum element: " << pq.heap_maxmium() << endl;


    int maxElement = pq.heap_extract();
    cout << "Extracted maximum element: " << maxElement << endl;


    cout << "New maximum element: " << pq.heap_maxmium() << endl;


    pq.increase_key(2, 50);
    cout << "Maximum element after increasing key: " << pq.heap_maxmium() << endl;

    return 0;
}
