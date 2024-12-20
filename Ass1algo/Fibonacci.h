#ifndef UNTITLED33_FIBONACCI_H
#define UNTITLED33_FIBONACCI_H

#include <vector>
using namespace std;


class Fibonacci {
public:
    vector<int> dp;
    Fibonacci() : dp(1e5 + 5, -1) {}
    int fibMatrix(int n);
    int fibRecursive(int n);
    int fibDP(int n);

private:
    void matrixMultiplication(int mat1[2][2], int mat2[2][2]);
    void matrixPower(int mat[2][2], int n);

};

#endif
