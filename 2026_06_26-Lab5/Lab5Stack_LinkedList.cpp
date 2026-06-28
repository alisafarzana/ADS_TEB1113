#include <iostream>
using namespace std;

class Stack{
    public:
        string name;
        Stack* next = NULL;
        Stack* top = NULL;
        //push
        void push(string name){
            Stack* newnode = new Stack();
            newnode->name = name;
            newnode->next = top;
            top = newnode;
        }
        //pop
        void pop() {
            if (top == NULL) {
                cout << "Stack is empty" << endl;
                return;
            }
        Stack* temp = top;
        cout << temp->name << " popped from stack." << endl;
        top = top->next;
        delete temp;
        }
        
        //peek
        void peek() {
        if (top == NULL) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Top element is: " << top->name << endl;
        }

        //display node
        void display(){
            Stack* display_node = top;
            while (display_node != NULL){
                cout<<display_node->name<<endl;
                display_node = display_node->next;
            }
        }

};

int main() {
    Stack* stack = new Stack();

    stack->push("Aimar");
    stack->push("Ahmad");
    stack->push("Aiman");

    cout<<"Stack List: "<<endl;
    stack->display();  
  
    cout<<endl;

    stack->peek();

    cout<<endl;

    stack->pop();

    cout<<endl;

    cout<<"After pop: "<<endl;
    stack->display();
    
    return 0;
}