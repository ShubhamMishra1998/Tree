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
void f1(node *root)
{
	if (root)
	{
		f1(root->left);
		cout << root->data << ' ';
		f1(root->right);
	}
}
void Preorder(node *root)
{
	stack<node*> s1;
	while (1)
	{
		while (root)
		{
			s1.push(root);
			root = root->left;
		}
		if (s1.empty())
			break;
		root = s1.top();
		cout << root->data << " ";
		s1.pop();
		root = root->right;
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
	f1(root);
	cout << '\n';
	Preorder(root);
}
