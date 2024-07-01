#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *Insert(struct Node *head, int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (head->next != NULL)
        temp->next = head;
    head->next = temp;
    // temp->data = x;
    // temp->next = NULL;
    // head = temp;
    return head;
}

void Print(struct Node *head)
{
    printf("The list is: ");
    while (head->next != NULL)
    {
        printf(head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    printf("\n");
    struct Node *head = NULL;
    int n, i, x;
    printf("How many numbers are in the list?\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Number to insert: ");
        scanf(" %d", &x);
        printf("\nstarting head\n");
        head = Insert(head, x);
        printf("\nstarting print\n");
        Print(head);
    }
    printf("\n");
    return 0;
}