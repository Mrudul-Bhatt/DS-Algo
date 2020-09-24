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

void TopView(Node *root)
{
    if (root == NULL)
        return;
    map<int, int> m;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        Node *curr = it.first;
        int hd = it.second;
        if (m.find(hd) == m.end())
            m[hd] = curr->data;
        q.pop();
        if (curr->left != NULL)
            q.push({curr->left, hd - 1});
        if (curr->right != NULL)
            q.push({curr->right, hd + 1});
    }
    for (auto it : m)
        cout << it.second << " ";
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
    TopView(root);

    return 0;
}
