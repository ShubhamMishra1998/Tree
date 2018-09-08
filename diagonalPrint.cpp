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
void diagonalPrintUtil(node *root, map<ll, vector<ll> > &hash, ll d)
{
	if (!root)
		return;
	hash[d].push_back(root->data);
	diagonalPrintUtil(root->left, hash, d + 1);
	diagonalPrintUtil(root->right, hash, d);
}
void diagonalPrint(node *root)
{
	map<ll, vector<ll> > hash;
	diagonalPrintUtil(root, hash, 0);
	for (auto it = hash.begin(); it!=hash.end(); it++)
	{
		for (ll i = 0; i < it->second.size(); i++)
			cout << it->second[i] << " ";
		cout << '\n';
	}

}
int main()
{
	node *root = NULL;
	ll v, e;
	cin >> v;
	root = Insert(v, v - 1);
	diagonalPrint(root);
}
