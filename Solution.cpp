
#include "Solution.h"




// recursive implementation of FindAccessible algorithm.
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

// iterative implementation of FindAccessib algorithm.
void findAccessibleIter(List* i_netWork, int i_computer, int* i_colorsArr, Static_list& i_accessibleGroup)
{
	Stack stack;
	int returnFromRecursion = FALSE;

	ItemType *curr = new ItemType(i_netWork[i_computer].getHead(), i_computer, ItemType::START);
	ItemType *newItem;

	do
	{
		if (returnFromRecursion)
		{
			delete curr;
			curr = stack.Pop();
		}
		
		if (curr->getLine() == ItemType::START)
		{
			i_colorsArr[curr->getComputer()] = BLACK;
			i_accessibleGroup.Insert_In_End_Of_List(curr->getComputer());
			curr->setlocalCurr(i_netWork[curr->getComputer()].getHead());
			curr->setLine(ItemType::AFTER);
		}
		while (curr->getlocalCurr() && curr->getLine() == ItemType::AFTER)  // loop for every node in the list.
		{
			if (i_colorsArr[curr->getlocalCurr()->getData()] == WHITE)     // the recursive condition.
			{
				newItem = new ItemType(curr);
				stack.Push(newItem);

				curr->setComputer(curr->getlocalCurr()->getData());
				
				curr->setLine(ItemType::START);
				returnFromRecursion = FALSE;
			}
			else
				curr->setlocalCurr(curr->getlocalCurr()->getNext());    // go to the next node in the list
		}
		if (!curr->getlocalCurr())
			returnFromRecursion = TRUE;

	} while (!stack.isEmpty());

	delete curr;

}



// build the computers connections in the list array
void Build_Network(List* i_list, int i_connections , int  i_numberOfComputers)
{
	int from , to;

	for (int i = 0; i < i_connections; i++)  // loop for the number of connections we have in the network
	{
		cin >> from >> to;
		try
		{
			checkConnectionsFromUser(from, to , i_numberOfComputers);  // could throw exception
			Node* newNode = new Node;
			newNode->setData(to);
			newNode->setNext(NULL);
			i_list[from].Insert_In_End_Of_List(newNode);
		}
		catch(const char* msg)   // catch the exception and check the value that was exception
		{
			cout << msg ;

			if (from == 0)
				cout << from;
			else if (to == 0)
				cout << to;
			else
				cout << (from >= to) ? from : to;
			cout << endl;
		}
	}
}

// print the list array
void Show_Array_Of_Lists(List * i_listArr, int i_size)
{
	for (int i = 1; i < i_size; i++)
	{
		cout << i;
		i_listArr[i].Show_List();
	}
}

// initial all the lists in the array      
void Initialized_List_Array(List * i_listArr, int i_size)
{
	for (int i = 0; i < i_size; i++)
	{
		i_listArr[i].MakeEmpty();
	}
}

// initial all the color in the array to white
void Initialized_Colors_Array(int * i_colorArr, int i_size)
{
	for (int i = 0; i < i_size; i++)
		i_colorArr[i] = WHITE;
}

// free the memory of all the lists in the array
void Free_Lists_Array(List * i_listArr, int i_size)
{
	for (int i = 0; i < i_size; i++)
	{
		i_listArr[i].Delete_List();
	}
	delete[] i_listArr;
}

// check if inputs for "i_from" and "i_to" are valid
void checkConnectionsFromUser(int i_from, int i_to, int  i_numberOfComputers) throw(const char*)
{
	if (i_from > i_numberOfComputers || i_from == 0 || i_to > i_numberOfComputers || i_to == 0)
	{
		throw "no such computer " ;
	}
}

// check if input for "i_computer" is valid
void checkFocusComputerFromUser(int  i_computer, int  i_numberOfComputers)
{
	if (i_computer > i_numberOfComputers || i_computer == 0)
	{
		throw "no such computer " ;
	}
}
