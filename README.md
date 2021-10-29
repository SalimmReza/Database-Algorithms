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

2. Expression conversion
3. 
4.1 Algorithm Design

5. Scan the infix expression from left to right. 
6. 
7. If the scanned character is an operand, output it. 
8. 
9. Else, 
      1 If the precedence of the scanned operator is greater than the precedence of the operator in the stack(or the stack is empty or the stack contains a ‘(‘ ), push it. 
      
      2 Else, Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator. After doing that Push the scanned operator to the stack. (If you encounter parenthesis while popping then stop there and push the scanned operator in the stack.) 
      
4. If the scanned character is an ‘(‘, push it to the stack. 
5. If the scanned character is an ‘)’, pop the stack and output it until a ‘(‘ is encountered, and discard both the parenthesis. 
6. 
7. Repeat steps 2-6 until infix expression is scanned. 
8. 
9. Print the output 
10. 
11. Pop and output from the stack until it is not empty.

Time complexity:

The time complexity of an infix to postfix expression conversion is O(N)

