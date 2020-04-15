#include "Stack.h"

ItemType::ItemType(Node* i_local_Curr, int i_computer, LINE line)
{
	m_line = line;
	m_computer = i_computer;
	m_local_Curr = new Node( i_local_Curr);
}

ItemType::ItemType(ItemType * i_item)
{
	m_line = i_item->getLine();
	m_computer = i_item->getComputer();
	m_local_Curr = new Node(i_item->getlocalCurr());
}

ItemType::~ItemType()
{
	delete m_local_Curr;
}

ItemType* ItemType::getNext()
{
	return m_next;
}

void ItemType::setNext(ItemType* item)
{
	m_next = item;
}

ItemType::LINE ItemType::getLine() const
{
	return m_line;
}

void ItemType::setLine(ItemType::LINE i_line)
{
	m_line = i_line;
}

void ItemType::setComputer(int i_computer)
{
	m_computer = i_computer;
}

int ItemType::getComputer()
{
	return m_computer;
}

void ItemType::setlocalCurr(Node * i_local_Curr)
{
	m_local_Curr = i_local_Curr;
}

Node * ItemType::getlocalCurr()
{
	return m_local_Curr;
}


// StackList:

ItemType* Stack::StackList::getHead()
{
	return m_head;
}

ItemType* Stack::StackList::getTail()
{
	return m_tail;
}

void Stack::StackList::MakeEmpty()
{
	m_head = m_tail = nullptr;
}

bool Stack::StackList::IsEmpty() const
{
	if (m_head == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

void Stack::StackList::Insert_In_Start_Of_List(ItemType * i_newNode)
{
	if (m_head == nullptr)
		m_head = m_tail = i_newNode;
	i_newNode->setNext(m_head);
	m_head = i_newNode;
	
}

void Stack::StackList::Insert_In_End_Of_List(ItemType * i_newNode)
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

void Stack::StackList::Delete_In_Start_Of_List()
{
	ItemType* toDelete = m_head;
	m_head = m_head->getNext();
	if (m_head == nullptr)
		m_tail = nullptr;

	delete toDelete;

}

void Stack::StackList::Delete_In_End_Of_List()
{
	ItemType* toDelete,
		*curr = m_head,
		*prev = nullptr;

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

void Stack::StackList::Remove_From_Head()  // removes head from list but doesn't delete (free) it
{
	ItemType* toDelete = m_head;
	m_head = m_head->getNext();

	if (m_head == nullptr)
		m_tail = nullptr;

	delete toDelete;
}


void Stack::StackList::Show_List() const
{
	ItemType* curr = m_head;
	while (curr != nullptr)
	{
		cout << "->" << curr->getNext();
		curr = curr->getNext();
	}
	cout << endl;
}

void Stack::StackList::Delete_List()
{
	ItemType* toDelete;
	
	while (m_head)
	{
		toDelete = m_head;
		m_head = m_head->getNext();
		delete toDelete;
	}
	
	m_head = m_tail = nullptr;

}

// Stack:

Stack::Stack(): m_Size(0)
{
	m_Stack.MakeEmpty();
}

bool Stack::isEmpty()
{
	return ( (m_Size == EMPTY) ? (true) : (false) );
}

void Stack::makeEmpty()
{
	m_Stack.MakeEmpty();
	m_Size = EMPTY;
}

void Stack::Push(ItemType *newItem)
{
	m_Stack.Insert_In_Start_Of_List(newItem);
	m_Size++;
}

ItemType* Stack::Pop()
{
	ItemType* item = new ItemType (m_Stack.getHead());
	
	m_Stack.Remove_From_Head();

	m_Size--;
	
	return item;
}
