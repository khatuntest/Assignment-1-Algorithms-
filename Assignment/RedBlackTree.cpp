#include <iostream>
using namespace std;

class Red_black_tree {
private:
    struct Node {
        int data;
        char color; // 'R' -> red, 'B' -> black
        Node *left, *right, *parent;
        Node(int data) {
            this->data = data;
            left = nullptr;
            right = nullptr;
            parent = nullptr;
            this->color = 'R'; // Default color is red
        }
    };
    Node* root;
public:
    Red_black_tree() {
        root = nullptr;
    }

    void rotateLeft(Node* x) {
        cout << "Rotating left at node: " << x->data << endl;
        Node* y = x->right;
        x->right = y->left;
        if (y->left != nullptr) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
        cout << "Left rotation completed." << endl;
    }

    void rotateRight(Node* x) {
        cout << "Rotating right at node: " << x->data << endl;
        Node* y = x->left;
        x->left = y->right;
        if (y->right != nullptr) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        } else if (x == x->parent->right) {
            x->parent->right = y;
        } else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
        cout << "Right rotation completed." << endl;
    }

    void Insert(const int& value) {
        cout << "Inserting value: " << value << endl;
        Node* node = new Node(value);
        Node* pos = nullptr;
        Node* current = this->root;

        while (current != nullptr) {
            pos = current;
            if (node->data < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        node->parent = pos;
        if (pos == nullptr) {
            this->root = node;
        } else if (node->data < pos->data) {
            pos->left = node;
        } else {
            pos->right = node;
        }

        if (node->parent == nullptr) {
            node->color = 'B';
            cout << "Node is root, setting color to black." << endl;
            return;
        }
        if (node->parent->parent == nullptr) {
            return;
        }
        FixInsert(node);
    }

    void FixInsert(Node* node) {
        cout << "Fixing insertion..." << endl;
        Node* uncle;
        while (node->parent != nullptr && node->parent->color == 'R') {
            cout << "Parent is red, fixing..." << endl;
            if (node->parent == node->parent->parent->left) {
                uncle = node->parent->parent->right;
                if (uncle != nullptr && uncle->color == 'R') {
                    uncle->color = 'B';
                    node->parent->color = 'B';
                    node->parent->parent->color = 'R';
                    node = node->parent->parent;
                    cout << "Case 1: Recoloring and moving up." << endl;
                } else {
                    if (node == node->parent->right) {
                        rotateLeft(node->parent);
                        node = node->parent;
                        cout << "Case 2: Left rotation performed." << endl;
                    }
                    node->parent->color = 'B';
                    node->parent->parent->color = 'R';
                    rotateRight(node->parent->parent);
                    cout << "Case 3: Right rotation performed." << endl;
                }
            } else {
                uncle = node->parent->parent->left;
                if (uncle != nullptr && uncle->color == 'R') {
                    uncle->color = 'B';
                    node->parent->color = 'B';
                    node->parent->parent->color = 'R';
                    node = node->parent->parent;
                    cout << "Case 1: Recoloring and moving up (left side)." << endl;
                } else {
                    if (node == node->parent->left) {
                        rotateRight(node->parent);
                        node = node->parent;
                        cout << "Case 2: Right rotation performed (left side)." << endl;
                    }
                    node->parent->color = 'B';
                    node->parent->parent->color = 'R';
                    rotateLeft(node->parent->parent);
                    cout << "Case 3: Left rotation performed (left side)." << endl;
                }
            }
        }
        root->color = 'B';
        cout << "Fixing insertion completed." << endl;
    }

    void DeleteNode(const int& data) {
        cout << "Deleting node with value: " << data << endl;
        Node* search = this->root;
        Node* pos = nullptr;
        // Search for the node to delete
        while (search != nullptr) {
            if (search->data == data) {
                pos = search;
            }
            if (search->data >= data) {
                search = search->left;
            } else {
                search = search->right;
            }
        }

        if (pos == nullptr) {
            cout << "The item is not here...\n";
            return;
        }
        cout << "Node found. Proceeding to deletion..." << endl;
        Node* temp = pos;
        Node* rep;
        char color = temp->color;
        if (pos->left == nullptr) {
            rep = pos->right;
            transplant(pos, rep);
        } else if (pos->right == nullptr ) {
            rep = pos->left;
            transplant(pos, rep);
        } else {
            temp = minValueNode(pos->right); // Get the minimum node in the right subtree
            color = temp->color;               // Store the color of the node to be deleted
            rep = temp->right;

            if (temp->parent == pos) {
                if (rep != nullptr)
                    rep->parent = temp;
            } else {
                transplant(temp, temp->right);
                temp->right = pos->right;
                temp->right->parent = temp;
            }

            transplant(pos, temp);
            temp->left = pos->left;
            temp->left->parent = temp;
            temp->color = pos->color; // Copy the color of the deleted node
        }
        delete pos;
        if (color == 'B' ){
            FixDelete(rep);}

    }

    void FixDelete(Node* node) {
        cout << "Fixing deletion..." << endl;
        while (node != root && node->color == 'B') {
            cout << "Node is black, fixing..." << endl;
            if (node == node->parent->left) {
                Node* bro = node->parent->right;

                if (bro->color == 'R') {
                    bro->color = 'B'; // Case 1
                    node->parent->color = 'R';
                    rotateLeft(node->parent);
                    bro = node->parent->right;
                    cout << "Case 1: Recoloring and rotating left." << endl;
                }

                if ((bro->left == nullptr || bro->left->color == 'B') && (bro->right == nullptr || bro->right->color == 'B')) {
                    bro->color = 'R'; // Case 2
                    node = node->parent;
                    cout << "Case 2: Recoloring brother." << endl;
                } else {
                    if (bro->right == nullptr || bro->right->color == 'B') {
                        if (bro->left != nullptr)
                            bro->left->color = 'B';
                        bro->color = 'R';
                        rotateRight(bro);
                        bro = node->parent->right;
                        cout << "Case 3: Right rotation performed." << endl;
                    }

                    bro->color = node->parent->color; // Case 3
                    node->parent->color = 'B';
                    if (bro->right != nullptr)
                        bro->right->color = 'B';
                    rotateLeft(node->parent);
                    node = root; // End the loop
                }
            } else {
                Node* bro = node->parent->left;

                if (bro->color) {
                    bro->color = 'B'; // Case 1
                    node->parent->color = 'R';
                    rotateRight(node->parent);
                    bro = node->parent->left;
                    cout << "Case 1: Recoloring and rotating right." << endl;
                }

                if ((bro->right == nullptr || bro->right->color == 'B') && (bro->left == nullptr || bro->left->color == 'B')) {
                    bro->color = 'R'; // Case 2
                    node = node->parent;
                    cout << "Case 2: Recoloring brother (right side)." << endl;
                } else {
                    if (bro->left == nullptr || bro->left->color == 'B') {
                        if (bro->right != nullptr)
                            bro->right->color = 'B';
                        bro->color = 'R';
                        rotateLeft(bro);
                        bro = node->parent->left;
                        cout << "Case 3: Left rotation performed." << endl;
                    }

                    bro->color = node->parent->color; // Case 3
                    node->parent->color = 'B';
                    if (bro->left != nullptr)
                        bro->left->color = 'B';
                    rotateRight(node->parent);
                    node = root; // End the loop
                }
            }
        }

        node->color = 'B';
        cout << "Fixing deletion completed." << endl;
    }

    void transplant(Node* u, Node* v) {
        if (u->parent == nullptr) {
            this->root = v;
        } else if (u == u->parent->left) {
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }
        if (v != nullptr) {
            v->parent = u->parent;
        }
        cout << "Transplant completed." << endl;
    }

    Node * minValueNode(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    void inorderHelper(Node* node) {
        if (node == nullptr) return;
        inorderHelper(node->left);
        cout << node->data << ","<<node->color<<"  ";
        inorderHelper(node->right);
    }

    void inorder() {
        inorderHelper(root);
    }


};


int main() {
    Red_black_tree rbtree;
    // Inserting values into Red-Black Tree
    rbtree.Insert(7);
    rbtree.Insert(3);
    rbtree.Insert(18);
    rbtree.Insert(10);
    rbtree.Insert(22);
    rbtree.Insert(8);
    rbtree.Insert(11);
    rbtree.Insert(26);
    rbtree.Insert(2);
    rbtree.Insert(6);
    // Printing Red-Black Tree
    rbtree.inorder();
    // Deleting nodes from Red-Black Tree
    cout <<"\n" <<"After deleting 18:" << endl;
    rbtree.DeleteNode(18);
    rbtree.inorder ();

    cout <<"\n"<<"After deleting 11:" << endl;
    rbtree.DeleteNode (11);
    rbtree.inorder ();

    cout <<"\n"<<"After deleting 3:" << endl;
    rbtree.DeleteNode (3);
    rbtree.inorder();

    return 0;
}