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

void levelorder(node *root)
{
	queue<node*> q1;
	if (root == NULL)
		return;
	q1.push(root);
	while (!q1.empty())
	{
		root = q1.front();
		q1.pop();
		cout << root->data << ' ';
		if (root->left)
			q1.push(root->left);
		if (root->right)
			q1.push(root->right);
	}
}
int main()
{
	node *root = NULL;
	root = Insert(root, 15);
	root = Insert(root, 13);
	root = Insert(root, 19);
	root = Insert(root, 10);
	root = Insert(root, 14);
	root = Insert(root, 18);
	root = Insert(root, 21);
	cout << '\n';
	levelorder(root);
}
