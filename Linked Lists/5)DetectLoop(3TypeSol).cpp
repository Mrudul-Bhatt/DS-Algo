#include <bits/stdc++.h>
using namespace std;

// Struct
struct Node
{
    int data;
    struct Node *next;
};

/* Function to get the middle of the linked list*/
bool detectLoop(Node *head)
{
    if (head == NULL)
    {
        return false;
    }
    Node *curr = head;
    Node *temp = new Node;
    Node *next = NULL;

    while (curr != NULL)
    {
        if (curr->next == NULL)
            return false;
        if (curr->next == temp)
            return true;
        next = curr->next;
        curr->next = temp;
        curr = next;
    }
    return false;
}

bool detectLoopHashing(Node *head)
{
    if (head == NULL)
        return false;
    unordered_set<Node *> n;
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        if (n.find(curr) != n.end())
            return true;
        n.insert(curr);
    }
    return false;
}

bool floydLoopDetection(Node *head)
{
    if (head == NULL)
        return false;
    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
            return true;
    }
    return false;
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
    //creating loop
    head->next->next->next->next->next = head;

    //printList(head);
    bool val1 = detectLoop(head); //Using temp pointer
    cout << val1;
    bool val2 = detectLoopHashing(head); //Using hashing
    cout << val2;
    bool val3 = floydLoopDetection(head); //Using floyd cycle method
    cout << val3;

    return 0;
}
