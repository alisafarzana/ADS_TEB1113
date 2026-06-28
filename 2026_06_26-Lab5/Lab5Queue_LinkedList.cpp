// LAB 5 QUEUE LINKED LIST

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next = NULL;
};

class Queue {
public:
    Node* front = NULL;
    Node* rear = NULL;

    // Enqueue: add data at the rear
    void enqueue(string name) {
        Node* newNode = new Node();
        newNode->name = name;
        newNode->next = NULL;

        if (rear == NULL) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << name << " added into queue." << endl;
    }

    // Dequeue: remove data from the front
    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        Node* temp = front;

        cout << "Removed: " << temp->name << endl;

        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        delete temp;
    }

    // Peek: show front data
    void peek() {
        if (front == NULL) {
            cout << "Queue is empty." << endl;
        }
        else {
            cout << "Front element is: " << front->name << endl;
        }
    }

    // Display all queue elements
    void display() {
        if (front == NULL) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* current = front;

        while (current != NULL) {
            cout << current->name << endl;
            current = current->next;
        }
    }
};

int main() {
    Queue* queue = new Queue();

    queue->enqueue("Aimar");
    queue->enqueue("Ahmad");
    queue->enqueue("Aiman");
    queue->enqueue("Alisa");

    cout << "\nQueue List:" << endl;
    queue->display();

    cout << endl;
    queue->peek();

    cout << endl;
    queue->dequeue();

    cout << "\nAfter dequeue:" << endl;
    queue->display();

    return 0;
}