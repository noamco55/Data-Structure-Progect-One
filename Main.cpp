// The program contains two implementations for the FindAccessible algorithm.
// One function will implement the algorithm recursively and the other will execute it without
// Using recursion.

//FindAccessible algorithm - receives, as input, the computers on the network, their connections and the focus computer 
//                           and finds the accessible group of the focus computer.


#include <iostream>
using namespace std;

#include "Solution.h"

int main()
{
	List* netWork;
	int numberOfComputers, numberOfConnections, focus;

	cin >> numberOfComputers >> numberOfConnections;		//get from user number of computers and number of connections
	netWork = new List[numberOfComputers + 1];			//size of netWork is numberOfComputers + 1
														//make easy to find the right computer in the array
	Initialized_List_Array(netWork, numberOfComputers + 1);

	Build_Network(netWork, numberOfConnections, numberOfComputers);

	cin >> focus;

	try
	{
		checkFocusComputerFromUser(focus, numberOfComputers);   // could throw exception

		Static_list accessibleGroup1(numberOfComputers);		//accessibleGroup1 - accessible Group for recursive solution 
		Static_list accessibleGroup2(numberOfComputers);		//accessibleGroup2 - accessible Group for iterative solution 

		int* colors = new int[numberOfComputers + 1];

		Initialized_Colors_Array(colors, numberOfComputers + 1);

		FindAccessibleRec(netWork, focus, colors, accessibleGroup1);

		Initialized_Colors_Array(colors, numberOfComputers + 1);		//need to initialized again for the second solution

		findAccessibleIter(netWork, focus, colors, accessibleGroup2);

		accessibleGroup1.Show_List();
		accessibleGroup2.Show_List();

		Free_Lists_Array(netWork, numberOfComputers + 1);

		//delete[] colors;
	}
	catch (const char* msg)   // catch the exception and print message to user
	{
		cout << msg << focus << endl;
	}

	system("pause");
}

