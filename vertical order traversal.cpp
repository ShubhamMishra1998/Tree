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
void levelOrder(node *root)
{
	if (!root)
		return;
	map<ll, ll> parent;
	map<ll, vector<ll> > hash;
	hash[0].push_back(root->data);
	parent[root->data] = 0;
	queue<node*> q1;
	q1.push(root);
	while (!q1.empty())
	{
		node *temp = q1.front();
		q1.pop();
		if (temp->left)
		{
			q1.push(temp->left);
			ll h = parent[temp->data];
			parent[temp->left->data] = h - 1;
			hash[parent[temp->left->data]].push_back(temp->left->data);
		}
		if (temp->right)
		{
			q1.push(temp->right);
			ll h = parent[temp->data];
			parent[temp->right->data] = h + 1;
			hash[parent[temp->right->data]].push_back(temp->right->data);
		}
	}
	for (auto it = parent.begin(); it != parent.end(); it++)
		cout << it->first << ' ' << it->second << '\n';
	for (auto it = hash.begin(); it != hash.end(); it++)
	{
		for (ll i = 0; i < it->second.size(); i++)
			cout << it->second[i] << ' ';
		cout << '\n';
	}
}
int main()
{
	node *root;
	ll v, e;
	cin >> v >> e;
	root = Insert(v, e);
	levelOrder(root);
}
