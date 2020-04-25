#include "singly_linked_list.h"

int Node::getData()
{
	return m_data;
}

Node * Node::getNext()
{
	return m_next;
}

void Node::setData(int i_data)
{
	m_data = i_data;
}

void Node::setNext(Node * newNode)
{
	m_next = newNode;
}

Node::Node(int i_data)
{
	m_data = i_data;
	m_next = nullptr;
}

Node::Node(Node * newNode)
{
	m_data = newNode->getData();
	m_next = newNode->getNext();
}

void Node::insertAfter(Node * newNode)
{
	newNode->m_next = m_next;
	m_next = newNode;
}

Node * Node::DeleteAfter()
{
	Node* toDelete = m_next;
	if (toDelete == nullptr)
		return nullptr;
	m_next = toDelete->m_next;
	return toDelete;
}


Node * List::getHead()
{
	return m_head;
}

Node * List::getTail()
{
	return m_tail;
}

void List::MakeEmpty()
{
	m_head = m_tail = nullptr;
}

bool List::IsEmpty()
{
	if (m_head == nullptr)
	{
		m_tail = nullptr;
		return true;
	}
	return false;
	
}

void List::Insert_In_Start_Of_List(Node * i_newNode)
{
	i_newNode->setNext(m_head);
	m_head = i_newNode;
	if (m_tail == nullptr)
		m_tail = m_head;
}

void List::Insert_In_End_Of_List(Node * i_newNode)
{
	if (m_tail == nullptr && m_head == nullptr)
	{
		m_tail = i_newNode;
		m_head = i_newNode;
	}
	else
	{
		m_tail->setNext(i_newNode);
		m_tail = i_newNode;
	}
	
}

void List::Delete_In_Start_Of_List()
{
	Node* toDelete = m_head;
	m_head = m_head->getNext();
	if (m_head == nullptr)
		m_tail = nullptr;

	delete toDelete;

}

void List::Delete_In_End_Of_List()
{
	Node* toDelete, *curr , *prev;

	curr = m_head;
	prev = nullptr;
	while (curr != m_tail)
	{
		prev = curr;
		curr = curr->getNext();
	}
	toDelete = m_tail;
	m_tail = prev;
	delete toDelete;

	if (m_tail == nullptr)
		m_head = nullptr;
}

void List::Show_List()
{
	Node* curr = m_head;
	while (curr != nullptr)
	{
		cout << "->" << curr->getNext();
		curr = curr->getNext();
	}
	cout << endl;
}

void List::Delete_List()
{
	Node* toDelete;
	while (m_head)
	{
		toDelete = m_head;
		m_head = m_head->getNext();
		delete toDelete;
	}
	m_head = m_tail = nullptr;
	
}


