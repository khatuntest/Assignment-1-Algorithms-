#include <iostream>
using namespace std;
#include <map>
#include "Hashing.h"

//int hashmethod(int key,int size){
//    return key%size;
//}
struct node{
    int value;
    node*forward;
    node(int val){
        value=val;
        forward=NULL;
    }
};

class linkedlist{
    node*header;
    int size;
public:
    linkedlist(){
        header=NULL;
        size=0;
    }
    int get_size(){
        return size;
    }

    void insert(int val){
        node*temp=header;
        node * newnode=new node(val);
        newnode->forward=temp;
        header=newnode;
        size++;
    }

    void Delete (int value){
        if(!header){
            cout<<"it is empty "<<endl;
            return;
        }else {
            node *temp = header;
            node *prev_temp = NULL;
            while (temp && temp->value != value) {
                prev_temp = temp;
                temp = temp->forward;
            }
            if(!temp){
                cout<<"not exist"<<endl;
                return;
            }else {
                if (prev_temp == NULL) {
                    header = temp->forward;
                } else {
                    prev_temp->forward = temp->forward;
                }
            }

            delete temp;
            size--;
            cout << "Value " << value << " deleted successfully.\n";
        }


    }
    void display() {
        node* temp = header;
        while (temp) {
            cout << temp->value << " -> ";
            temp = temp->forward;
        }
        cout << "NULL\n";
    }

};

class chain{
    map<int,linkedlist>hash;
    Hashing h1;
public:
    void insert(int key,int size){
        int hashpos = h1.Multiplication(key,size);
        hash[hashpos].insert(key);
    }
    void Delete(int key, int size) {
        int hashpos =  h1.Multiplication(key,size);
        hash[hashpos].Delete(key);
    }
    void display(int size) {
        for (int i = 0; i < size; i++) {
            cout << "Bucket " << i << ": ";
            hash[i].display();
        }
    }
};
int main() {
    int tableSize = 5; // Size of the hash table
    chain hashTable;

    // Insert values into the hash table
    hashTable.insert(10, tableSize);
    hashTable.insert(15, tableSize);
    hashTable.insert(20, tableSize);
    hashTable.insert(25, tableSize);
    hashTable.insert(30, tableSize);
    hashTable.insert(11, tableSize);

    cout << "Hash Table after insertion:" << endl;
    hashTable.display(tableSize);

    // Delete some values
    cout << "\nDeleting value 15:" << endl;
    hashTable.Delete(15, tableSize);

    cout << "\nDeleting value 11:" << endl;
    hashTable.Delete(11, tableSize);

    cout << "\nHash Table after deletion:" << endl;
    hashTable.display(tableSize);

    // Try deleting a value not in the table
    cout << "\nDeleting value 100 (not in table):" << endl;
    hashTable.Delete(100, tableSize);

    // Final display of hash table
    cout << "\nFinal Hash Table:" << endl;
    hashTable.display(tableSize);

    return 0;
}