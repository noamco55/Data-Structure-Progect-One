#ifndef __STACK__
#define __STACK__

#include "singly_linked_list.h"
#include "static_singly_linked_list.h"

class ItemType
{
public:
	enum LINE { START, AFTER };
	
	ItemType(Node* i_local_Curr, int i_computer,  LINE line);
	ItemType(ItemType* i_item);
	~ItemType();


	ItemType* getNext();
	void setNext(ItemType* i_item);
	LINE getLine() const;
	void setLine(ItemType::LINE i_line);
	void setComputer(int i_computer);
	int getComputer();
	void setlocalCurr(Node* i_local_Curr);
	Node* getlocalCurr();
	
 private:
	
	LINE m_line;                //   parameters
								//         of
	int m_computer;             //          ITERATIVE
	Node* m_local_Curr;         //           FindAccessible() function
 
	
	ItemType* m_next;

 
};

class Stack
{
	  class StackList
	{
		 ItemType* m_head;
		 ItemType* m_tail;

	 public:
		 ItemType* getHead();
		 ItemType* getTail();

		 void MakeEmpty();
		 bool IsEmpty() const;
		 void Insert_In_Start_Of_List(ItemType* i_newNode);
		 void Insert_In_End_Of_List(ItemType* i_newNode);
		 void Delete_In_Start_Of_List();
		 void Delete_In_End_Of_List();
		 void Remove_From_Head();
		 void Show_List() const;
		 void Delete_List();
	};
	
 private:

	StackList m_Stack;
	int m_Size;

 public:
	 const static int EMPTY = 0;
	
	Stack();
	bool isEmpty();
	void makeEmpty();
	void Push(ItemType *newItem);
	ItemType* Pop();
	

};











#endif 