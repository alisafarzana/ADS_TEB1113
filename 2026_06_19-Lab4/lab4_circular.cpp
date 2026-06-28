#include <iostream>
using namespace std;

struct Node{
    string name;
    Node* next = NULL;

};

int main(){ 

    Node* node1 = new Node();
    Node* node2 = new Node();
    Node* node3 = new Node();
    Node* node4 = new Node();

    node1->name = "Aimar";
    node1->next = node2;

    node2->name = "Anjana";
    node2->next = node3;

    node3->name = "Alisa";
    node3->next = node4;

    node4->name = "Jessy";
    node4->next = node1;


    Node* display_node = node1;
    for (int i = 0; i<8; i++){
        cout<<display_node->name<<endl;
        display_node = display_node->next;
    }


    return 0;
}