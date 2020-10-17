// Name: Kfir Bilu
// I.D: 205639230


#include "linkedList.h"
#include "Node.h"




//////////////     Linked List Methods   -    Start      ///////////////


LinkedList::LinkedList()  // constructor
{
	this->setHead(NULL);
	this->setTail(NULL);
}

void LinkedList::setHead(Node* head)  // sets head node
{
	this->_head = head;
}


void LinkedList::setTail(Node* tail)  // sets tail node
{
	this->_tail = tail;
}



Node* LinkedList::getHead()   // gets the head of the list
{
	return this->_head;
}


Node* LinkedList::getTail()    // gets the tail of the list
{
	return this->_tail;
}


int LinkedList::getSize()const  // gets the size of the list
{
	return this->_size;
}

void LinkedList::increaseSize()   // increaeses list's size
{
	this->_size += 1;
}


void LinkedList::setType(int type)   // sets the type of the list
{
	this->_type = type;
}

void LinkedList::increaseSnailLoop()  // increaeses snail's loop size
{
	this->_snailLoop++;
}


int LinkedList::getSnailSize()const  // gets snail's loop size
{
	return this->_snailLoop;
}

int LinkedList::getType()const  // gets the type of the list
{
	return this->_type;
}







Node* snakeOrSnail(LinkedList * list) // return null if snake, returns pointer if snail 
{
	Node* ptr1;
	Node* ptr2;
	int count = 1;

	if (list->getHead() == NULL || list->getHead()->getNextNode()==NULL || list->getHead()->getNextNode()->getNextNode()==NULL)
	{
		return NULL;
	}

	ptr1 = list->getHead()->getNextNode();
	ptr2 = list->getHead()->getNextNode()->getNextNode();

	while (ptr2 != NULL && ptr1 != ptr2) // checks if they point to the same node
	{
		if ( ptr2->getNextNode() == NULL || ptr2->getNextNode()->getNextNode() == NULL)
		{
			return NULL;
		}

		ptr1 = ptr1->getNextNode();
		ptr2 = ptr2->getNextNode()->getNextNode();
	}

	if (ptr2 == NULL)
	{
		return NULL;
	}

	while (ptr2->getNextNode() != ptr1)  //counting the circle's length 
	{
		ptr2 = ptr2->getNextNode();
		count++;
	}

	ptr1 = list->getHead();   // restarts the pointer to the head of the list
	ptr2 = list->getHead();   // restarts the pointer to the head of the list

	for (int i = 0; i < count; i++)  
	{
		ptr2 = ptr2->getNextNode();
	}

	while (ptr1->getNextNode() != ptr2->getNextNode())  // ptr2 will point to the start of the loop
	{
		ptr1 = ptr1->getNextNode();
		ptr2 = ptr2->getNextNode();
	}

	return ptr2->getNextNode()->getNextNode();   // returns the start of the loop

}



void LinkedList::printData()   // prints the data of the list
{
	int type = this->getType();
	if (this->getHead() == NULL)
	{
		cout << "NULL" << endl;
	}
	if (type == 0)  // snake
	{
		Node* temp = this->getHead();

		while(temp != NULL)
		{
			cout << temp->getKey()<<"->";
			temp = temp->getNextNode();
		}
		cout << "NULL" << endl;
		cout <<"The size of the snake is: "<<this->getSize() << endl;

	}

	if (type == 1)  // snail
	{
		Node* ptr1=this->getHead();
		Node* ptr2=snakeOrSnail(this);
		while (ptr1 != ptr2)
		{
			cout << ptr1->getKey() << "->";
			ptr1 = ptr1->getNextNode();
		}

		cout << "^" << ptr1->getKey() << "->";
		ptr2 = ptr2->getNextNode();

		while (ptr1 != ptr2->getNextNode()->getNextNode())
		{
			cout << ptr2->getKey() << "->";
			ptr2 = ptr2->getNextNode();
		}

		cout << ptr2->getKey() << "^" << endl;

		cout << "The size of the snail is: " << this->getSize() << endl;
		cout << "The size of the loop is: " << this->getSnailSize() << endl;

	}

}

void LinkedList::insert2(int data)  // inserts new node
{
	Node* temp = new Node(data); //create a new node

	if (this->getHead() == NULL) //if the linked list is empty
	{
		this->setHead(temp);

		this->setTail(temp);
	}
	else
	{
		this->getTail()->setNextNode(temp);

		this->setTail(temp);
	}
}



LinkedList& LinkedList::createList2()  // creates new list - snail or snake
{
	
	LinkedList list;
	Node* head = new Node;
	
	srand(time(NULL));
	int snakeOrSnail = rand() % (2 - 1 + 1);  // snake or snail
	int i = 0;

	if (snakeOrSnail == 0)  // creates snake
	{
		list.setType(0);   // sets list type to snake
		srand(time(NULL));
		int randomForSnake = rand() % 100 + 1;  //NULL or continue
		int nullOrNode = -1;
		
		
		while (nullOrNode != randomForSnake)
		{
			list.insert2(i);
			list.increaseSize();
			nullOrNode = rand() % 100 + 1;  //number between 1-100
			i++;
		}
		list.insert2(i);
		return list;
	}


	if (snakeOrSnail == 1)  // creates snail
	{
		srand(time(NULL));
		list.setType(1);

		int snailEnd = rand() % 80 + 1;  //number between 1-80
		int loopStart = rand() % 850 + 1;     //number between 1-850
		int end = -1;
		int start = -1;


		while (start != loopStart)
		{
			list.insert2(i);
			list.increaseSize();
			start = rand() % 850 + 1;     //number between 1-850 - choses the last cell
			i++;
		}
		
		Node* temp = list.getTail();

		while (end != snailEnd)
		{
			list.insert2(i);
			list.increaseSize();
			list.increaseSnailLoop();
			end = rand() % 80 + 1;  //number between 1-80 - end of the snail
			i++;
		}

		list.insert2(i);
		list.increaseSnailLoop();
		list.getTail()->setNextNode(temp);
		return list;

	}




}




//////////////     Linked List Methods   -    End      ///////////////


