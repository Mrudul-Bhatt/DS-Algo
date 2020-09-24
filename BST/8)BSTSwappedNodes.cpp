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
void fixBST(Node *root, Node *&prev, Node *&first, Node *&second)
{
    if (root == NULL)
        return;
    fixBST(root->left, prev, first, second);
    if (prev != NULL && root->data < prev->data)
    {
        if (first == NULL)
        {
            first = prev;
        }
        second = root;
    }
    prev = root;
    fixBST(root->right, prev, first, second);
}

int main()
{
    struct Node *root = new Node(4);
    root->left = new Node(6);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    int count = 0;
    cout << "\nInorder traversal of binary tree is \n";
    Inorder(root);
    cout << endl;
    Node *prev = NULL;
    Node *first = NULL;
    Node *second = NULL;
    fixBST(root, prev, first, second);
    if (!first)
        cout << "null1 ";
    if (!second)
        cout << "null2 ";
    if (first && second)
        cout << "nodes to be changed" << first->data << " " << second->data;
    //swap(first, second);
    cout << endl;
    cout << "\nInorder traversal of binary tree is \n";
    Inorder(root);

    return 0;
}
