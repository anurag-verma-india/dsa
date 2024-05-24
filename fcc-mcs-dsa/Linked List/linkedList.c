#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* head;

void Insert(int x);
void Print();

int main() {
    printf("\n");
    head = NULL;

    struct Node* Node1 = (struct Node*)malloc(sizeof(struct Node));
    Node1 -> data = 42;
    Node1 -> next = NULL;
    head = Node1;

    Insert(44); 
    Insert(46); 

    Print();
    
//    for(int i; i)

    printf(" %d", Node1->data);

    // printf("\n");
    printf("\n");
    return 0;
}

void Print() {
    struct Node* temp = head;
    printf("The list is: ");
    while(temp != NULL) {
        printf(" %d", temp->data);
        temp= temp->next;
    }
    printf("\n");
}

void Insert(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = x;
    temp -> next = head;
    head = temp;
}

// Program will do
// Make a node | insert 42 in it | make head point this node