#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
void printAtKDist(Node *root, int k)
{
    if (root == NULL)
        return;
    if (k == 0)
        cout << root->data << " ";
    else
    {
        printAtKDist(root->left, k - 1);
        printAtKDist(root->right, k - 1);
    }
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int k = 1;
    printAtKDist(root, k);

    return 0;
}
