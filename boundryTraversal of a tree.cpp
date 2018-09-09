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
node *Insert(ll v, ll e)
{
	map<ll, node*> hash;
	node *parent = NULL, *child = NULL, *root = NULL;
	while (e--)
	{
		ll a, b;
		cin >> a >> b;
		if (hash.find(a) == hash.end())
		{
			parent = newNode(a);
			if (root == NULL)
				root = parent;
			hash[a] = parent;
		}
		else
			parent = hash[a];
		child = newNode(b);
		hash[b] = child;
		if (!parent->left)
			parent->left = child;
		else
			parent->right = child;

	}
	return root;
}
void printLeaf(node *root)
{
	if (root)
	{
		printLeaf(root->left);
		if (!root->left && !root->right)
			cout << root->data << ' ';
		printLeaf(root->right);
	}
}
void leftBoundry(node *root)
{
	if (root)
	{
		if (root->left)
		{
			cout << root->data << ' ';
			leftBoundry(root->left);
		}
		else if (root->right)
		{
			cout << root->right << ' ';
			leftBoundry(root->right);
		}
	}
}
void rightBoundry(node *root)
{
	if (root)
	{
		if (root->right)
		{
			cout << root->data << ' ';
			rightBoundry(root->right);
		}
		else if (root->left)
		{
			cout << root->left << " ";
			rightBoundry(root->right);
		}
	}
}
void boundryPrint(node *root)
{
	cout << root->data << ' ';
	leftBoundry(root->left);
	printLeaf(root->left);
	printLeaf(root->right);
	rightBoundry(root->right);
}
void f(node *root)
{
	if (root)
	{
		cout << root->data;
		f(root->left);
		f(root->right);
	}
}
int main()
{
	node *root = NULL;
	ll v, e;
	cin >> v >> e;
	root = Insert(v, e);
	//f(root);
	boundryPrint(root);
	//cin >> v;
}
