#include <iostream>
#include <vector>
using namespace std;
template<typename T>
class Tree {
private:

	class Node {
	public:
		T data;
		vector<Node*> leaves;
		Node(T data) {
			this->data = data;
		}
	};
	int count;
	Node* root;
public:
	Tree(T val);
	~Tree();
	Node* getRoot() {
		return root;
	}
	void append(float memory, int day, int hour, int minute);
	void setId(Node* current);
	void outputTree(Node* current,int tmp=0);
	void defaultOutput();
	void deleteTree(Node* current);
	//void printNode(Node* current);
	void deleteNodeByIndex(int index);
	void preord(Node* tree);
	void postord(Node* cur);

	


};

template <typename T>
Tree<T>::Tree(T val) {
	root = new Node(val);
	count++;
	Tree::setId(root);
}
template <typename T>
Tree<T>::Tree::~Tree() {
	deleteTree(root);
}

template <typename T>
void Tree<T>::outputTree(Node* current,int tmp) {
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

template <typename T>
void Tree<T>::defaultOutput() {
	outputTree(root);
}

template <typename T>
void Tree<T>::append(float memory, int day, int hour, int minute) {
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
		cout << "\enter\"-1\"\n";
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

template <typename T>
void Tree<T>::deleteTree(Tree::Node* current) {
	for (auto& leaf : current->leaves)
		deleteTree(leaf);
	cout << "Node " << current << " is deleted" << endl;
	delete current;
}

template <typename T>
void Tree<T>::setId(Tree::Node* current) {
	current->ID = count;
}

template <typename T>
void Tree<T>::deleteNodeByIndex(int index) {
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

template <typename T>
void Tree<T>::preord(Node* current) {
	int len = current->leaves.size();
	if (current) {
		cout << "[" << current->ID << "]:" << current->memory << "  " << current->day << " " << current->hour << " " << current->minute << endl;
		for (int i = 0; i < len; ++i)
			preord(current->leaves[i]);
	}
}

template <typename T>
void Tree<T>::postord(Node* current) {
	int len = current->leaves.size();
	if (current) {
		for (int i = 0; i < len; ++i)
			postord(current->leaves[i]);
		cout << "[" << current->ID << "]:" << current->memory << "  " << current->day << " " << current->hour << " " << current->minute << endl;
	}
}