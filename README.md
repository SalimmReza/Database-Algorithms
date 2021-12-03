  <h1 align="center"> **Bank Simulation** </h1>
  
 ### Algorithm Design:
 
Linked List 
In a singly linked list, for accessing any node of linked list, we start traversing from the first node. If we are at any node in the middle of the list, then it is not possible to access nodes that precede the given node. This problem can be solved by slightly altering the structure of singly linked list. In a singly linked list, next part (pointer to next node) is NULL, if we utilize this link to point to the first node then we can reach preceding nodes. Refer this for more advantages of circular linked lists.


#### Insertion:

A node can be added in three ways: 

•	Insertion in an empty list

•	Insertion at the beginning of the list

•	Insertion at the end of the list

•	Insertion in between the nodes

Insertion in an empty List 

Initially, when the list is empty, last pointer will be NULL. 

<p align="center"><img src="https://user-images.githubusercontent.com/91980956/142001552-3e6d0f69-5542-4506-bfb1-4bd8cf1e4a20.png" width="600" height="400" /></p>
<p align="center"><img src="https://user-images.githubusercontent.com/91980956/142001577-498745ca-9ad3-40ad-936b-8b5d7edc55b1.png" width="600" height="400" /></p>


### Time complexity:
circular singly linked list can be done in O(1) time.


 <h1 align="center"> **Expression Conversion** </h1>

### Algorithm Design:
1. Scan the infix expression from left to right. 
2. If the scanned character is an operand, output it. 
3. Else, 
      1 If the precedence of the scanned operator is greater than the precedence of the operator in the stack(or the stack is empty or the stack contains a ‘(‘ ), push it.
      
      2 Else, Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator. After doing that Push the scanned operator to the stack. (If you encounter parenthesis while popping then stop there and push the scanned operator in the stack.) 
4. If the scanned character is an ‘(‘, push it to the stack. 
5. If the scanned character is an ‘)’, pop the stack and output it until a ‘(‘ is encountered, and discard both the parenthesis. 
6. Repeat steps 2-6 until infix expression is scanned. 
7. Print the output 
8. Pop and output from the stack until it is not empty.


<p align="center"><img src="https://user-images.githubusercontent.com/91980956/143436908-379eb898-df5f-4968-bfe7-e94d82e3ffac.jpg" width="600" height="400" /></p>


### Time complexity:

The time complexity of an infix to postfix expression conversion is O(N)


<h1 align="center"> **Huffman coding** </h1>
 
### Algorithm Design
There are mainly two major parts in Huffman Coding
1) Build a Huffman Tree from input characters.
2) Traverse the Huffman Tree and assign codes to characters.

Steps to build Huffman Tree
Input is an array of unique characters along with their frequency of occurrences and output is Huffman Tree.
1. Create a leaf node for each unique character and build a min heap of all leaf nodes (Min Heap is used as a priority queue. The value of frequency field is used to compare two nodes in min heap. Initially, the least frequent character is at root)



2. Extract two nodes with the minimum frequency from the min heap.
3. Create a new internal node with a frequency equal to the sum of the two nodes frequencies. Make the first extracted node as its left child and the other extracted node as its right child. Add this node to the min heap.
4. Repeat steps#2 and #3 until the heap contains only one node. The remaining node is the root node and the tree is complete.




