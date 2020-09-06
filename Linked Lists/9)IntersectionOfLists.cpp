#include <bits/stdc++.h>
using namespace std;

// Struct
struct Node
{
    int data;
    struct Node *next;
};

int intersection(Node *head1, Node *head2)
{
    Node *curr = NULL;
    int c1 = 0, c2 = 0;
    for (curr = head1; curr != NULL; curr = curr->next)
        c1++;
    for (curr = head2; curr != NULL; curr = curr->next)
        c2++;
    curr = c1 > c2 ? head1 : head2;
    for (int i = 0; i < abs(c1 - c2); i++)
        curr = curr->next;
    Node *curr2 = c1 > c2 ? head2 : head1;
    while (curr != NULL && curr2 != NULL)
    {
        if (curr == curr2)
            return curr->data;
        curr = curr->next;
        curr2 = curr2->next;
    }

    return -1;
}

// Function to add a new node
// void push(struct Node **head_ref, int new_data)
// {
//     /* allocate node */
//     struct Node *new_node = new Node;

//     /* put in the data */
//     new_node->data = new_data;

//     /* link the old list off the new node */
//     new_node->next = (*head_ref);

//     /* move the head to point to the new node */
//     (*head_ref) = new_node;
// }

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
    Node *newNode;

    // Addition of new nodes
    Node *head1 = new Node();
    head1->data = 10;

    Node *head2 = new Node();
    head2->data = 3;

    newNode = new Node();
    newNode->data = 6;
    head2->next = newNode;

    newNode = new Node();
    newNode->data = 9;
    head2->next->next = newNode;

    newNode = new Node();
    newNode->data = 15;
    head1->next = newNode;
    head2->next->next->next = newNode;

    newNode = new Node();
    newNode->data = 30;
    head1->next->next = newNode;

    head1->next->next->next = NULL;

    printList(head1);
    printList(head2);
    int val = intersection(head1, head2);
    cout << val;

    return 0;
}
