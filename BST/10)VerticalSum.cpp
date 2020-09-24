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
void getVSum(Node *root, int hd, map<int, int> &m)
{
    if (root == NULL)
        return;
    getVSum(root->left, hd - 1, m);
    m[hd] += root->data;
    getVSum(root->right, hd + 1, m);
}
void printVSum(Node *root)
{
    if (root == NULL)
        return;
    map<int, int> m;
    int hd = 0;
    getVSum(root, hd, m);
    for (auto sum : m)
        cout << sum.second << " ";
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
    printVSum(root);

    return 0;
}
