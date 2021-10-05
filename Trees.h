#include <iostream>
#include <vector>
using namespace std;
class Tree {
private:

	class Node {
	public:
		int ID;
		float memory;
		int day;
		int hour;
		int minute;
		vector<Node*> leaves;
		Node(float memory, int day, int hour, int minute);
	};
	int count;
	Node* root;
public:
	Tree(float memory, int day, int hour, int minute);
	~Tree();
	Node* getRoot();
	void append(float memory, int day, int hour, int minute);
	void setId(Node* current);
	void outputTree(Node* current,int tmp=0);
	void defaultOutput();
	Node* deleteNode();
	void deleteTree(Node* current);

	void printNode(Node* current);
	void deleteNodeByIndex(int index);
	void preord(Node* tree);
	void postord(Node* cur);

	Node* getParent(Node* current);


};
Tree::Node::Node(float memory, int day, int hour, int minute) {
	this->memory = memory;
	this->day = day;
	this->hour = hour;
	this->minute = minute;
	

}

Tree::Tree(float memory, int day, int hour, int minute) {
	root = new Node(memory, day, hour, minute);
	count++;
	Tree::setId(root);
}

Tree::~Tree() {
	deleteTree(root);
}

Tree::Node* Tree::getRoot() {
	return root;
}

void Tree::outputTree(Node* current,int tmp) {
	cout << "[" << current->ID << "]:" << current->memory << "  " << current->day << " " << current->hour << " " << current->minute << endl;
	tmp++;
	int len = current->leaves.size();
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < tmp; j++)
			cout << '\t';
		cout << i << ". ";
		outputTree(current->leaves[i]);
	}
}

void Tree::defaultOutput() {
	outputTree(root);
}

void Tree::append(float memory, int day, int hour, int minute) {
	Tree::Node* current = root;
	int tmp;
	if (root->leaves.empty()) {
		Node* newNode = new Node(memory, day, hour, minute);
		count++;
		Tree::setId(newNode);
		root->leaves.push_back(newNode);
		cout << "Tree was empty, node is added to root" << endl;
		return;
	}
	while (true) {
		Tree::outputTree(current);
		if (current->leaves.empty()) {
			Node* newNode = new Node(memory, day, hour, minute);
			count++;
			Tree::setId(newNode);
			current->leaves.push_back(newNode);
			return;
		}
		cout << "\nChoose the leap or enter\"-1\"\n";
		cin >> tmp;
		if (tmp == -1) {
			Node* newNode = new Node(memory, day, hour, minute);
			count++;
			Tree::setId(newNode);
			current->leaves.push_back(newNode);
			return;
		}
		else
			current = current->leaves[tmp];
	}
}

Tree::Node* Tree::deleteNode() {
	Node* current = root;
	Node* previous = root;
	int tmp = -1, act;

	if (root->leaves.empty()) {
		cout << "There is no leaves..." << endl;
		return nullptr;
	}

	while (true) {
		Tree::outputTree(current);
		if (current->leaves.empty()) {
			cout << "That node hasn't got leaves." << endl;
			previous->leaves.erase(previous->leaves.begin() + tmp);
			cout << "Node " << current << " is deleted" << endl;
			return current;
		}

		cout << "Free leaves: ";
		for (int i = 0; i < current->leaves.size(); i++)
			cout << i << ' ';
		cout << "\nChoose the leafe or press \"-1\"\n";
		cin >> act;
		if (act == -1) {
			if (tmp == -1) {
				cout << "You can't delete root" << endl;
				continue;
			}
			previous->leaves.erase(previous->leaves.begin() + tmp);
			cout << "Node " << current << " is deleted" << endl;
			return current;

		}
		else {
			tmp = act;
			previous = current;
			current = current->leaves[tmp];
		}
	}
}

void Tree::deleteTree(Tree::Node* current) {
	for (auto& leaf : current->leaves)
		deleteTree(leaf);
	cout << "Node " << current << " is deleted" << endl;
	delete current;
}

void Tree::setId(Tree::Node* current) {
	current->ID = count;
}

void Tree::deleteNodeByIndex(int index) {
	Node* current = root;
	for (int i = 0; i < current->leaves.size(); i++) {
		if (current->leaves[i]->ID == index) {
			cout << "Node " << current->leaves[i] << " is deleted." << endl;
			current = current->leaves[i];
			while (true) {
				if (current->leaves.size() == 0) {
					current = nullptr;
					return;
				}
				else {
					for (int i = 0; i < current->leaves.size(); i++) {
						current->leaves[i] = nullptr;
					}
				}
			}
		}
	}
}

Tree::Node* Tree::getParent(Node* current) {
	return nullptr;
}

void Tree::preord(Node* current) {
	int len = current->leaves.size();
	if (current) {
		cout << "[" << current->ID << "]:" << current->memory << "  " << current->day << " " << current->hour << " " << current->minute << endl;
		for (int i = 0; i < len; ++i)
			preord(current->leaves[i]);
	}
}

void Tree::postord(Node* current) {
	int len = current->leaves.size();
	if (current) {
		for (int i = 0; i < len; ++i)
			postord(current->leaves[i]);
		cout << "[" << current->ID << "]:" << current->memory << "  " << current->day << " " << current->hour << " " << current->minute << endl;
	}
}