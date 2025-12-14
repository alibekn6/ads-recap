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


class DequeNode {
public:
    int data;
    DequeNode *next;
    DequeNode *prev;

    DequeNode (int data) {
        this -> data = data;
        this -> prev = NULL;
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
    
    bool empty() {
        return (stackSize == 0);
    }

};



class Queue {
public:
    Node *front;
    Node *rear;
    int queueSize;

    Queue() {
        front = NULL;
        rear = NULL;
        queueSize = 0;
    }

    void push(int data) {
        Node *node = new Node(data);
        if (rear != NULL) {
            front = rear = node;
        } else {
            rear -> next = node;
            rear = node;
        }
        queueSize++;
    }

    void pop() {

        if (empty()) {
            runtime_error("Queue Underflow");
        }

        Node *temp = front;
        front = front -> next;

        if (front == NULL) {
            cout << "WHEN FRONT IS NULL: " << rear -> data;
            rear = NULL;
        }

        delete temp;
        queueSize--;
    }

    int getFront() {
        if (empty()) {
            throw runtime_error("Queue is empty");
        }
        return front -> data;
    }

    int getFront() {
        return front -> data;
    }

    bool empty() {
        return (queueSize == 0);
    }


};



class Deque {
public:
    DequeNode *front;
    DequeNode *rear;
    int dequeSize;

    Deque() {
        front = NULL;
        rear = NULL;
        dequeSize = 0;
    }

    void push_back(int data) {
        DequeNode *node = new DequeNode(data);
        
        if (empty()) {
            front = rear = node;
        } else {
            node -> prev = rear;
            rear -> next = node;
            rear = node;
        }
        dequeSize++;
    }

    void pop_front() {

        if (empty()) {
            runtime_error("Queue Underflow");
        }

        DequeNode *temp = front;
        front = front -> next;

        if (front == NULL) {
            rear = NULL;
        } else {
            front -> prev = NULL;
        }

        delete temp;
        dequeSize--;
    }


    void push_front(int data) {
        DequeNode *node = new DequeNode(data);

        if (empty()) {
            front = rear = node;
        } else {
            node -> next = front;
            front -> prev = node;
            front = node;
        }
        dequeSize++;
    }

    void pop_back() {
        if (empty()) {
            throw runtime_error("Deque Underflow");
        }

        DequeNode *temp = rear;
        rear = rear -> prev;
        if (rear == NULL) {
            front = NULL;
        } else {
            rear -> next = NULL;
        }

        delete temp;
        dequeSize--;
    }



    int getFront() {
        if (empty()) {
            throw runtime_error("Queue is empty");
        }
        return front -> data;
    }

    int getRear() {
        if (empty()) {
            throw runtime_error("Deque is empty");
        }

        return rear -> data;
    }   


    bool empty() {
        return (dequeSize == 0);
    }

    int size() {
        return dequeSize;
    }

    


};


int main () {


    int n;
    cin >> n;


    


    return 0;
}