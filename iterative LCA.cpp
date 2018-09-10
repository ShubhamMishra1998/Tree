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
ll LCA(map<ll, ll> parent, ll a, ll b)
{
	map<ll, bool> hash;
	while (a)
	{
		hash[a] = true;
		a = parent[a];
	}
	while (b)
	{
		if (hash.find(b) != hash.end())
			return b;
		b = parent[b];
	}
}
void bfs(node *root,ll a,ll b)
{
	map<ll, ll> parent;
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
			parent[temp->left->data] = temp->data;
		}
		if (temp->right)
		{
			q1.push(temp->right);
			parent[temp->right->data] = temp->data;
		}
	}
	ll l=LCA(parent, a, b);
	cout << l << ' ';
}
int main()
{
	node *root = NULL;
	ll v, e, a, b;
	cin >> v >> e;
	root = Insert(v,e);
	cout << '\n';
	cin >> a >> b;
	bfs(root, a, b);
	//cin >> a;
}
