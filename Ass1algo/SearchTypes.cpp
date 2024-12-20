#include <iostream>
#include <deque>
#include "SearchTypes.h"
SearchTypes :: SearchTypes(deque<int>& list){
    List=list;
    ListSize=list.size();
}
void SearchTypes:: SequentialSearch(int item){
    if (List.empty())
        throw out_of_range("List is Empty\n");
    for (int i=0 ; i<List.size() ; ++i){
        if (List[i] == item){
            cout<<"The item in index number: "<<i<<" (The List is Zero based.\n)";
            return;
        }
    }
    cout<<"The Item is not find in my data.\n";
}
void SearchTypes ::  BinarySearch(int target){
    long long  left=-1;
    long long  right=List.size()+1;
    while (right>left+1){
        long long  mid=(left+right)/2;
        if(List [mid]==target){
            cout<<" The index of element "<<target<<" = "<<mid<<"\n";
            return;
        }
        else if(List[mid]>target){
            right=mid;
        }
        else{
            left=mid;
        }
    }
    cout << "Element " << target << " not found in the list";
}
int SearchTypes :: RecursiveSequentialSearch(int index, int target) {
    if (index == ListSize ) {
        return -1;
    }
    if (List[index] == target) {
        return index;
    }
    return RecursiveSequentialSearch( index+1, target);
}
int SearchTypes :: RecursiveBinarySearch(int left,int right,int target){
    if(left >= right){
        return -1;
    }
    int mid=(left+right)/2;
    if(List[mid] == target){
        return mid;
    }
    else if(List[mid] < target){
        return RecursiveBinarySearch(mid+1,right,target);
    }
    else{
        return RecursiveBinarySearch(left,mid-1,target);
    }
}