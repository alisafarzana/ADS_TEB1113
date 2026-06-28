#include <iostream>
using namespace std;

class Stack {
public:
    int top = -1;
    int size = 4;
    string arr[4];

    // push
    void push(string name) {
        if (top == size - 1) {
            cout << "Stack is full. Cannot push." << endl;
            return;
        }

        top++;
        arr[top] = name;
    }

    // pop
    void pop() {
        if (top == -1) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }

        cout << arr[top] << " popped from stack." << endl;
        top--;
    }

    // peek
    void peek() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Top element is: " << arr[top] << endl;
    }

    // display
    void display() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack elements:" << endl;

        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
};

int main() {
    Stack s;

    s.push("Aimar");
    s.push("Ahmad");
    s.push("Aiman");
    s.push("Alisa");

    s.display();

    cout << endl;
    s.peek();

    cout << endl;
    s.pop();

    cout << endl;
    s.display();

    cout << endl;
    s.peek();

    return 0;
}