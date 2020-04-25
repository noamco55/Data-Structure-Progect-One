# Data-Structure-Progect-One

The project made by myself and Lidor Sommer for school as first project in Data Structure.

The program came to describe a computer network, with different computers connected in one-way communication lines.
Not all computers are necessarily connected to everyone.

The program receives from the user the number of computers, the number of connections the user types the existing connections and the number of computer from which to send a message.
The program will iteratively and recursively return the group of computers that can receive the message

For example:
For this input
5 5
1 4 3 2 3 5 2 4 4 5

The following connections will be created:
1->4 3->2 3->5 2->4 4->5

If computer 1 has a message then the output will be: 1 4 5
 
If computer 3 has a message then the output will be: 3 2 4 5


The program uses the data structures list and stack.
