// #include <bits/stdc++.h>
// using namespace std;

// struct Node
// {
//     int data;
//     struct Node *left, *right;
//     Node(int data)
//     {
//         this->data = data;
//         left = right = NULL;
//     }
// };
// void Inorder(Node *root)
// {
//     if (root != NULL)
//     {
//         Inorder(root->left);
//         cout << root->data << " ";
//         Inorder(root->right);
//     }
// }
// void kth(Node *root, int k, int &count)
// {
//     if (root != NULL)
//     {
//         kth(root->right, k, count);
//         count++;
//         if (count == k)
//         {
//             cout << root->data;
//             return;
//         }
//         kth(root->right, k, count);
//     }
// }

// int main()
// {
//     struct Node *root = new Node(6);
//     root->left = new Node(4);
//     root->right = new Node(7);
//     root->left->left = new Node(3);
//     root->left->right = new Node(5);
//     int count = 0;
//     cout << "\nInorder traversal of binary tree is \n";
//     Inorder(root);
//     cout << endl;
//     kth(root, 2, count);

//     return 0;
// }

// A simple inorder traversal based C++ program
// to find k-th smallest element in a BST.
#include <iostream>
using namespace std;

// A BST node
struct Node
{
    int data;
    Node *left, *right;
    int lCount;
    Node(int x)
    {
        data = x;
        left = right = NULL;
        lCount = 0;
    }
};

// Recursive function to insert an key into BST
Node *insert(Node *root, int x)
{
    if (root == NULL)
        return new Node(x);

    // If a node is inserted in left subtree, then
    // lCount of this node is increased. For simplicity,
    // we are assuming that all keys (tried to be
    // inserted) are distinct.
    if (x < root->data)
    {
        root->left = insert(root->left, x);
        root->lCount++;
    }

    else if (x > root->data)
        root->right = insert(root->right, x);
    return root;
}

// Function to find k'th largest element in BST
// Here count denotes the number of nodes processed so far
Node *kthSmallest(Node *root, int k)
{
    // base case
    if (root == NULL)
        return NULL;

    int count = root->lCount + 1;
    if (count == k)
        return root;

    if (count > k)
        return kthSmallest(root->left, k);

    // else search in right subtree
    return kthSmallest(root->right, k - count);
}

// main function
int main()
{
    Node *root = NULL;
    int keys[] = {20, 8, 22, 4, 12, 10, 14};

    for (int x : keys)
        root = insert(root, x);

    int k = 4;
    Node *res = kthSmallest(root, k);
    if (res == NULL)
        cout << "There are less than k nodes in the BST";
    else
        cout << "K-th Smallest Element is " << res->data;
    return 0;
}
