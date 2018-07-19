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
	cout << root->data << ' ';
	vector<ll> v1;
	queue<node*> q1;
	q1.push(root);
	ll c = 0, s = 0;
	while (!q1.empty())
	{
		s = q1.size();
		if (c % 2 && c != 0)
		{
			for (ll i = v1.size() - 1; i >= 0; i--)
				cout << v1[i] << ' ';
		}
		else if(c%2==0&&c!=0)
		{
			for (ll i = 0; i < v1.size(); i++)
				cout << v1[i] << ' ';
		}
		v1.resize(0);
		c++;
		while (s--)
		{
			node *temp = q1.front();
			q1.pop();
			if (temp->left)
			{
				q1.push(temp->left);
				v1.push_back(temp->left->data);
			}
			if (temp->right)
			{
				q1.push(temp->right);
				v1.push_back(temp->right->data);
			}
		}
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
