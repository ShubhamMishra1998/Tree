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
ll height(node *root)
{
	if (root == NULL)
		return 0;
	ll h;
	ll left = height(root->left);
	ll right = height(root->right);
	if (left > right)
		h = left + 1;
	else
		h = right + 1;
	return h;
}
ll diameter(node *root)
{
	if (root == NULL)
		return 0;
	ll left = height(root->left);
	ll right = height(root->right);
	ll ld = diameter(root->left);
	ll rd = diameter(root->right);
	return max((left + right + 1), max(ld, rd));
}
int main()
{
	node *root1 = NULL;
	root1 = Insert(root1, 15);
	root1 = Insert(root1, 13);
	root1 = Insert(root1, 12);
	root1 = Insert(root1, 14);
	root1 = Insert(root1, 17);
	root1 = Insert(root1, 16);
	root1 = Insert(root1, 18);
	cout << diameter(root1);
}
