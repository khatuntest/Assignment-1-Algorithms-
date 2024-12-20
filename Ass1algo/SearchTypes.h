#include <iostream>
#include <deque>
using namespace std;
#ifndef ADVANSED_DS_SEARCHTYPES_H
#define ADVANSED_DS_SEARCHTYPES_H

class SearchTypes {
private:
    deque<int>List;
    int ListSize;
public:
    SearchTypes(deque<int>& list);
    void SequentialSearch( int item);
    void BinarySearch(int target);
    int RecursiveSequentialSearch(int index, int target);
    int RecursiveBinarySearch(int left,int right,int target);
};


#endif //ADVANSED_DS_SEARCHTYPES_H
