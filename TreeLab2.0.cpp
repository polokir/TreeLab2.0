#include <iostream>
#include<vector>

//#include"BinTreeSearch.h"
//#include"Trees.h"
#include "BinTree.h"


using namespace std;

int main()
{
    vector<int> a = { 1,2,3 };
    vector<int> b = { 12,53,46,234 };
    vector<int> c = { 86,34,976,11111 };
    vector<int> d = { 875,896,259,9043,570 };
    vector<int> e = { 867,96 };
    vector<int> f = { 476,46,973 };
    vector<int> g = { 73,843,546,98,7033,78 };
    BinaryTree<vector<int>>tree(a);
    tree.add(b);
    tree.add(c);
    tree.add(d);
    tree.add(e);
    tree.add(f);
    tree.add(g);

    //tree.delete_by_value(10);

    tree.printPostOrder();
    tree.printInOrder();
    tree.printPreOrder();


    std::cout << "Tree size: " << tree.size() << std::endl;
    
    
   /*Tree tree(2.3, 1, 5, 2);
    tree.append(1.2, 1, 1, 5);
    tree.append(1.3, 3, 4, 5);
    tree.append(1.4, 5, 45, 5);
    tree.append(1.5, 7, 47, 5);
    tree.append(1.6, 8, 3, 5);
    tree.append(1.7, 9, 2, 5);

    cout << "______________" << endl;
    tree.defaultOutput();
    cout << "______________" << endl;
    tree.deleteNodeByIndex(4);
    cout << "______________" << endl;
    */

    /*BinTreeSearch tree(2.3, 1, 5, 2);
    tree.push_back(1.2, 1, 1, 5);
    tree.push_back(1.3, 3, 4, 5);
    tree.push_back(1.4, 5, 45, 5);
    tree.push_back(1.5, 7, 47, 5);
    tree.push_back(1.6, 8, 3, 5);
    tree.push_back(1.7, 9, 2, 5);
    tree.output();
    cout << "______________" << endl;
    tree.deleteNodeByValue(1.4, 5, 45, 5);
    cout << "______________" << endl;*/




    

}

