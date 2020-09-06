#include <bits/stdc++.h>
using namespace std;

// Structure of linked list Node
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Utility function to print the list.
void print(Node *head)
{
    Node *ptr = head;
    while (ptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

Node *mergeSortedLists(Node *head1, Node *head2)
{
    Node *head = NULL, *tail = NULL;
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    if (head1->data <= head2->data)
    {
        head = head1;
        tail = head1;
        head1 = head1->next;
    }
    else
    {
        head = head2;
        tail = head2;
        head2 = head2->next;
    }
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data <= head2->data)
        {
            tail->next = head1;
            tail = head1;
            head1 = head1->next;
        }
        else
        {
            tail->next = head2;
            tail = head2;
            head2 = head2->next;
        }
    }
    if (head1 == NULL)
        tail->next = head2;
    else
        tail->next = head1;

    return head;
}

// Driver Code
int main()
{
    // Start with the empty list
    Node *head1 = new Node(10);
    head1->next = new Node(20);
    head1->next->next = new Node(30);
    head1->next->next->next = new Node(40);

    Node *head2 = new Node(5);
    head2->next = new Node(15);
    head2->next->next = new Node(17);
    head2->next->next->next = new Node(18);
    head2->next->next->next->next = new Node(35);

    print(head1);
    print(head2);
    Node *head = mergeSortedLists(head1, head2);
    print(head);

    return 0;
}
