#include <bits/stdc++.h>
using namespace std;

// Struct
struct Node
{
    int data;
    struct Node *next;
};

void removeLoop(Node *head)
{
    if (head == NULL)
        return;
    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
            break;
    }
    if (fast == head)
    {
        while (fast->next != head)
        {
            fast = fast->next;
        }
        fast->next = NULL;
        return;
    }
    if (fast != slow)
        return;
    slow = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
    return;
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

    //creating loop
    head->next->next->next->next->next = head;

    removeLoop(head);
    printList(head);

    return 0;
}
