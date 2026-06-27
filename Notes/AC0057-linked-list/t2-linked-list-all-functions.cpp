#include <iostream>
using namespace std;

/*
push_front
push_back
pop_front
pop_back

insert(val, pos)

search

printLL
*/

class Node {
   public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
    Node* HEAD;
    Node* TAIL;

   public:
    LinkedList() {
        HEAD = TAIL = nullptr;
    }

    void push_front(int val) {
        /*
        Push a element to the front of the Linked List
        CASE 1: List is empty
            Make a new node and point HEAD & TAIL to it

        CASE 2: List is not empty
            Make a new node point it's next to HEAD
            Update HEAD to point to this new node
        */
        Node* newNode = new Node(val);
        if (HEAD == nullptr) {
            HEAD = TAIL = newNode;
            return;
        }
        newNode->next = HEAD;
        HEAD = newNode;
        return;
    }
    void print_ll() {
        Node* temp = HEAD;

        cout << endl << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "null" << endl;
        return;
    }
};

int main() {
    LinkedList* l1 = new LinkedList();
    l1->push_front(1);
    l1->push_front(2);
    l1->push_front(3);
    l1->push_front(1);

    l1->print_ll();

    return 0;
}