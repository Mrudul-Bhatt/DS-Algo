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
void Inorder(Node *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}

Node *floorX(Node *root, int x)
{
    Node *res = NULL;
    while (root != NULL)
    {
        if (root->data == x)
            return root;
        else if (root->data > x)
            root = root->left;
        else
        {
            res = root;
            root = root->right;
        }
    }
    return res;
}
Node *ceilX(Node *root, int x)
{
    Node *res = NULL;
    while (root != NULL)
    {
        if (root->data == x)
            return root;
        else if (root->data < x)
            root = root->right;
        else
        {
            res = root;
            root = root->left;
        }
    }
    return res;
}

int main()
{
    struct Node *root = new Node(200);
    root->left = new Node(100);
    root->right = new Node(300);
    root->left->left = new Node(50);
    root->left->right = new Node(150);

    cout << "\nInorder traversal of binary tree is \n";
    Inorder(root);
    cout << endl;
    cout << floorX(root, 73)->data << " ";
    cout << ceilX(root, 73)->data << " ";
    cout << endl;
    cout << "\nInorder traversal of binary tree is \n";
    Inorder(root);

    return 0;
}
