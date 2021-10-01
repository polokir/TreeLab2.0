#include <iostream>
#include"BinTree.h"
//#include"BinTreeSearch.h"
#include"Trees.h"

using namespace std;

int main()
{
    BinTree tree(2.3, 1, 5, 2);
    tree.push_back(1.2, 1, 1, 5);
    tree.push_back(1.3, 3, 4, 5);
    tree.push_back(1.4, 5, 45, 5);
    tree.push_back(1.5, 7, 47, 5);
    tree.push_back(1.6, 8, 3, 5);
    tree.push_back(1.7, 9, 2, 5);

    cout << "______________" << endl;

    tree.symetricaloutput();
}

