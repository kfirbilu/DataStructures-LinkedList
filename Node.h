// Name: Kfir Bilu
// I.D: 205639230



#pragma once
#include <ctime>
#include<iostream>
using namespace std;




class Node 
{
private:
	int _key = 0;
	Node* _nextNode;
	

public:
	Node();  // default constructor
	Node(int data);  // constructor
	int getKey();   // gets the key's data
	Node* getNextNode()const;   // gets the next node pointer
	void setNextNode(Node* next);  // sets next node
	void setKey(int key); // sets the key
	
};




