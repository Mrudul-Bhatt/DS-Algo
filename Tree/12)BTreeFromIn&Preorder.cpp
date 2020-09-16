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
int preIndex = 0;
Node *makeBTree(unordered_map<int, int> h, int pre[], int is, int ie)
{
    if (is > ie)
        return NULL;
    Node *root = new Node(pre[preIndex++]);
    int inIndex;
    if (h.find(root->data) != h.end())
        inIndex = h[root->data];
    root->left = makeBTree(h, pre, is, inIndex - 1);
    root->right = makeBTree(h, pre, inIndex + 1, ie);
    return root;
}

void Inorder(Node *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}

int main()
{
    int in[5] = {20, 10, 40, 30, 50}, pre[5] = {10, 20, 30, 40, 50}, n = 5, is = 0, ie = n - 1;
    //creating hashmap for inorder array
    unordered_map<int, int> h;
    for (int i = 0; i < n; i++)
        h[in[i]] = i;
    Node *root = makeBTree(h, pre, is, ie);
    //Prints the tree that we made on screen
    Inorder(root);

    return 0;
}
