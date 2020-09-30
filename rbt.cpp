#include<iostream>
using namespace std;

struct node
{
	int data;
	char colour;
	node*left, *right, *parent;
};
node*root = NULL;
node*par = NULL;
class tree
{

public:
	void insert(int value, node*&n);
	void coloring(node* n);
	node* rotate_left(node*  p, node* q);
	node* rotate_right(node * p, node* q);
	void in_order(node* q);
	void pre_order(node*p);
	void post_order(node*p);
};
void tree::insert(int value, node*&n)
{
	if (n == NULL)
	{
		n = new node;
		n->data = value;
		n->left = NULL;
		n->right = NULL;
		n->colour = 'r';
		n->parent = par;
		coloring(n);
		cout << "inserted :" << value << endl;
	}
	else if (value<n->data)
	{
		par = n;
		insert(value, n->left);

	}
	else if (value > n->data)
	{
		par = n;
		insert(value, n->right);
	}
	else
		cout << "\nData exist" << endl;
}

void tree::coloring(node*n)
{
	if (n->parent == NULL)
	{
		n->colour = 'b';
	}
	else if (n->parent->colour == 'b')
	{
		return;
	}
	else
	{
		node*u, *d, *p;
		p = n->parent;
		d = n->parent->parent;
		if (p == d->left)
		{
			u = d->right;
		}
		else
		{
			u = d->left;
		}
		if (u != NULL&&u->colour == 'r')
		{
			p->colour = 'b';
			u->colour = 'b';
			d->colour = 'r';
			coloring(d);
		}
		else
		{
			if (n == p->right&&p == d->left)
			{
				p = rotate_left(p, n);
				n = n->left;
			}
			else if (n == p->left&&p == d->right)
			{
				p = rotate_right(p, n);
				n = n->right;
			}
			p = n->parent;//not required
			p->colour = 'b';
			d->colour = 'r';
			if (n == p->left)
				d = rotate_right(d, d->left);
			else
				d = rotate_left(d, d->right);
		}
	}
}
node*tree::rotate_right(node* p, node* q)
{
	node* r = p;
	p->left = q->right;
	if (q->right != NULL)
		q->right->parent = p;
	q->right = p;
	q->parent = p->parent;
	p->parent = q;
	if (q->parent != NULL)
	{
		if (q->data<q->parent->data)
			q->parent->left = q;
		else
			q->parent->right = q;
	}
	if (r == root)
		root = q;
	return q;
}

node*tree::rotate_left(node* p, node* q)
{
	node* r = p;
	p->right = q->left;
	if (q->left != NULL)
		q->left->parent = p;
	q->left = p;
	q->parent = p->parent;
	p->parent = q;
	if (q->parent != NULL)
	{
		if (q->data<q->parent->data)
			q->parent->left = q;
		else
			q->parent->right = q;
	}
	if (r == root)
		root = q;
	return q;
}
void tree::in_order(node*q)
{

	if (q != NULL)
	{
		in_order(q->left);
		cout << endl << q->data << " " << q->colour;
		in_order(q->right);
	}


}
void tree::pre_order(node*q)
{
	if (q != NULL)
	{
		cout << q->data << " " << q->colour << endl;
		pre_order(q->left);
		pre_order(q->right);
	}
}

void tree::post_order(node*q)
{
	if (q != NULL)
	{
		pre_order(q->left);
		pre_order(q->right);
		cout << q->data << " " << q->colour << endl;
	}
}

int main()
{
	int op = 0;
	tree a;
	a.insert(10, root);
	a.insert(20, root);
	a.insert(30, root);
	a.insert(40, root);
	a.insert(50, root);
	a.insert(60, root);
	a.insert(70, root);
	a.insert(80, root);
	a.insert(90, root);
	a.insert(100, root);
	a.insert(110, root);
	a.insert(120, root);
	a.insert(15, root);
	a.insert(13, root);
	a.insert(115, root);
	a.insert(5, root);
	a.insert(6, root);
	cout << endl;
	cout << "Root is : " << root->data << endl;
	while (true)
	{
		cout << "Enter option :" << endl;
		cout << "1 : pre order\n2 : post order\n3 : in order\n4 : Exit" << endl;
		cin >> op;
		if (op == 1)
		{
			cout << "Pre order :" << endl;
			a.pre_order(root);
		}
		else if (op == 2)
		{
			cout << "post order :" << endl;
			a.post_order(root);
		}
		else if (op == 3)
		{
			cout << "in order :" << endl;
			a.in_order(root);
		}
		else{
			break;
		}
	}



	return 0;
}
