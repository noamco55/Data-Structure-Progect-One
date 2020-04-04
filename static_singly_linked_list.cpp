#include "static_singly_linked_list.h"

Static_list::Static_list(int i_size)
{
	m_stataic_list = new Stataic_node[i_size];
	m_size = i_size;
	this->MakeEmpty();
}

Static_list::~Static_list()
{
	delete[] m_stataic_list;
}

void Static_list::MakeEmpty()
{
	m_headList = -1;
	m_tailList = -1;
	m_headFree = 0;
	int i;
	for ( i= 0; i < m_size; i++)
		m_stataic_list[i].next = i + 1;
	m_stataic_list[i].next = -1;
}

void Static_list::Insert_In_End_Of_List(int i_data)
{
	if (m_headFree != -1)
	{
		int locNew = m_headFree;
		m_headFree = m_stataic_list[m_headFree].next;
		m_stataic_list[locNew].data = i_data;
		m_stataic_list[locNew].next = -1;
		if (m_headList == -1)
			m_headList = m_tailList = locNew;
		else
		{
			m_stataic_list[m_tailList].next = locNew;
			m_tailList = locNew;
		}
	}
	else
		cout << "there is no place in the list\n";
	

}

void Static_list::Delete_From_List(int i_DataToDelete)
{
	int curr = m_headList, prev = -1;

	while (m_stataic_list[curr].data != i_DataToDelete && curr != -1)
	{
		prev = curr;
		curr = m_stataic_list[curr].next;
	}

	if (curr == -1)
		cout << i_DataToDelete << "Does not exist in the list\n";
	else
	{
		int locFree = curr;
		m_stataic_list[prev].next = m_stataic_list[curr].next;
		m_stataic_list[locFree].next = m_headFree;
		m_headFree = locFree;
	}
}

void Static_list::Show_List()
{
	int curr = m_headList;

	while (curr != -1)
	{
		cout << m_stataic_list[curr].data << " ";
		curr = m_stataic_list[curr].next;
	}
	cout << endl;
}
