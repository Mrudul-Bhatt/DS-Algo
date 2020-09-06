#include <bits/stdc++.h>
using namespace std;

// Struct
struct Node
{
    int data;
    struct Node *next;
};

Node *seperateEvenOdd(Node *head)
{
    int value;
    Node *es = NULL, *ee = NULL, *os = NULL, *oe = NULL;
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        value = curr->data;
        if (value % 2 == 0)
        {
            if (es == NULL)
            {
                es = curr;
                ee = es;
            }
            else
            {
                ee->next = curr;
                ee = ee->next;
            }
        }
        else
        {
            if (os == NULL)
            {
                os = curr;
                oe = os;
            }
            else
            {
                oe->next = curr;
                oe = oe->next;
            }
        }
    }
    if (os == NULL || es == NULL)
        return;
    ee->next = os;
    oe->next = NULL;

    return es;
}

// Function to add a new node
void push(struct Node **head_ref, int new_data)
{
    /* allocate node */
    struct Node *new_node = new Node;

    /* put in the data */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

// A utility function to print a given linked list
void printList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// Driver Code
int main()
{
    // Start with the empty list
    struct Node *head = NULL;

    // Iterate and add element
    for (int i = 5; i > 0; i--)
    {
        push(&head, i);
    }
    printList(head);
    head = seperateEvenOdd(head);
    printList(head);

    return 0;
}
