#include "Hashing.h"
using namespace std;

int Hashing::midSquareHash(int key,int size) {
    long long square = key*key;
    string sqStr= to_string(square);
    int midStart=(sqStr.size())/2-1;
    string ans=sqStr.substr(midStart , 2);
    int hash=stoi(ans);
    return hash%size;
}

int Hashing::DivisionHash(int key,int size) {
    int value=key%size;
    return value;
}

int Hashing::FoldingHash_Shifting(int partSize,int key,int size) {
    string keyStr= to_string(key);
    int totalValue=0;
    for (int i = 0; i < keyStr.size(); ++i) {
        string miniPart=keyStr.substr(i,partSize);
        int partValue= stoi(miniPart);
        totalValue+=partValue;
    }
    int res=totalValue%size;
    return res ;
}

int Hashing::Multiplication(int key, int size) {
    float A=0.618033;
    float product= key*A;
    float fracation=product- floor(product);
    int position= floor(size*(fracation));
    return position;
}

int Hashing::foldMethod_boundary(int key, int space) {
    string strkey= to_string(key);
    int size=ceil((strkey.size()/space));
    string arr[size];
    for(int i=0,j=0;i<size;i+=space,j++){
        arr[j]=strkey.substr(i,min(space, (int)strkey.size() - i));
    }
    reverse(arr[0].begin(), arr[0].end());
    reverse(arr[size - 1].begin(), arr[size - 1].end());

    int pos=0;
    for(int i=0;i<size;i++){
        pos+= stoi(arr[i]);
    }
    return pos%100;
}
