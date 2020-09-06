#include <bits/stdc++.h>
using namespace std;

// Structure of linked list Node
struct Node
{
    int data;
    Node *next, *random;
    Node(int x)
    {
        data = x;
        next = random = NULL;
    }
};

// Utility function to print the list.
void print(Node *start)
{
    Node *ptr = start;
    while (ptr)
    {
        cout << "Data = " << ptr->data << ", Random = "
             << ptr->random->data << endl;
        ptr = ptr->next;
    }
}

// This function clones a given linked list
// in O(1) space
Node *clone(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        // Node *newNode = new Node;
        // newNode->data = curr->data;

        Node *next = curr->next;
        curr->next = new Node(curr->data);
        curr->next->next = next;
        curr = next;
    }
    // for (curr = head; curr != NULL; curr = curr->next)
    // curr->next->random = (curr->random != NULL) ? curr->random->next : NULL;
    curr = head;
    while (curr != NULL)
    {
        if (curr->next)
            curr->next->random = curr->random ? curr->random->next : curr->random;
        curr = curr->next ? curr->next->next : curr->next;
    }
    Node *head1 = head;
    Node *head2 = head->next;
    curr = head->next;
    while (head1 != NULL && head2 != NULL)
    {
        head1->next = head1->next ? head1->next->next : head1->next;
        head2->next = head2->next ? head2->next->next : head2->next;
        head1 = head1->next;
        head2 = head2->next;
    }

    return curr;
}

// Driver code
int main()
{
    Node *start = new Node(1);
    start->next = new Node(2);
    start->next->next = new Node(3);
    start->next->next->next = new Node(4);
    start->next->next->next->next = new Node(5);

    // 1's random points to 3
    start->random = start->next->next;

    // 2's random points to 1
    start->next->random = start;

    // 3's and 4's random points to 5
    start->next->next->random =
        start->next->next->next->next;
    start->next->next->next->random =
        start->next->next->next->next;

    // 5's random points to 2
    start->next->next->next->next->random =
        start->next;

    cout << "Original list : \n";
    print(start);

    cout << "\nCloned list : \n";
    Node *cloned_list = clone(start);
    print(cloned_list);

    return 0;
}
