// LAB 5 QUEUE ARRAY

#include <iostream>
#include <string>
using namespace std;

class Queue {
public:
    string arr[5];
    int front = -1;
    int rear = -1;
    int size = 5;

    // Enqueue: add data at the rear
    void enqueue(string name) {
        if (rear == size - 1) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear++;
        arr[rear] = name;

        cout << name << " added into queue." << endl;
    }

    // Dequeue: remove data from the front
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        cout << "Removed: " << arr[front] << endl;
        front++;

        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }

    // Peek: show front data
    void peek() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Front element is: " << arr[front] << endl;
    }

    // Display all queue elements
    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty." << endl;
            return;
        }

        for (int i = front; i <= rear; i++) {
            cout << arr[i] << endl;
        }
    }
};

int main() {
    Queue queue;

    queue.enqueue("Aimar");
    queue.enqueue("Ahmad");
    queue.enqueue("Aiman");
    queue.enqueue("Alisa");

    cout << "\nQueue List:" << endl;
    queue.display();

    cout << endl;
    queue.peek();

    cout << endl;
    queue.dequeue();

    cout << "\nAfter dequeue:" << endl;
    queue.display();

    return 0;
}