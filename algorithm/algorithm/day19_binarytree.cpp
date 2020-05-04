#include<iostream>

using namespace std;

int number = 15;

typedef struct node* treePointer;
typedef struct node {

	int data;
	treePointer leftchild, rightChild;
}node;

void preorder(treePointer ptr)
{
	if (ptr)
	{
		cout << ptr->data << ' ';
		preorder(ptr->leftchild);
		preorder(ptr->rightChild);
	}
}


void inorder(treePointer ptr)
{
	if (ptr)
	{
		preorder(ptr->leftchild);
		cout << ptr->data << ' ';
		preorder(ptr->rightChild);
	}
}

void postorder(treePointer ptr)
{
	if (ptr)
	{
		preorder(ptr->leftchild);
		preorder(ptr->rightChild);
		cout << ptr->data << ' ';
	}
}
int main()
{
	node nodes[16];
	for (int i = 1; i <= number; i++)
	{
		nodes[i].data = i;
		nodes[i].leftchild = NULL;
		nodes[i].rightChild = NULL;

	}
	for (int i = 1; i <= number; i++)
	{
		if (i % 2 == 0)
		{
			nodes[i / 2].leftchild = &nodes[i];

		}
		else
			nodes[i / 2].rightChild = &nodes[i];
	}
	preorder(&nodes[1]);
	return 0;

}