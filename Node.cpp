// Name: Kfir Bilu
// I.D: 205639230



#include "Node.h"
#include "linkedList.h"


//////////////     Node Methods   -    Start      ///////////////


Node::Node()
{
	this->setKey(0);
	this->setNextNode(NULL);
	
}


Node::Node(int key)  // constructor
{
	this->setKey(key);
	this->setNextNode(NULL);
	
}

int Node::getKey()    // gets the key's data - done
{
	return this->_key;
}

void Node::setKey(int key) // sets the key - dove
{
	this->_key = key;
}


Node* Node::getNextNode() const   // gets the next node pointer - done
{
	return this->_nextNode;
}


void Node::setNextNode(Node* next) // sets the next node pointer - done
{
	this->_nextNode = next;
}








//////////////     Node Methods   -    End      ///////////////

