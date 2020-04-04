#include "singly_linked_list.h"

Node::Node(int i_data)
{
	m_data = i_data;
	next = NULL;
}

void Node::insertAfter(Node * newNode)
{
	newNode->next = next;
	next = newNode;
}

Node * Node::DeleteAfter()
{
	Node* toDelete = next;
	if (toDelete == NULL)
		return NULL;
	next = toDelete->next;
	return toDelete;
}


void List::MakeEmpty()
{
	m_head = m_tail = NULL;
}

bool List::IsEmpty()
{
	if (m_head == NULL)
	{
		m_tail = NULL;
		return true;
	}
	return false;
	
}

void List::Insert_In_Start_Of_List(Node * i_newNode)
{
	i_newNode->next = m_head;
	m_head = i_newNode;
	if (m_tail == NULL)
		m_tail = m_head;
}

void List::Insert_In_End_Of_List(Node * i_newNode)
{
	if (m_tail == NULL && m_head == NULL)
		m_tail = m_head = i_newNode;
	else
	{
		m_tail->next = i_newNode;
		m_tail = i_newNode;
	}
	
}

void List::Delete_In_Start_Of_List()
{
	Node* toDelete = m_head;
	m_head = m_head->next;
	if (m_head == NULL)
		m_tail = NULL;

	delete toDelete;

}

void List::Delete_In_End_Of_List()
{
	Node* toDelete, *curr , *prev;

	curr = m_head;
	prev = NULL;
	while (curr != m_tail)
	{
		prev = curr;
		curr = curr->next;
	}
	toDelete = m_tail;
	m_tail = prev;
	delete toDelete;

	if (m_tail == NULL)
		m_head = NULL;
}

void List::Show_List()
{
	Node* curr = m_head;
	while (curr != NULL)
	{
		cout << "->" << curr->m_data;
		curr = curr->next;
	}
	cout << endl;
}

void List::Delete_List()
{
	Node* toDelete;
	while (m_head)
	{
		toDelete = m_head;
		m_head = m_head->next;
		delete toDelete;
	}
	m_head = m_tail = NULL;
	
}


