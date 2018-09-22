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
	vector<ll> v1;
	queue<node*> q1;
	map<ll, vector<ll> > hashvertical;
	map<ll, ll> parent;
	hashvertical[0].push_back(root->data);
	parent[root->data] = 0;
	q1.push(root);
	while (!q1.empty())
	{
		node *temp = q1.front();
		q1.pop();
		v1.push_back(temp->data);
		if (temp->left)
		{
			q1.push(temp->left);
			ll c = parent[temp->data];
			hashvertical[c - 1].push_back(temp->left->data);
			parent[temp->left->data] = c - 1;
		}
		if (temp->right)
		{
			q1.push(temp->right);
			ll c = parent[temp->data];
			hashvertical[c+1].push_back(temp->right->data);
			parent[temp->right->data] = c + 1;
		}
	}
	//vector<ll> v2;
	map<ll, ll> m2;
	for (auto it = hashvertical.begin(); it != hashvertical.end(); it++)
	{
		for (ll i = 0; i < it->second.size(); i++)
		{
			//v2.push_back(it->second[0]);
			m2[it->second[0]] = 1;
			break;
		}
	}
	for (ll i = 0; i < v1.size(); i++)
	{
		if (m2[v1[i]])
			cout << v1[i] << ' ';

	}
}
int main()
{
	node *root = NULL;
	ll v, e;
	cin >> v >> e;
	root=Insert(v, e);
    levelOrder(root);
	//cin >> v;
}
