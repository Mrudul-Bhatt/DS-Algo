#include <bits/stdc++.h>
using namespace std;

// Struct
struct Node
{
    int data;
    struct Node *next;
};

/* Function to reverse linked list*/
Node *reverseListIteration(struct Node *head)
{
    if (head == NULL)
        return head;
    struct Node *curr = head;
    struct Node *prev = NULL;
    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node *reverseListRecursive(Node *curr, Node *prev)
{
    if (curr == NULL)
        return prev;
    Node *next = curr->next;
    curr->next = prev;
    return reverseListRecursive(next, curr);
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
    head = reverseListIteration(head); //Reverse by Iteration
    printList(head);
    Node *curr = head;
    Node *prev = NULL;
    head = reverseListRecursive(curr, prev); //Reverse by Recursion
    printList(head);

    return 0;
}
