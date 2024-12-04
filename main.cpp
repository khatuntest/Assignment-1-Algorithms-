#include <iostream>
#include "Btree.cpp"
using namespace std;

int main() {
    // Construct a BTree of order 3, which stores int data
    Btree<int,3> t1;
    t1.Insert (1);
    t1.Insert(5);
    t1.Insert(0);
    t1.Insert(4);
    t1.Insert(3);
    t1.Insert(2);
    t1.Print(); // Should output the following on the screen:
    /*
    1,4
    0
    2,3
    5
    */

    /*Btree <char,5> t; // Construct a BTree of order 5, which stores char data, Look at the example in our lecture:
    t.Insert('G');
    t.Insert('I');
    t.Insert('B');
    t.Insert('J');
    t.Insert('C');
    t.Insert('A');
    t.Insert('K');
    t.Insert('E');
    t.Insert('D');
    t.Insert('S');
    t.Insert('T');
    t.Insert('R');
    t.Insert('L');
    t.Insert('F');
    t.Insert('H');
    t.Insert('M');
    t.Insert('N');
    t.Insert('P');
    t.Insert('Q');
    t.Print(); // Should output the following on the screen:
    /*
    K
    C,G
    A,B
    D,E,F
    H,I,J
    N,R
    L,M
    P,Q
    S,T
    */
    return 0;
}
