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
	head = tail = NULL;
}

bool List::IsEmpty()
{
	if (head == NULL)
	{
		tail = NULL;
		return true;
	}
	return false;
	
}

void List::Insert_In_Start_Of_List(Node * i_newNode)
{
	i_newNode->next = head;
	head = i_newNode;
	if (tail == NULL)
		tail = head;
}

void List::Insert_In_End_Of_List(Node * i_newNode)
{
	if (tail == NULL && head == NULL)
		tail = head = i_newNode;
	else
	{
		tail->next = i_newNode;
		tail = i_newNode;
	}
	
}

void List::Delete_In_Start_Of_List()
{
	Node* toDelete = head;
	head = head->next;
	if (head == NULL)
		tail = NULL;

	delete toDelete;

}

void List::Delete_In_End_Of_List()
{
	Node* toDelete, *curr , *prev;

	curr = head;
	prev = NULL;
	while (curr != tail)
	{
		prev = curr;
		curr = curr->next;
	}
	toDelete = tail;
	tail = prev;
	delete toDelete;

	if (tail == NULL)
		head = NULL;
}

void List::Show_List()
{
	Node* curr = head;
	while (curr != NULL)
	{
		cout << "->" << curr->m_data;
		curr = curr->next;
	}
	cout << endl;
}


