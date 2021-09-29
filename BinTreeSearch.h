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
	void SetID(Node* cur);
	void push(float memory, int day, int hour, int minute);
	void output(Node* cur);
	void output1();
	void SearchByValue(float memory, int day, int hour, int minute);
	void printNode(Node* cur);
	Node* deleteNode();
	Node* getParent(Node* tree1, Node* tree2);
	bool checkVal(Node* cur, float memory, int day, int hour, int minute);
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

void BinTreeSearch::SetID(Node* cur) {
	cur->index = count;
}

bool BinTree