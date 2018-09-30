#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct node
{
	ll data;
	node *left, *right;
};
node *newNode(ll x)
{
	node *temp = new node();
	temp->data = x;
	temp->left = temp->right = NULL;
	return temp;
}
node *Insert(node *root, ll a)
{
	if (!root)
		root = newNode(a);
	else if (a > root->data)
		root->right = Insert(root->right, a);
	else
		root->left = Insert(root->left, a);
	return root;
}
node *findMin(node *root)
{
	if (!root)
		return NULL;
	else if (!root->left)
		return root;

	return findMin(root->left);
}
node *deleteNode(node *root, ll x)
{
	if (!root)
		return root;
	else if (x < root->data)
		root->left = deleteNode(root->left, x);
	else if (x > root->data)
		root->right = deleteNode(root->right, x);
	else
	{
		if (!root->left && !root->right)
		{
			delete(root);
			root = NULL;
		}
		else if (!root->right)
		{
			node *temp = root;
			root = root->left;
			delete(temp);
		}
		else if (!root->left)
		{
			node *temp = root;
			root = root->right;
			delete(temp);
		}
		else
		{
			node *temp = findMin(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
		}
	}
	return root;
}
void inorder(node *root)
{
	if (root)
	{
		inorder(root->left);
		cout << root->data << ' ';
		inorder(root->right);
	}
}
int main()
{
	node *root = NULL;
	ll n, a;
	cin >> n;
	for (ll i = 0; i < n; i++)
	{
		cin >> a;
		root = Insert(root, a);
	}
	for (ll i = 0; i < 5; i++)
	{
		cin >> a;
		deleteNode(root, a);
		inorder(root);
		cout << '\n';
	}
	//cin >> a;
}
