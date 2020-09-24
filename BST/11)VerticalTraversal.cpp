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

void VTraversal(Node *root)
{
    if (root == NULL)
        return;
    map<int, vector<int>> m;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        Node *curr = it.first;
        int hd = it.second;
        m[hd].push_back(curr->data);
        q.pop();
        if (curr->left != NULL)
            q.push({curr->left, hd - 1});
        if (curr->right != NULL)
            q.push({curr->right, hd + 1});
    }
    for (auto it : m)
    {
        vector<int> v = it.second;
        for (int x : v)
            cout << x << " ";
        cout << endl;
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
    VTraversal(root);

    return 0;
}
