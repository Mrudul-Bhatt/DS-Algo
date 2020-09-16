#include <bits/stdc++.h>
using namespace std;
int maxLevel = 0;
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
int res = 0;
int diameter(Node *root)
{
    if (root == NULL)
        return 0;
    int lh = diameter(root->left);
    int rh = diameter(root->right);
    res = max(res, 1 + rh + lh);
    return 1 + max(rh, lh);
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    diameter(root);
    cout << res;
    return 0;
}
