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
bool ifBST(Node *root, int min, int max)
{
    if (root == NULL)
        return true;
    return (root->data > min &&
            root->data < max &&
            ifBST(root->left, min, root->data) &&
            ifBST(root->right, root->data, max));
}

int main()
{
    struct Node *root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    int count = 0;
    cout << "\nInorder traversal of binary tree is \n";
    Inorder(root);
    cout << endl;
    cout << ifBST(root, INT_MIN, INT_MAX);

    return 0;
}
