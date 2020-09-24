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
Node *insertXI(Node *root, int x)
{
    Node *temp = new Node(x);
    Node *prev = NULL, *curr = root;
    while (curr)
    {
        prev = curr;
        if (curr->data > x)
            curr = curr->left;
        else if (curr->data < x)
            curr = curr->right;
        else
            return root;
    }
    if (prev == NULL)
        return temp;
    if (prev->data > x)
        prev->left = temp;
    else
        prev->right = temp;
    return root;
}
Node *insertXR(Node *root, int x)
{
    if (root == NULL)
        return new Node(x);
    else if (root->data > x)
        root->left = insertXR(root->left, x);
    else if (root->data < x)
        root->right = insertXR(root->right, x);
    return root;
}

int main()
{
    struct Node *root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(5);

    cout << "\nInorder traversal of binary tree is \n";
    Inorder(root);
    cout << endl;
    insertXI(root, 1); //iterative
    insertXR(root, 2); //recursive
    cout << endl;
    cout << "\nInorder traversal of binary tree is \n";
    Inorder(root);

    return 0;
}
