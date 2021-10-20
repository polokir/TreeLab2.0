#include <iostream>
#include "BinTree.h"

using namespace std;


template <typename T1>
class BinaryTreeSearch
{

public:
	BinaryTreeSearch(T val) {
		root = new Node(T val);
		treeSize++;
	}
	void append(T1 val);
	void deleteNodeByValue(T1 val);
	void searchNodeByValue(T1 val);
    void printPreOrder();
    void printInOrder();
    void printPostOrder();
	

protected:
	class Node {
	public:
		T1 data;
		Node* right;
		Node* left;
		Node(T1 data) {
			this->data = data;
			right = left = nullptr;
		}
	};
	Node* root;
    void printPreOrder(Node*node);
    void printInOrder(Node*node);
    void printPostOrder(Node*node);
};

template<typename T1>
inline void BinaryTreeSearch<T1>::append(T1 val)
{
    Node* current = root;
    while (true) {
        if (current->data>=val) {
            if (current->left != nullptr) {
                current = current->left;
            }
            else {         
                current->left = new Node(val);
                treeSize++;
                return;
            }
        }
        else {
            if (current->right != nullptr) {
                current = current->right;

            }
            else {              
                current->right = new Node(val);
                treeSize++;
                return;
            }
        }
    }
}

template<typename T1>
inline void BinaryTreeSearch<T1>::deleteNodeByValue(T1 val)
{
    Node* current = root;
    Node* parent = getParent(root, current);

    if (current->left == nullptr && current->right == nullptr) { // Если потомки отсутствуют
        if (current->data!=val)
            return;
        else {
            if (parent->left == current) {
                parent->left = nullptr;
                return;
            }
            else if (parent->right == current) {
                parent->right = nullptr;
                return;
            }
        }
    }
    else if (current->left == nullptr || current->right == nullptr) { // 1 потомок
        if (current->data == val) {
            if (current->left == nullptr) {
                if (parent->left == nullptr)
                    parent->left = current->right;
                else
                    parent->right = current->right;
            }
            else {
                if (parent->left == current)
                    parent->left = current->left;
                else
                    parent->right = current->left;
            }
        }
        else {
            if (current->left == nullptr) {
                if (current->data <= val)
                    current = current->right;
                else return;
            }
            else if (current->right == nullptr) {
                if (current->data == val)
                    current = current->left;
                else return;
            }
        }
    }
    else { // 2 потомка
        while (true) {
            parent = getParent(root, current);
            Node* temp = current->left;
            if (parent != nullptr) {
                if ((current->left == nullptr && current->right == nullptr) && current->data != val)
                    return;
                else if (current->data == val) {
                    if (parent->left == current) {
                        parent->left = temp;
                    }
                    else {
                        parent->right = temp;
                    }
                    while (temp->right)
                        temp = temp->right;
                    temp->right = current->right;
                    current = temp;
                }
                else if (current->data!=val) {
                    if (current->left != nullptr && current->right != nullptr) {
                        if (current->data == val)
                            current = current->right;
                        else current = current->left;
                    }
                    else if (current->left != nullptr) {
                        current = current->left;
                    }
                    else {
                        current = current->right;
                    }
                }
            }
            else {
                if (current->data != val) {
                    if (current->data >= val && current->left != nullptr)
                        current = current->left;
                    else if (current->data =< val && current->right != nullptr)
                        current = current->right;
                }
            }
        }
    }
}

template<typename T1>
inline void BinaryTreeSearch<T1>::searchNodeByValue(T1 val)
{
	Node* current = root;
	while (true) {
		if (current->data>=val) {
			if (current->data == val) {
				cout << "Nodeis searched" << endl;
			}
			else
				if (current->left != nullptr)
					current = current->left;
				else {
					cout << "Can't search nothing more." <<endl;
					return;
				}
		}
		else {
			if (current->right != nullptr)
				current = current->right;
			else {
				cout << "Can't search nothing more." << endl;
				return;
			}
		}
	}
}

template <typename T>
void BinaryTreeSearch<T>::printInOrder() {
    printInOrder(this->root);
    cout << endl;
}

template <typename T>
void BinaryTreeSearch<T>::printInOrder(Node* node) {
    if (node != NULL) {
        printInOrder(node->left);
        cout << node->value << " | ";
        printInOrder(node->right);
    }
}

template <typename T>
void BinaryTreeSearch<T>::printPreOrder() {
    printPreOrder(this->root);
    cout << endl;
}

template <typename T>
void BinaryTreeSearch<T>::printPreOrder(Node* node) {
    if (node != NULL) {
        cout << node->value << " | ";
        printInOrder(node->left);
        printInOrder(node->right);
    }
}

template <typename T>
void BinaryTreeSearch<T>::printPostOrder() {
    printPostOrder(this->root);
    cout << endl;
}

template <typename T>
void BinaryTreeSearch<T>::printPostOrder(Node* node) {
    if (node != NULL) {
        printInOrder(node->left);
        printInOrder(node->right);
        cout << node->value << " | ";
    }
}