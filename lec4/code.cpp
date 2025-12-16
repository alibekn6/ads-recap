#include <iostream>
#include <queue>
#include <stack>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this -> data = data;
        left = right = nullptr;
    }
};



class bst {
private:
    Node* root;


    
    Node* insertHelper(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }

        if (value < root -> data) {
            root -> left = insertHelper(root -> left, value);
        } else if (value > root -> data) {
            root -> right = insertHelper(root -> right, value);
        }

        return root;
    }

    bool searchHelper(Node* root, int key) {


        if (root -> data == key) return true;
        if (root == nullptr) return false;


        if (key < root -> data) {
            return searchHelper(root -> left, key);
        } else {
            return searchHelper(root -> right, key);
        }
        
    }


    Node* findMin(Node* root) {
        while (root && root->left != nullptr) {
            root = root->left;
        }
        return root;
    }


    Node* destroyTree(Node* root) {
        if (root == nullptr) return;
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }





    Node* deleteHelper(Node* root, int key) {

        if (root == nullptr) return root;

        if (key < root -> data) {
            root -> left = deleteHelper(root -> left, key);
        } else if (key > root -> data) {
            root -> right = deleteHelper(root -> right, key);
        } else {
            // here we found it

            if (root -> left == nullptr) {
                Node* temp = root -> right;
                delete root;
                return temp;
            } else if (root -> right == nullptr) {
                Node* temp = root -> left;
                delete root;
                return temp;
            }



            /*
                  5                    5
                /                     /
               3  ← delete this      7  ← right child moves up
                \
                7 (right)

            */



            /*
            
            
                  10  ← delete this           12  ← replaced with successor
                /  \                         /  \
              5    15                      5    15
                    /  \                         /  \
                   12  20                       ✗   20  ← 12 was deleted here



            */


            // here we have 2 children

            Node* temp = findMin(root -> right);
            root -> data = temp -> data;
            root -> right = deleteHelper(root -> right, temp -> data);
    


        }

        // case 1 -> one child or no child

        // case 2 -> Node with two children


    }

public:
    bst() {
        root = nullptr;
    }

    ~bst() {
        destroyTree(root);
    }

    void insert(int value) {
        root = insertHelper(root, value);
    }

    void remove(int value) {
        root = deleteHelper(root, value);
    }

    bool search(int value) {
        return searchHelper(root, value);
    }



};



int main () {
    return 0;
}