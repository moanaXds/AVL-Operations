#include<iostream>

using namespace std;


class Node {
public:
	Node* left;
	Node* right;
	int data;
	int height;
	int size;

	Node(int val)
	{
		left = right = NULL;
		data = val;
		height = 1;
		size = 1;
	}
};

class AVL {
public:

	int getHeight(Node* root)
	{
		if (root == NULL)return 0;

		return root->height;
	}

	int getSize(Node* root)
	{
		if (root == NULL)return 0;

		return root->size;
	}

	int getBalance(Node* root)
	{
		if (root == NULL)return 0;

		return (getHeight(root->left) - getHeight(root->right));
	}

	Node* RotateLeft(Node* root)
	{
		Node* y = root->right;
		Node* x = y->left;

		y->left = root;
		root->right = x;

		root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
		y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

		root->size = 1 + getSize(root->left) + getSize(root->right);
		y->size = 1 + getSize(y->left) + getSize(y->right);


		return y;
	}

	Node* RotateRight(Node* root)
	{
		Node* y = root->left;
		Node* x = y->right;

		y->right = root;
		root->left = x;

		root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
		y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

		root->size = 1 + getSize(root->left) + getSize(root->right);
		y->size = 1 + getSize(y->left) + getSize(y->right);


		return y;
	}

	Node* insertion(Node* root, int val)
	{
		if (root == NULL)
		{
			return new Node(val);
		}
		
		if (val < root->data)
		{
			root->left = insertion(root->left, val);
		
		}
		if (val > root->data)
		{
			root->right = insertion(root->right, val);
		
		}

		root->height = max(getHeight(root->left), getHeight(root->right))+1;
		root->size = 1 + getSize(root->left) + getSize(root->right);

		int balance = getBalance(root);

		// l

		if (balance > 1 && getBalance(root->left) > 0)
		{
			return RotateRight(root);
		}

		// lr
		if (balance > 1 && getBalance(root->left) < 0)
		{
			root->left= RotateLeft(root->left);

			return RotateRight(root);
		}

		// R

		if (balance < -1 && getBalance(root->right) > 0)
		{
			return RotateLeft(root);
		}

		// rl

		if (balance < -1 && getBalance(root->right) < 0)
		{
			root->right= RotateRight(root->right);
			return RotateLeft(root);
		}

		return root;
	}
		
	Node* kthSmallest(Node* root, int k)
	{
		if (root == NULL)return NULL;

		int leftsize = getSize(root->left);

		if (k == leftsize + 1)return root;

		else if (k <= leftsize)
		{
			return kthSmallest(root->left,k);
		}
		else 
		{
			return kthSmallest(root->right, k -leftsize- 1);
		}
	}
};

int main() {
	AVL tree;
	Node* root = NULL;

	// Insert keys
	root = tree.insertion(root, 30);
	root = tree.insertion(root, 20);
	root = tree.insertion(root, 40);
	root = tree.insertion(root, 10);
	root = tree.insertion(root, 25);
	root = tree.insertion(root, 35);
	root = tree.insertion(root, 50);

	int k = 3; // 3rd smallest
	Node* kth = tree.kthSmallest(root, k);

	if (kth) cout << "The " << k << "rd smallest element is: " << kth->data << endl;

	return 0;
}
