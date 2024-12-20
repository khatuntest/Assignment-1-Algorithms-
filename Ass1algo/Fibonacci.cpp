#include "Fibonacci.h"
#include <vector>
#include <iostream>
using namespace std;

void Fibonacci::matrixMultiplication(int mat1[2][2], int mat2[2][2]) {
    int a = mat1[0][0] * mat2[0][0] + mat1[0][1] * mat2[1][0];
    int b = mat1[0][0] * mat2[0][1] + mat1[0][1] * mat2[1][1];
    int c = mat1[1][0] * mat2[0][0] + mat1[1][1] * mat2[1][0];
    int d = mat1[1][0] * mat2[0][1] + mat1[1][1] * mat2[1][1];
    mat1[0][0] = a;
    mat1[0][1] = b;
    mat1[1][0] = c;
    mat1[1][1] = d;
}

void Fibonacci::matrixPower(int mat[2][2], int n) {
    if (n == 0 || n == 1) return;
    int original[2][2] = {{1, 1}, {1, 0}};
    matrixPower(mat, n / 2);
    matrixMultiplication(mat, mat);
    if (n % 2) {
        matrixMultiplication(mat, original);
    }
}

int Fibonacci::fibMatrix(int n) {
    if (n == 0) return 0;
    int mat[2][2] = {{1, 1}, {1, 0}};
    matrixPower(mat, n - 1);
    return mat[0][0];
}

int Fibonacci::fibRecursive(int n) {
    if (n == 0 || n == 1) return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

int Fibonacci::fibDP(int n) {
    dp[0] = 0;
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    if (dp[n] != -1) return dp[n];
    dp[n] = fibDP(n - 1) + fibDP(n - 2);
    return dp[n];
}
