#ifndef __SINGLY_LINKEK_LIST
#define __SINGLY_LINKEK_LIST

#include <iostream>
using namespace std;

class Node
{
public:
	int m_data;
	Node* next;


	Node() = default;
	Node(int i_data);
	
	void insertAfter(Node* i_newNode);
	Node* DeleteAfter();
	
	
};



class List
{
public:
	Node* head;
	Node* tail;


	void MakeEmpty();
	bool IsEmpty();
	void Insert_In_Start_Of_List(Node* i_newNode);
	void Insert_In_End_Of_List(Node* i_newNode);
	void Delete_In_Start_Of_List();
	void Delete_In_End_Of_List();
	void Show_List();
};












#endif // !__SINGLY_LINKEK_LIST

