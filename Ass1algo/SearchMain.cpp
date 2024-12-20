#include <iostream>
#include <deque>
#include "SearchTypes.h"
using namespace std;

int main() {
    deque<int> myList = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    SearchTypes searchObj(myList);
    int target = 30;
    cout << "Performing Sequential Search for: " << target << ":\n";
    searchObj.SequentialSearch(target);
    cout << "Performing Binary Search for: " << target << ":\n";
    searchObj.BinarySearch(target);
    int index = searchObj.RecursiveSequentialSearch(0, target);
    if (index != -1) {
        cout << "SequentialSearch found " << target << " at index: " << index << "\n";
    }
    else {
        cout << target << " not found in list using SequentialSearch.\n";
    }
    index = searchObj.RecursiveBinarySearch(0, myList.size()-1 , target);
    if (index != -1) {
        cout << "BinarySearch found " << target << " at index: " << index << "\n";
    }
    else {
        cout << target << " not found in list using BinarySearch.\n";
    }
    return 0;
}