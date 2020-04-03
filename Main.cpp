
#include <iostream>
using namespace std;


#include "singly_linked_list.h"



void Build_Network(List* list,int i_connections);
void Show_Array_Of_Lists(List* listArr , int size);
void Initialized_List_Array(List* listArr, int size);

int main()
{
	List* netWork;
	int numberOfComputers, numberOfConnections;

	cin >> numberOfComputers >> numberOfConnections;

	netWork = new List[numberOfComputers + 1];

	Initialized_List_Array(netWork, numberOfComputers + 1);

	Build_Network(netWork, numberOfConnections);

	Show_Array_Of_Lists(netWork, numberOfConnections + 1);



	system("pause");
}

void Build_Network(List* list, int i_connections)
{
	int from, to;

	for (int i = 0; i < i_connections; i++)
	{
		cin >> from >> to;
		Node* newNode = new Node;
		newNode->m_data = to;
		newNode->next = NULL;
		list[from].Insert_In_Start_Of_List(newNode);
	}

}

void Show_Array_Of_Lists(List * listArr , int size)
{
	for (int i = 1; i < size; i++)
	{
		cout << i;
		listArr[i].Show_List();
	}
}

void Initialized_List_Array(List * listArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		listArr[i].MakeEmpty();
	}
}
