#include <iostream>
#include "OpenAddressingHashTable.h"
using namespace std;

int main() {
    int size;
    string method;
    cout << "Enter the size of the hash table: ";
    cin >> size;
    cout << "Enter the probing method (linear/quadratic/double): ";
    cin >> method;
    OpenAddressingHashTable hashTable(size, method);
    cout << "Inserting keys..." << endl;
    // Insert keys
    hashTable.insert(7);
    hashTable.insert(36);
    hashTable.insert(18);
    hashTable.insert(62);
    hashTable.insert(51);
    cout << "Displaying the hash table:" << endl;
    hashTable.Display();
    cout << "Searching for keys..." << endl;
    hashTable.search(62); // Should find
    hashTable.search(60); // Should not find
    cout << "Deleting keys..." << endl;
    hashTable.Delete(62);
    cout << "Displaying the hash table after deletion:" << endl;
    hashTable.Display();
    // Insert more keys to trigger rehashing
    hashTable.insert(60);
    hashTable.insert(70);
    hashTable.insert(80);
    cout << "Displaying the hash table after rehashing:" << endl;
    hashTable.Display();

    return 0;
}
