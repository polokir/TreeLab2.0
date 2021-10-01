#include <iostream>
#include <vector>
#include <string>
#define SIZE 10
using namespace std;


class BinTreeSearch
{
private:
	class Node {
	public:
		float memory;
		int day;
		int hour;
		int minute;
		int index;
		Node* left;
		Node* right;
		Node(float memory, int day, int hour, int minute);
	};
	Node* root;
	int count;
public:
	BinTreeSearch(float memory, int day, int hour, int minute);
	~BinTreeSearch();
	void SetID(Node* cur);
	void push_back(float memory, int day, int hour, int minute);
	//void output(Node* cur);
	//void output1(Node* Cur, int sp);
	void SearchByValue(float memory, int day, int hour, int minute);
	void printNode(Node* cur);
	Node* deleteNode();
	Node* getParent(Node* tree1, Node* tree2);
	bool check_val(Node* cur, float memory, int day, int hour, int minute);
	bool check_eql(Node* cur, float memory, int day, int hour, int minute);
	bool check_nodes(Node* tree1, Node* tree2);
	bool check_nodes_eql(Node* tree1, Node* tree2);

};

BinTreeSearch::Node::Node(float memory, int day, int hour, int minute) {
	this->memory = memory;
	this->day = day;
	this->hour = hour;
	this->minute = minute;
	right = left = nullptr;
}

BinTreeSearch::BinTreeSearch(float memory, int day, int hour, int minute) {
	root = new Node(memory, day, hour, minute);
	count++;
	SetID(root);
}

BinTreeSearch::~BinTreeSearch() {
	while (root != nullptr) {
		deleteNode();
	}
}

void BinTreeSearch::SetID(Node* cur) {
	cur->index = count;
}

void BinTreeSearch::printNode(Node* cur) {
	cout << cur->memory << " " << cur->day << " " << cur->hour << " " << cur->minute <<"[" << cur->index <<"]" << endl;
}

bool BinTreeSearch::check_val(Node* cur, float memory, int day, int hour, int minute) {
	if (cur->memory >= memory) {
		if (cur->day >= day) {
			if (cur->hour >= hour) {
				if (cur->minute >= minute) {
					return true;
				}
				else return false;
			}
			else return false;
		}
		else return false;
	}
	else return false;
}

bool BinTreeSearch::check_eql(Node* cur, float memory, int day, int hour, int minute) {
	if (cur->memory == memory) {
		if (cur->day == day) {
			if (cur->hour == hour) {
				if (cur->minute == minute) {
					return true;
				}
				else return false;
			}
			else return false;
		}
		else return false;
	}
	else return false;
}

bool BinTreeSearch::check_nodes(Node* tree1, Node* tree2) {
	if (tree1->memory <= tree2->memory) {
		if (tree1->day <= tree2->day) {
			if (tree1->hour <= tree2->hour) {
				if (tree1->minute <= tree2->minute) {
					return true;
				}
				else return false;
			}
			else return false;
		}
		else return false;
	}
	else return false;
}

bool BinTreeSearch::check_nodes_eql(Node* tree1, Node* tree2) {
	if (tree1->memory == tree2->memory) {
		if (tree1->day = tree2->day) {
			if (tree1->hour == tree2->hour) {
				if (tree1->minute == tree2->minute) {
					return true;
				}
				else return false;
			}
			else return false;
		}
		else return false;
	}
	else return false;
}

void BinTreeSearch::push_back(float memory, int day, int hour, int minute) {
	Node* cur = root;
	while (true) {
		if (check_val(cur, memory, day, hour, minute)) {
			if (cur->left != nullptr) {
				cur = cur->left;
			}

			else {
				count++;
				cur->left = new Node(memory, day, hour, minute);
				SetID(cur->left);
				return;
			}
		}
		else {
			if (cur->right != nullptr) {
				cur = cur->right;
			}
			else {
				count++;
				cur->right = new Node(memory, day, hour, minute);
				SetID(cur->right);
				return;
			}
		}
	}
}


BinTreeSearch::Node* BinTreeSearch::deleteNode() {
	Node* previous = root;
	Node* current = root;
	if ((root->left == nullptr) && (root->right == nullptr)) { 
		cout << "Root hasn't got leaves" << endl;
		root = nullptr;
		cout << "Tree with root " << current << " is deleted." << endl;
		return nullptr;
	}
	while (true) { 
		if (((current->left != nullptr) && (current->right == nullptr)) ||
			((current->left != nullptr) && (current->right != nullptr))) {
			previous = current;
			current = current->left;
		}
		else if ((current->left == nullptr) && (current->right != nullptr)) {
			previous = current;
			current = current->right;
		}
		else {
			cout << "Node " << current << " is deleted." << endl;
			if (previous->left == current)
				previous->left = nullptr;
			else
				previous->right = nullptr;
			current = nullptr;
			return nullptr;
		}
	}
}

BinTreeSearch::Node* BinTreeSearch::getParent(Node* tree, Node *cur) {
	if (!check_nodes_eql(cur, tree)) {
		if (check_nodes(cur, tree)) { 
			Node* parent = getParent(tree->left, cur); 
			if (parent)
				return parent;
			return tree;
		}
		else if (!check_nodes(cur, tree)) {
			Node* parent = getParent(tree->right, cur);
			if (parent)
				return parent;
			return tree;
		}
	}
	else return nullptr;
}

void BinTreeSearch::SearchByValue(float memory, int day, int hour, int minute) {
	Node* current = root;
	while (true) {
		if (check_val(current, memory, day, hour, minute)) {
			if (check_eql(current, memory, day, hour, minute)) {
				cout << "Node "; printNode(current); cout << " finded!" << endl;
			}
			else
				if (current->left != nullptr)
					current = current->left;
				else {
					cout << "Error" << endl;
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