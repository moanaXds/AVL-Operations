//#include<iostream>
//
//using namespace std;
//
//
//class Node {
//public:
//	Node* left;
//	Node* right;
//	int data;
//	int height;
//	int size;
//
//	Node(int val)
//	{
//		left = right = NULL;
//		data = val;
//		height = 1;
//		size = 1;
//	}
//};
//
//class AVL {
//public:
//
//	int getHeight(Node* root)
//	{
//		if (root == NULL)return 0;
//
//		return root->height;
//	}
//
//	int getSize(Node* root)
//	{
//		if (root == NULL)return 0;
//
//		return root->size;
//	}
//
//	int getBalance(Node* root)
//	{
//		if (root == NULL)return 0;
//
//		return (getHeight(root->left) - getHeight(root->right));
//	}
//
//	Node* RotateLeft(Node* root)
//	{
//		Node* y = root->right;
//		Node* x = y->left;
//
//		y->left = root;
//		root->right = x;
//
//		root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
//		y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
//
//		root->size = 1 + getSize(root->left) + getSize(root->right);
//		y->size = 1 + getSize(y->left) + getSize(y->right);
//
//
//		return y;
//	}
//
//	Node* RotateRight(Node* root)
//	{
//		Node* y = root->left;
//		Node* x = y->right;
//
//		y->right = root;
//		root->left = x;
//
//		root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
//		y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
//
//		root->size = 1 + getSize(root->left) + getSize(root->right);
//		y->size = 1 + getSize(y->left) + getSize(y->right);
//
//
//		return y;
//	}
//
//	Node* insertion(Node* root, int val)
//	{
//		if (root == NULL)
//		{
//			return new Node(val);
//		}
//
//		if (val < root->data)
//		{
//			root->left = insertion(root->left, val);
//
//		}
//		if (val > root->data)
//		{
//			root->right = insertion(root->right, val);
//
//		}
//
//		root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
//		root->size = 1 + getSize(root->left) + getSize(root->right);
//
//		int balance = getBalance(root);
//
//		// l
//
//		if (balance > 1 && getBalance(root->left) > 0)
//		{
//			return RotateRight(root);
//		}
//
//		// lr
//		if (balance > 1 && getBalance(root->left) < 0)
//		{
//			root->left = RotateLeft(root->left);
//
//			return RotateRight(root);
//		}
//
//		// R
//
//		if (balance < -1 && getBalance(root->right) > 0)
//		{
//			return RotateLeft(root);
//		}
//
//		// rl
//
//		if (balance < -1 && getBalance(root->right) < 0)
//		{
//			root->right = RotateRight(root->right);
//			return RotateLeft(root);
//		}
//
//		return root;
//	}
//
//	int COUNTinRANGE(Node* root, int  l, int r)
//	{
//		if (root == NULL)return 0;
//		
//		if (root->data >= l && root->data <= r)     // if current node is b/w l and r 
//		{
//			return 1+ COUNTinRANGE(root->left, l, r)+ COUNTinRANGE(root->right, l, r);  // +1 for node itself
//		}
//
//		if (root->data < l)
//		{
//			return COUNTinRANGE(root->right, l, r);  // if root<l than it left subtree wil also
//		}
//		else
//		{
//			return COUNTinRANGE(root->left, l, r);  // if root>r than it right subtree wil also
//		}
//	}
//};
//
//int main() {
//	AVL tree;
//	Node* root = NULL;
//
//	root = tree.insertion(root, 10);
//	root = tree.insertion(root, 5);
//	root = tree.insertion(root, 15);
//	root = tree.insertion(root, 3);
//	root = tree.insertion(root, 7);
//	root = tree.insertion(root, 12);
//	root = tree.insertion(root, 18);
//
//	cout << "Input RANGES\n";
//	int l, r;
//	cout << "enter l ";
//	cin >> l;
//	cout << "enter r ";
//	cin >> r;
//	int result = tree.COUNTinRANGE(root, l, r);
//	cout << "RESULT :" << result<<endl;
//	return 0;
//}
