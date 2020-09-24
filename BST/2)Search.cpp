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
bool searchXI(Node *root, int x)
{
	while (root != NULL)
	{
		if (root->data == x)
			return true;
		else if (root->data < x)
			root = root->right;
		else
			root = root->left;
	}
	return false;
}
bool searchXR(Node *root, int x)
{
	if (root == NULL)
		return false;
	else if (root->data == x)
		return true;
	else if (root->data < x)
		return searchXR(root->right, x);
	else
		return searchXR(root->left, x);
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
	cout << searchXI(root, 4) << " "; //iterative
	cout << searchXR(root, 4) << " "; //recursive

	return 0;
}
