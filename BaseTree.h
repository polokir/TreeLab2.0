#pragma once
template<typename T>class BaseTree {
public:
	virtual void add(T val)=0;
	virtual void printPreOrder()=0;
	virtual void printInOrder()=0;
	virtual void printPostOrder()=0;
	virtual void delete_by_value() = 0;

};