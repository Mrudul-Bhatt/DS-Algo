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
bool pairsum(Node *root, int sum, unordered_set<int> &s)
{
    if (root == NULL)
        return false;
    if (pairsum(root->left, sum, s) == true)
        return true;
    if (s.find(sum - root->data) != s.end())
        return true;
    else
        s.insert(root->data);
    return pairsum(root->right, sum, s);
}

int main()
{
    struct Node *root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    unordered_set<int> s;
    cout << "\nInorder traversal of binary tree is \n";
    Inorder(root);
    cout << endl;
    cout << pairsum(root, 10, s);

    return 0;
}
