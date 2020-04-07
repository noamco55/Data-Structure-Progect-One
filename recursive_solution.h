#ifndef __RECURSIVE_SOLUTION

#define __RECURSIVE_SOLUTION

#include "singly_linked_list.h"
#include "static_singly_linked_list.h"


const int WHITE = 1;
const int BLACK = 0;

void Recursive_Solution();                                        
void Build_Network(List* i_list, int i_connections);             // build the computers connections in the list array
void Show_Array_Of_Lists(List* i_listArr, int i_size);           // print the list array
void Initialized_List_Array(List* i_listArr, int i_size);        // initial all the lists in the array      
void Initialized_Colors_Array(int* i_colorArr, int i_size);      // initial all the color in the array to white
void FindAccessible(List* i_netWork, int i_computer, int* i_colorsArr, Static_list& i_accessibleGroup);  // implement the algorithm recursively
void Free_Lists_Array(List* i_listArr, int i_size);              // free the memory of all the lists in the array






#endif // !__RECURSIVE_SOLUTION

