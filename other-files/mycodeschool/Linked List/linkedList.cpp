#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *link;
};

int main()
{
    cout << endl;
    Node *A;
    A = NULL;

    // Create a new node
    Node *temp = new Node;
    temp->data = 2;
    temp->link = NULL;
    // assign the new node to head
    A = temp;

    // Create another new node
    temp = new Node;
    temp->data = 4;
    temp->link = NULL;

    // Add the new node to the end of the list
    Node *temp1;
    temp1 = A;
    while (temp1->link != NULL)
    {
        temp1 = temp1->link;
    }
    temp1->link = temp;

    cout << "Second node inserted" << endl;

    temp = new Node;
    temp->data = 6;
    temp->link = NULL;

    // Add the new node to the end of the list
    temp1 = A;
    while (temp1->link != NULL)
    {
        temp1 = temp1->link;
    }
    temp1->link = temp;

    // Printing the list
    temp1 = A;
    cout << "The data is: ";
    while (temp1 != NULL)
    {
        cout << temp1->data << " ";
        temp1 = temp1->link;
    }

    cout << endl;
    cout << endl;

    return 0;
}