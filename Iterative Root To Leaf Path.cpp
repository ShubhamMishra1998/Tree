#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct node
{
	ll data;
	node *left, *right;
};
node *Insert(node *root,ll x)
{
	if (root == NULL)
	{
		root = new node();
		root->data = x;
		root->left = root->right = NULL;
	}
	else if (x <= root->data)
		root->left = Insert(root->left, x);
	else
		root->right = Insert(root->right, x);
	return root;
}
void print(ll s, map<ll, ll> m1)
{
	stack<ll> s1;
	while (s)
	{
		s1.push(s);
		s = m1[s];
	}
	while (!s1.empty())
	{
		cout << s1.top() << ' ';
		s1.pop();
	}
	cout << '\n';
}

void f1(node *root)
{
	if (root == NULL)
		return;
	map<ll, ll> parent;
	stack<node*> s1;
	s1.push(root);
	parent[root->data] = 0;
	while (!s1.empty())
	{
		node *current = s1.top();
		s1.pop();
		if (!current->left && !current->right)
			print(current->data, parent);
		if (current->right)
		{
			s1.push(current->right);
			parent[current->right->data] = current->data;
		}
		if (current->left)
		{
			s1.push(current->left);
			parent[current->left->data] = current->data;
		}
	}
}
int main()
{
	node *root1 = NULL;
	root1 = Insert(root1, 15);
	root1 = Insert(root1, 13);
	root1 = Insert(root1, 20);
	root1 = Insert(root1, 10);
	root1 = Insert(root1, 14);
	root1 = Insert(root1, 19);
	root1 = Insert(root1, 21);
	root1 = Insert(root1, 11);
	f1(root1);
}
