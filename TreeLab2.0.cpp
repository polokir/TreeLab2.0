#include <iostream>

#include"BinTreeSearch.h"
#include"Trees.h"
#include "BinTree.h"


using namespace std;

int main()
{
    /*BinTree tree(2.3, 1, 5, 2);
    tree.push_back(1.2, 1, 1, 5);
    tree.push_back(1.3, 3, 4, 5);
    tree.push_back(1.4, 5, 45, 5);
    tree.push_back(1.5, 7, 47, 5);
    tree.push_back(1.6, 8, 3, 5);
    tree.push_back(1.7, 9, 2, 5);

    cout << "______________" << endl;

    tree.symetricaloutput();
    cout << "______________" << endl;
    tree.deleteNodeByValue(1.7, 9, 2, 5);
    */
    
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

    BinTreeSearch tree(2.3, 1, 5, 2);
    tree.push_back(1.2, 1, 1, 5);
    tree.push_back(1.3, 3, 4, 5);
    tree.push_back(1.4, 5, 45, 5);
    tree.push_back(1.5, 7, 47, 5);
    tree.push_back(1.6, 8, 3, 5);
    tree.push_back(1.7, 9, 2, 5);
    tree.output();
    cout << "______________" << endl;
    tree.deleteNodeByValue(1.4, 5, 45, 5);
    cout << "______________" << endl;




    

}

