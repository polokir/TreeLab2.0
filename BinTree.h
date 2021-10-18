#include <iostream>
#include"Equality.h"

using namespace std;

template <typename T>
class BinaryTree
{

public:
	BinaryTree(T v);
	~BinaryTree();
	void add(T val);
	void printPreOrder();
	void printInOrder();
	void printPostOrder();
	int size();
	bool lookup(T val);
	void delete_by_value(T v);

protected:
	
    class Node {
	public:
		T value;
		Node* right;
		Node* left;
		Node(T val) {
			this->value = val;
			right = left = nullptr;
		}
	};
	Node* root;
	int treeSize;
	void add(Node* node, T val);
	bool lookup(Node* node, T val);
	void printPreOrder(Node* node);
	void printInOrder(Node* node);
	void printPostOrder(Node* node);
	void deleteTree(Node* node);
	Node* getparent(Node* tree, Node* cur) {
		if (cur->value != tree->value) {
			if (cur->value <= tree->value) {
				Node* parent = getparent(tree->left, cur);
				if (parent)
					return parent;
			}
			else if (tree->value <= cur->value) {
				Node* parent = getparent(tree->right, cur);
				if (parent)
					return parent;
				return tree;
			}
		}
		else return nullptr;
	}
};

template <typename T>
BinaryTree<T>::BinaryTree(T v) {
	root = new Node(v);
	treeSize++;
}

template <typename T>
BinaryTree<T>::~BinaryTree() {
	deleteTree(this->root);
}

template <typename T>
int BinaryTree<T>::size() {
	return this->treeSize;
}

template <typename T>
void BinaryTree<T>::add(T val) {
	add(root, val);
}

template <typename T>
void BinaryTree<T>::add(Node* node, T val) {

	int   cmd;
	while (true) {
		if ((node->left != nullptr) && (node->right != nullptr)) {
			cout << "Choose node to add info" << endl;
			cout << "Press 1 to add left node" << endl;
			cout << "Press 2 to add right node" << endl;
			cin >> cmd;
			switch (cmd) {
			case 1:
				node = node->left;
				break;
			case 2:
				node = node->right;
				break;
			default:
				cout << "ERROR" << endl;
			}
		}
		else {
			if ((node->left == nullptr) && (node->right != nullptr)) {
				cout << "Choose node to add info" << endl;
				cout << "Press 1 to add left-node" << endl;
				cout << "Press 2 to add right node" << endl;
				cin >> cmd;
				switch (cmd) {
				case 1:
					node->left = new Node(val);
					return;
				case 2:
					node = node->right;
					break;
				default:
					cout << "ERROR" << endl;
					break;
				}
			}
			else if ((node->left != nullptr) && (node->right == nullptr)) {
				cout << "Choose node to add info" << endl;
				cout << "Press 1 to add left-node" << endl;
				cout << "Press 2 to add right node" << endl;
				cin >> cmd;
				switch (cmd) {
				case 2:
					node->right = new Node(val);
					return;
				case 1:
					node = node->left;
					break;
				default:
					cout << "ERROR" << endl;
					break;
				}
			}
			else {
				cout << "Choose node to add info" << endl;
				cout << "Press 1 to add left-node" << endl;
				cout << "Press 2 to add right node" << endl;
				cin >> cmd;
				switch (cmd) {
				case 1:
					node->left = new Node(val);
					return;
				case 2:
					node->right = new Node(val);
					return;
				default:
					cout << "ERROR" << endl;
					break;
				}

			}
		}
	}
}

template <typename T>
void BinaryTree<T>::printInOrder() {
	printInOrder(this->root);
	cout << std::endl;
}

template <typename T>
void BinaryTree<T>::printInOrder( Node* node) {
	if (node != NULL) {
		printInOrder(node->left);
		cout << node->value << " | ";
		printInOrder(node->right);
	}
}

template <typename T>
void BinaryTree<T>::printPreOrder() {
	printPreOrder(this->root);
	cout << endl;
}

template <typename T>
void BinaryTree<T>::printPreOrder( Node* node) {
	if (node != NULL) {
		std::cout << node->value << " | ";
		printInOrder(node->left);
		printInOrder(node->right);
	}
}

template <typename T>
void BinaryTree<T>::printPostOrder() {
	printPostOrder(this->root);
	std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::printPostOrder( Node* node) {
	if (node != NULL) {
		printInOrder(node->left);
		printInOrder(node->right);
		std::cout << node->value << " | ";
	}
}


template <typename T>
void BinaryTree<T>::deleteTree( Node* node) {
	if (node != NULL) {
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}
}

template <typename T>
bool BinaryTree<T>::lookup(T val) {
	return lookup(this->root, val);
}

template <typename T>
bool BinaryTree<T>::lookup( Node* node, T val) {
	if (node == NULL) {
		return false;
	}
	else {
		if (val == node->value) {
			return true;
		}

		if (val > node->value) {
			return lookup(node->right, val);
		}
		else {
			return lookup(node->left, val);
		}
	}

}

template <typename T>
void BinaryTree<T>::delete_by_value(T val) {
	Node* current = root;
	Node* parent = getparent(root, current);
	if (current->left == nullptr && current->right == nullptr) {
		if (current->value == val) {
			if (parent->left == current)
				parent->left = nullptr;
			else
				parent->right = nullptr;
		}
		else return;
	}
	else if (current->left == nullptr || current->right == nullptr) {
		if (current->value == val) {
		if (current->left == nullptr) {
			if (parent->left = current) {
				parent->left = current->left;
				current = parent->left;
			}
			else {
				parent->right = current->left;
				current = parent->right;
			}
		}
		else {
			if (parent->left = current) {
				parent->left = current->right;
				current = parent->left;
			}
			else {
				parent->right = current->right;
				current = parent->right;
			}
		}
		}
		else {

		}
	}
}


template <typename T1>
class BinaryTreeSearch::public BinaryTree<T>
{

public:


protected:


};