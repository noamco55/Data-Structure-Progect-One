#include "recursive_solution.h"





void Recursive_Solution()
{
	List* netWork;
	int numberOfComputers, numberOfConnections, focus;

	cin >> numberOfComputers >> numberOfConnections;
	netWork = new List[numberOfComputers + 1];

	Initialized_List_Array(netWork, numberOfComputers + 1);

	Build_Network(netWork, numberOfConnections);

	cin >> focus;

	Static_list accessibleGroup(numberOfComputers);

	int* colors = new int[numberOfComputers + 1];
	Initialized_Colors_Array(colors, numberOfComputers + 1);

	FindAccessible(netWork, focus, colors, accessibleGroup);

	accessibleGroup.Show_List();
	
	Free_Lists_Array(netWork, numberOfComputers + 1);
	//delete[] colors;
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

void FindAccessible(List * i_netWork, int i_computer, int * i_colorsArr, Static_list & i_accessibleGroup)
{
	i_colorsArr[i_computer] = BLACK;
	i_accessibleGroup.Insert_In_End_Of_List(i_computer);
	Node* curr = i_netWork[i_computer].getHead();

	while (curr)
	{
		if (i_colorsArr[curr->getData()] == WHITE)
			FindAccessible(i_netWork, curr->getData(), i_colorsArr, i_accessibleGroup);
		curr = curr->getNext();
	}

}

void Free_Lists_Array(List * i_listArr, int i_size)
{
	for (int i = 0; i < i_size; i++)
	{
		i_listArr[i].Delete_List();
	}
	delete[] i_listArr;
}
