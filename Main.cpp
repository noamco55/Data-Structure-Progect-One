// The program contains two implementations for the FindAccessible algorithm.
// One function will implement the algorithm recursively and the other will execute it without
// Using recursion.

//FindAccessible algorithm - receives, as input, the computers on the network, their connections and the hotspot 
//                           and finds the accessible group of the hotspot.




#include <iostream>
using namespace std;




#include "Solution.h"



int main()
{
	List* netWork;
	int numberOfComputers, numberOfConnections, focus;

	cin >> numberOfComputers >> numberOfConnections;
	netWork = new List[numberOfComputers + 1];

	Initialized_List_Array(netWork, numberOfComputers + 1);

	Build_Network(netWork, numberOfConnections);

	cin >> focus;

	Static_list accessibleGroup1(numberOfComputers);
	Static_list accessibleGroup2(numberOfComputers);

	int* colors = new int[numberOfComputers + 1];

	Initialized_Colors_Array(colors, numberOfComputers + 1);

	FindAccessibleRec(netWork, focus, colors, accessibleGroup1);

	Initialized_Colors_Array(colors, numberOfComputers + 1);

	findAccessibleIter(netWork, focus, colors, accessibleGroup2);

	accessibleGroup1.Show_List();
	accessibleGroup2.Show_List();

	Free_Lists_Array(netWork, numberOfComputers + 1);

	//delete[] colors;

	system("pause");
}

