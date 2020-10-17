// Name: Kfir Bilu
// I.D: 205639230





#pragma once
#include "Node.h"
#include<iostream>
using namespace std;




class LinkedList :public Node
{
private:
	Node* _head;
	Node* _tail;
	int _size=1;
	int _type = -1; // 0 - snake , 1 - snail
	int _snailLoop = 0; 


public:

	LinkedList();  // constructor
	Node* getHead();   // gets the head of the list
	Node* getTail();   // gets the tail of the list
	int getSize()const;  // gets the size of the list
	void setHead(Node* head);  // sets head node
	void setTail(Node* tail);  // sets tail node
	void increaseSize();  // increaeses list's size
	void setType(int type);   // sets the type of the list
	int getType()const;  // gets the type of the list
	void increaseSnailLoop();  // increaeses snail's loop size
	int getSnailSize()const;  // gets snail's loop size


	
	friend Node* snakeOrSnail(LinkedList* list); // return null if snake, returns pointer if snail
	void printData();   // prints the data of the list


	LinkedList& createList2();  // creates new list - snail or snake
	void insert2(int data);  // inserts new node

};