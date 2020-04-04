#ifndef __STATIC_SINGLY_LINKED_LIST

#define __STATIC_SINGLY_LINKED_LIST


#include <iostream>
using namespace std;

class Stataic_node
{
public:
	int data;
	int next;
};


class Static_list
{
public:

	Stataic_node* m_stataic_list;
	int m_headList;
	int m_tailList;
	int m_headFree;
	int m_size;


	Static_list(int i_size);
	~Static_list();

	void MakeEmpty();

	void Insert_In_End_Of_List(int i_data);

	void Delete_From_List(int i_DataToDelete);

	void Show_List();
};

#endif // !__STATIC_SINGLY_LINKED_LIST
