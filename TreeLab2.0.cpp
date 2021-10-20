#include <iostream>
#include<vector>

#include "BinTree.h"



using namespace std;

int main(){
    BinaryTree<int>tree(1);
    tree.add(2);
    tree.add(3);
    tree.add(4);
    tree.add(5);
    tree.add(6);
    tree.add(7);

 

    tree.printPostOrder();
    tree.printInOrder();
    tree.printPreOrder();


    cout << "Tree size: " << tree.size() << std::endl;
    }

