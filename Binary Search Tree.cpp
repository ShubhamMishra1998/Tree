#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct node
{
	ll data;
	node *left;
	node *right;
};
node *Insert(node *root, ll x)
{
	if (root == NULL)
	{
		root = new node();
		root->data = x;
		root->right = root->left = NULL;
	}
	else if (x < root->data)
		root->left = Insert(root->left, x);
	else
		root->right = Insert(root->right, x);
	return root;
}
bool Search(node *root, ll x)
{
	if (root == NULL)
		return false;
	else if (root->data == x)
		return true;
	else if (x > root->data)
		return Search(root->right, x);
	else
		return Search(root->left, x);
}
int main()
{
	node *root = NULL;
	root = Insert(root, 15);
	root = Insert(root, 12);
	root = Insert(root, 10);
	root = Insert(root, 9);
	root = Insert(root, 19);
	root = Insert(root, 25);
	root = Insert(root, 12);
	ll x;
	cin >> x;
	if (Search(root, x))
		cout << "found";
	else
		cout << "not found";
}
