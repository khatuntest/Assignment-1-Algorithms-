#include <iostream>
using namespace std;
int SIZE=100;

int Binary_search(int arr[],int size,int left,int right,int target){
    int mid=(left+right)/2;
    if(mid==size){
        return -1;
    }
    if(arr[mid]==target){
        return mid;
    }else{
        if(arr[mid]>target){
            return Binary_search(arr,size,mid+1,right,target);
        }else{
            return Binary_search(arr,size,left,mid-1,target);
        }
    }
}



int main(){
    int size,target;
    cin>>size>>target;
    int arr[SIZE];

    for(int i=0;i<size;i++){
        int num;cin>>num;
        arr[i]=num;
    }

    int res=Binary_search(arr,size,0,size,target);

    if(res==-1){
        cout<<"Not found"<<endl;
    }else {
        cout << "at index: " << res - 1 << endl;
    }

    return 0;
}


