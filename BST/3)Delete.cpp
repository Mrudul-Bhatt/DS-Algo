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
Node *getSuccessor(Node *root)
{
    Node *curr = root->right;
    while (curr != NULL && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}
Node *deleteX(Node *root, int x)
{
    if (root == NULL)
        return root;
    if (root->data < x)
        deleteX(root->right, x);
    else if (root->data > x)
        deleteX(root->left, x);
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete (root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete (root);
            return temp;
        }
        else
        {
            Node *succ = getSuccessor(root);
            root->data = succ->data;
            root->right = deleteX(root->right, succ->data);
            //nodes next successor can only be in its right so we call
            //its right child to delete duplicate node
        }
        return root;
    }
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
    deleteX(root, 4);
    cout << endl;
    cout << "\nInorder traversal of binary tree is \n";
    Inorder(root);

    return 0;
}
