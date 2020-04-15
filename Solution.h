#ifndef __SOULUTION_H
#define __SOULUTION_H




#include "singly_linked_list.h"
#include "static_singly_linked_list.h"
#include "Stack.h"

const int FALSE = 0;
const int TRUE = 1;
const int WHITE = 1;
const int BLACK = 0;

// implement the algorithm recursively
void FindAccessibleRec(List* i_netWork, int i_computer, int* i_colorsArr, Static_list& i_accessibleGroup);  

// implement the algorithm Iteratively
void findAccessibleIter(List* i_netWork, int i_computer, int* i_colorsArr, Static_list& i_accessibleGroup);  


void Build_Network(List* i_list, int i_connections , int  i_numberOfComputers); // build the computers connections in the list array
void Show_Array_Of_Lists(List* i_listArr, int i_size);						    // print the list array
void Initialized_List_Array(List* i_listArr, int i_size);					    // initial all the lists in the array      
void Initialized_Colors_Array(int* i_colorArr, int i_size);					    // initial all the color in the array to white
void Free_Lists_Array(List* i_listArr, int i_size);							    // free the memory of all the lists in the array
void checkConnectionsFromUser(int i_from, int i_to ,int  i_numberOfComputers);  // check if inputs for "i_from" and "i_to" are valid
void checkFocusComputerFromUser(int i_computer, int  i_numberOfComputers);      // check if input for "i_computer" is valid



#endif // !__SOULUTION_H


