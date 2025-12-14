#include <iostream>
using namespace std;


// linear data structures


class Node {
public:
    int data;
    Node *next;

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

    void push_back(int data) {
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
    
    int empty() {
        return (stackSize == 0);
    }

};


class Queue {
    
}


int main () {


    int n;
    cin >> n;


    


    return 0;
}