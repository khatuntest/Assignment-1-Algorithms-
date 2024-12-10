#include <iostream>

#include "SkipList.h"
int main() {
    srand(static_cast<unsigned>(time(0)));
    SkipList skipList;
    skipList.insert(3);
    skipList.insert(6);
    skipList.insert(13);
    skipList.insert(9);
    skipList.insert(12);
    skipList.insert(18);

    skipList.print();
    return 0;
}
