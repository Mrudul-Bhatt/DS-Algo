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

Node *lca(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
    if (root->data == n1 || root->data == n2)
        return root;
    Node *lca1 = lca(root->left, n1, n2);
    Node *lca2 = lca(root->right, n1, n2);
    if (lca1 != NULL && lca2 != NULL)
        return root;
    if (lca1 != NULL)
        return lca1;
    else
        return lca2;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Node *temp = lca(root, 4, 5);
    cout << temp->data;
    return 0;
}
