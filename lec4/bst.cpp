/*



Average time complexity for search, insert, delete: O(log n)

Worst case time complexity (skewed tree): O(n)


Space complexity: O(n) for storing n nodes



In-order traversal of a BST gives elements in sorted order




*/


#include <iostream>
using namespace std;



class Node {
public:
    int data;
    Node *left, *right;

    Node(int data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

};


class BST {
public:
    Node *root;

    BST() {
        root = NULL;
    }

    Node *insert(Node *node, int data) {
        if (node == NULL) {
            node = new Node(data);
            return node;
        }


        if (data <= node->data) {
            node -> left = insert(node -> left, data);
        } else {
            node -> right = insert(node -> right, data);
        }

        return node;
    }


    Node *find(Node *node, int data) {
        if (node == NULL || node->data == data) {
            return node;
        }
    
        if (data <= node->data) {
            return find(node -> left, data);
        } else {
            return find(node -> right, data);
        }
    }



    Node *findMax(Node *node) {
        if (node == NULL)
            return NULL;
        while (node->right != NULL)
            node = node->right;
        return node;
    }

    Node *findMin(Node *node) {
        if (node == NULL) {
            return NULL;
        }
        while (node -> left != NULL) {
            node = node -> left;
        }
        return node;
    }

    Node *deleteNode(Node *node, int data) {

        if (node == NULL)
            return NULL;

        if (data < node -> data) {
            node -> left = deleteNode(node -> left, data);
        } else if (data > node -> data) {
            node -> right = deleteNode(node -> right, data);
        } else {
            // we found it

            // case 1 leaf node

            if (node -> right == NULL && node -> left == NULL) {
                delete node;
                node = NULL; 
            } else if (node -> left == NULL) { // case 2, node has only right child
                Node *temp = node;
                node = node -> right;
                delete temp;
            }  else if (node -> right == NULL) { // case 3 , node has only left child
                Node *temp = node;
                node = node -> left;
                delete temp;
            } else {
                Node *temp = findMax(node->left);  
                node->data = temp->data;
                node->left = deleteNode(node->left, temp->data);
            }
        }



    }



    int getHeight(Node *node) {
        if (node == NULL)
            return 0;
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }

    int countNodes(Node *node) {
        if (node == NULL)
            return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }


    void inOrder(Node *node) {
        if (node == NULL)
            return;
        
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    void preOrder(Node *node) {
        if (node == NULL)
            return;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void postOrder(Node *node) {
        if (node == NULL)
            return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }






};

int main() {



    return 0;
}