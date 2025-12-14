#include <iostream>
using namespace std;


/*
 * STACK - Time & Space Complexity
 * ================================
 * Accessing (top):    O(1)
 * Inserting (push):   O(1)
 * Deleting (pop):     O(1)
 * Searching:          O(n)
 * Space:              O(n)
 */


class Node {
public:
    Node *next;
    int data;


    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};


class Stack {
public:
    Node *topNode;
    int stackSize;


    Stack() {
        topNode = NULL;
        stackSize = 0;
    }

    void push(int data) {
        Node *node = new Node(data);
        node -> next = topNode;
        topNode = node;
        stackSize++;
    }


    void pop() {
        if (topNode != NULL) {
            Node *temp = topNode;
            topNode = topNode -> next;
            delete temp;
            stackSize--;
        }
    }


    int top () {
        if (topNode != NULL) {
            return topNode -> data;
        }
        throw runtime_error("stack is empty!");
    }

    int size() {
        return stackSize;
    }
    
    bool empty() {
        return (stackSize == 0);
    }

};
