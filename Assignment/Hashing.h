#include <bits/stdc++.h>
#include <iostream>

#ifndef ASSIGNMENT_HASHING_H
#define ASSIGNMENT_HASHING_H


class Hashing {
public:
    ///Hashing Techniques
    int midSquareHash(int key,int size);
    int DivisionHash(int key,int size);
    int FoldingHash_Shifting(int partSize,int key,int size);
    int Multiplication (int key,int size);
    int foldMethod_boundary(int key,int space);

};


#endif //ASSIGNMENT_HASHING_H
