#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct node
{
	ll data;
	node *left, *right;
};
node *Insert(node *root, ll x)
{
	if (!root)
	{
		root = new node();
		root->data = x;
		root->left=root->right = NULL;
	}
	if (x < root->data)
		root->left = Insert(root->left, x);
	else if (x > root->data)
		root->right = Insert(root->right, x);

	return root;
}
node *Find(node *root, ll x)
{
	if (root->data == x)
		return root;
	if (x < root->data)
		return Find(root->left, x);
	else if (x > root->data)
		return Find(root->right, x);
}
node *findMin(node *root)
{
	if (!root)
		return NULL;
	while (root->left)
	{
		root = root->left;
	}
	return root;
}
node *inorderSuccessor(node *root, ll x)
{
	if (!root)
		return NULL;
	node *current = Find(root, x);
	if (current->right)
	{
		return findMin(current->right);
	}
	else
	{
		node *ancestor = root;
		node *successor = NULL;
		while (ancestor->data != current->data)
		{
			if (current->data < ancestor->data)
			{
				successor = ancestor;
				ancestor = ancestor->left;
			}
			else
				ancestor = ancestor->right;
		}
		return successor;
	}
}
int main()
{
	node *root = NULL;
	ll n, a;
	cin >> n;
	for (ll i = 0; i<n; i++)
	{
		cin >> a;
		root = Insert(root, a);
	}
	node *temp = inorderSuccessor(root, 12);
	cout << temp->data;
	//cin >> n;
}
