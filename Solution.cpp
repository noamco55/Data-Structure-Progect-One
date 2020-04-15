
#include "Solution.h"





void FindAccessibleRec(List * i_netWork, int i_computer, int * i_colorsArr, Static_list & i_accessibleGroup)
{
	i_colorsArr[i_computer] = BLACK;
	i_accessibleGroup.Insert_In_End_Of_List(i_computer);
	Node* curr = i_netWork[i_computer].getHead();

	while (curr)
	{
		if (i_colorsArr[curr->getData()] == WHITE)
			FindAccessibleRec(i_netWork, curr->getData(), i_colorsArr, i_accessibleGroup);
		curr = curr->getNext();
	}

}


void findAccessibleIter(List* i_netWork, int i_computer, int* i_colorsArr, Static_list& i_accessibleGroup)
{
	Stack stack;
	int returnFromRecursion = FALSE;

	ItemType *curr = new ItemType(i_netWork[i_computer].getHead(), i_computer, ItemType::START);
	Node* local_currentCompInNetworkPath = curr->getlocalCurr();
	ItemType *newItem;

	do
	{
		if (returnFromRecursion)
			curr = stack.Pop();

		if (curr->getLine() == ItemType::START)
		{
			i_colorsArr[curr->getComputer()] = BLACK;
			i_accessibleGroup.Insert_In_End_Of_List(curr->getComputer());
			curr->setlocalCurr(i_netWork[curr->getComputer()].getHead());
			curr->setLine(ItemType::AFTER);
		}
		while (curr->getlocalCurr() && curr->getLine() == ItemType::AFTER)
		{
			if (i_colorsArr[curr->getlocalCurr()->getData()] == WHITE)
			{
				newItem = new ItemType(curr);
				stack.Push(newItem);

				curr->setComputer(curr->getlocalCurr()->getData());
				//curr->setlocalCurr(i_netWork[curr->getComputer()].getHead());

				curr->setLine(ItemType::START);
				returnFromRecursion = FALSE;
			}
			else
				curr->setlocalCurr(curr->getlocalCurr()->getNext());
		}
		if (!curr->getlocalCurr())
			returnFromRecursion = TRUE;

	} while (!stack.isEmpty());

	delete curr;

}







void Build_Network(List* i_list, int i_connections)
{
	int from, to;

	for (int i = 0; i < i_connections; i++)
	{
		cin >> from >> to;
		Node* newNode = new Node;
		newNode->setData(to);
		newNode->setNext(NULL);
		i_list[from].Insert_In_End_Of_List(newNode);
	}

}

void Show_Array_Of_Lists(List * i_listArr, int i_size)
{
	for (int i = 1; i < i_size; i++)
	{
		cout << i;
		i_listArr[i].Show_List();
	}
}

void Initialized_List_Array(List * i_listArr, int i_size)
{
	for (int i = 0; i < i_size; i++)
	{
		i_listArr[i].MakeEmpty();
	}
}

void Initialized_Colors_Array(int * i_colorArr, int i_size)
{
	for (int i = 0; i < i_size; i++)
		i_colorArr[i] = WHITE;
}



void Free_Lists_Array(List * i_listArr, int i_size)
{
	for (int i = 0; i < i_size; i++)
	{
		i_listArr[i].Delete_List();
	}
	delete[] i_listArr;
}
