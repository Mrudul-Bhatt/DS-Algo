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
int getMax(Node *root)
{
    if (root == NULL)
        return INT_MIN;
    else
        return max(root->data, max(getMax(root->left), getMax(root->right)));
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << getMax(root);

    return 0;
}
