#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct node
{
	ll data;
	node *left, *right;
	ll height;
};
node *newNode(ll x)
{
	node *temp = new node();
	temp->data = x;
	temp->left = temp->right = NULL;
	temp->height = 1;
	return temp;
}
ll getHeight(node *root)
{
	if (!root)
		return 0;
	return root->height;
}
ll getBalance(node *root)
{
	if (!root)
		return 0;
	return getHeight(root->left) - getHeight(root->right);
}
node *leftRotate(node *x)
{
	node *y = x->right;
	node *t2 = y->left;
	y->left = x;
	x->right = t2;
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	return y;
}
node *rightRotate(node *x)
{
	node *y = x->left;
	node *t2 = y->right;
	y->right = x;
	x->left = t2;
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	return y;
}
node *Insert(node *root, ll x)
{
	if (!root)
		return newNode(x);
	else if (x < root->data)
		root->left = Insert(root->left, x);
	else if (x > root->data)
		root->right = Insert(root->right, x);
	else
		return root;
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

	ll balance = getBalance(root);


	if (balance > 1 && x < root->left->data)
		return rightRotate(root);
	if (balance<-1 && x>root->right->data)
		return leftRotate(root);
	if (balance >1 && x > root->left->data)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	if (balance <-1 && x < root->right->data)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}
void preorder(node *root)
{
	if (root)
	{
		cout << root->data << ' ';
		preorder(root->left);
		preorder(root->right);
	}
}
int main()
{
	node *root = NULL;
	ll a, n;
	cin >> n;
	for (ll i = 0; i < n; i++)
	{
		cin >> a;
		root = Insert(root, a);
	}
	preorder(root);
	//cin >> a;
}
