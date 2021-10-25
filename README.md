Bank simulation

1.1 Algorithm Design
Linked List 
In a singly linked list, for accessing any node of linked list, we start traversing from the first node. If we are at any node in the middle of the list, then it is not possible to access nodes that precede the given node. This problem can be solved by slightly altering the structure of singly linked list. In a singly linked list, next part (pointer to next node) is NULL, if we utilize this link to point to the first node then we can reach preceding nodes. Refer this for more advantages of circular linked lists.


Insertion 
A node can be added in three ways: 
•	Insertion in an empty list
•	Insertion at the beginning of the list
•	Insertion at the end of the list
•	Insertion in between the nodes
Insertion in an empty List 
Initially, when the list is empty, last pointer will be NULL. 


 


 


 
Time complexity:
circular singly linked list can be done in O(1) time.
