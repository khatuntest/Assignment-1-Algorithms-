

#include "SkipList.h"

SkipList::SkipList() {
    currentLevel = 0;
    maxLevel = MAX_LEVEL;
    header = new Node(-1, maxLevel); // Header node with a dummy key}

}

SkipList::~SkipList() {
    Node* current=header;
    while (current){
        Node*next=current->forward[0];
        delete current;
        current=next;
    }
}

int SkipList::randomLevel() {
    int level=0;
    while ((float)rand()/RAND_MAX<PROBABILITY&&level<MAX_LEVEL){
        level++;
    }
    return level;
}

void SkipList::insert(int key) {
    Node*current=header;
    Node*Update[MAX_LEVEL+1];
    for (int i = currentLevel; i >=0 ;--i) {
        while (current->forward[i]&&current->forward[i]->key<key){
            current=current->forward[i];
        }
        Update[i]=current;
    }
    current=current->forward[0];
    if(!current||current->key!=key) {
        int newLevel = randomLevel();
        if (newLevel > currentLevel) {
            for (int i = currentLevel + 1; i <= newLevel; ++i) {
                Update[i] = header;
            }
            currentLevel = newLevel;
        }
        Node*newNode=new Node(key,newLevel);
        for (int i = 0; i <= newLevel; ++i) {
            newNode->forward[i]=Update[i]->forward[i];
            Update[i]->forward[i]=newNode;

        }
    }

}

void SkipList::print() {
    cout << "\nSkip List:\n";
    for (int i = currentLevel; i >= 0; i--) {
        Node* current = header->forward[i];
        cout << "Level " << i << ": ";
        while (current) {
            cout << current->key << " ";
            current = current->forward[i];
        }
        cout << "\n";
    }
}
bool SkipList::Search(int value) {
    Node*current=header;
    for(int i=currentLevel ;i>=0;i--){
        while(current->forward[i] && current->forward[i]->key < value){
            current=current->forward[i];
        }

    }
    current= current->forward[0];

    if(current && current->key==value) return true;
    else return false;

}
void SkipList:: Delete(int value){
    Node*current=header;
    Node*update[maxLevel+1];

    for(int i=currentLevel ;i>=0;i--){
        while(current->forward[i] && current->forward[i]->key < value){
            current=current->forward[i];
        }
        update[i]=current;
    }

    current=current->forward[0];

    if(current && current->key==value) {

        for (int i = 0; i <= currentLevel; i++) {

            if (update[i]->forward[i] != current) {

                break;

            }
            update[i]->forward[i] = current->forward[i];

        }
        delete current;


        while (currentLevel > 0 && !header->forward[currentLevel]) {
            currentLevel--;

        }
        cout << "deleted successfully" << endl;
    }
}

