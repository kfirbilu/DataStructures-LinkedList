// Name: Kfir Bilu
// I.D: 205639230




#include "Node.h"
#include "linkedList.h"
#include <iostream>

using namespace std;

void main()
{

	LinkedList lst;
	lst = lst.createList2();
	Node* node = snakeOrSnail(&lst);
	lst.printData();
	system("pause");
}