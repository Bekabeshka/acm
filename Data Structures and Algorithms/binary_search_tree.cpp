#include <iostream>
using namespace std;

struct node {
	int value;
	struct node *left, *right;
};

void print(struct node *root)
{
	if (root != NULL)
	{
		print(root->left);
		cout << root->value << " ";
		print(root->right);
	}
}

struct node* insert(struct node* top, int value) {
	if (top == NULL) {
		top = new node();
		top->value = value;
		top->left = NULL;
		top->right = NULL;
		return top;
	}
	else if (top->value > value) {
		top->left = insert(top->left, value);
	}
	else {
		top->right = insert(top->right, value);
	}
	return top;
}

struct node* minValueNode(struct node* node)
{
	struct node* current = node;
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}

struct node* deleteNode(struct node* root, int value) {
	
	if (root == NULL) {
		return root;
	}

	if (value < root->value)
		root->left = deleteNode(root->left, value);
	else if (value > root->value)
		root->right = deleteNode(root->right, value);
	else {
		
		if (root->left == NULL) {
			return root->right;
		} else if (root->right == NULL) {
			return root->left;
		}
		struct node* temp = minValueNode(root->right);

		root->value = temp->value;

		root->right = deleteNode(root->right, temp->value);
	}
	return root;
}

int main() {

	struct node *root = NULL;
	root = insert(root, 50);
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 40);
	root = insert(root, 70);
	root = insert(root, 60);
	root = insert(root, 80);

	print(root);
	cout << endl;

	root = deleteNode(root, 20);
	print(root);

	return 0;
}