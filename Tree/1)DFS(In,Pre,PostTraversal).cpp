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
void Preorder(Node *root)
{
	if (root != NULL)
	{
		cout << root->data << " ";
		Preorder(root->left);
		Preorder(root->right);
	}
}
void Postorder(Node *root)
{
	if (root != NULL)
	{
		Postorder(root->left);
		Postorder(root->right);
		cout << root->data << " ";
	}
}

int main()
{
	struct Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);

	cout << "\nInorder traversal of binary tree is \n";
	Inorder(root);

	cout << "\nPreorder traversal of binary tree is \n";
	Preorder(root);

	cout << "\nPostorder traversal of binary tree is \n";
	Postorder(root);

	return 0;
}
