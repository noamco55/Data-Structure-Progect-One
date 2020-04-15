#ifndef __SINGLY_LINKEK_LIST
#define __SINGLY_LINKEK_LIST

#include <iostream>
using namespace std;

class Node
{
private:

	int m_data;
	Node* m_next;

public:

	Node() = default;
	Node(int i_data);
	Node(Node* newNode);

	int getData();
	Node* getNext();
	void setData(int i_data);
	void setNext(Node* newNode);

	
	
	void insertAfter(Node* i_newNode);
	Node* DeleteAfter();
	
	
};



class List
{
private:

	Node* m_head;
	Node* m_tail;

public:
	Node* getHead();
	Node* getTail();
	
	void MakeEmpty();
	bool IsEmpty();
	void Insert_In_Start_Of_List(Node* i_newNode);
	void Insert_In_End_Of_List(Node* i_newNode);
	void Delete_In_Start_Of_List();
	void Delete_In_End_Of_List();
	void Show_List();
	void Delete_List();
};












#endif // !__SINGLY_LINKEK_LIST

