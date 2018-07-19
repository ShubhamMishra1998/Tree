#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct node
{
	ll data;
	node *left, *right;
};
node *newnode(ll a)
{
	node *temp = new node();
	temp->data = a;
	temp->left = temp->right = NULL;
	return temp;
}
node *Insert(ll v, ll e)
{
	map<ll, node*> m1;
	node *root = NULL, *child, *parent;
	ll a, b;
	while (e--)
	{
		cin >> a >> b;
		if (m1.find(a) == m1.end())
		{
			parent = newnode(a);
			m1[a] = parent;
			if (root == NULL)
				root = parent;
		}
		else
			parent = m1[a];
		child = newnode(b);
		if (!parent->left)
			parent->left = child;
		else
			parent->right = child;
		m1[b] = child;
	}
	return root;
}
int f1(node *root1, node *root2)
{
	if (!root1 && !root2)
		return 1;
	if (!root1 || !root2)
		return 0;
	return (root1->data==root2->data&&f1(root1->left, root2->right) && f1(root1->right, root2->left));
}
void inorder(node *root)
{
	if (root == NULL)
		return;
	cout << root->data << ' ';
	inorder(root->left);
	inorder(root->right);
}
int main()
{
	ll t;
	cin >> t;
	while (t--)
	{
		ll v, e;
		cin >> v >> e;
		node *root1, *root2;
		root1 = Insert(v, e);
		root2 = Insert(v, e);
		inorder(root1);
		cout << '\n';
		inorder(root2);
		cout << f1(root1, root2) << '\n';
	}
}
