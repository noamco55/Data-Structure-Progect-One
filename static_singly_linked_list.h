#ifndef __STATIC_SINGLY_LINKED_LIST

#define __STATIC_SINGLY_LINKED_LIST


#include <iostream>
using namespace std;

class Stataic_node
{
private:
	int m_data;
	int m_next;

public:
	int getData();
	int getNext();
	void setData(int i_data);
	void setNext(int i_next);

};


class Static_list
{
private:

	Stataic_node* m_stataic_list;
	int m_headList;     //the head of the value list
	int m_tailList;		//the tail of the value list
	int m_headFree;		//the head of the free list
	int m_size;

public:

	Static_list(int i_size);
	~Static_list();

	Stataic_node* getList();
	int getHeadList();
	int getTailList();
	int getHeadFree();
	int getSize();
	

	void MakeEmpty();

	void Insert_In_End_Of_List(int i_data);

	void Delete_From_List(int i_DataToDelete);

	void Show_List();
};

#endif // !__STATIC_SINGLY_LINKED_LIST
