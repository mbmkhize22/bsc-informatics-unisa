# Data Structures (C++)

## Linked list
 * [Linked list Tutorial 01](https://www.youtube.com/watch?v=HKfj0l7ndbc)
 * [Linked list Tutorial 02 - Insert an element to linked list](https://www.youtube.com/watch?v=RNMIDj62o_o)
 * [Linked list Tutorial 03 - Double linked list, Back & Next](https://www.youtube.com/watch?v=-StYr9wILqo)
 * Arrays have fixed side but linked list is dynamic.
 * Random access is not allowed, because you don't know where the next element is. you only know the 1st element, then first element will point you to the next element.
 * Linked list need more memory compared to array, because it store 2 things, pointer and value.
### 3. Linked lists
#### 3.1. Linked lists
   * Differences between arrays and linked list:
     * Arrays:
       * Defined size
       * Insertion and deletion of elements are difficult 
       * Accessing the elements is permitted at random 
       * Elements are contiguous
       * No additional space is required for the pointer to the next element
       
     * Linked lists
       * Size is variable
       * Insertion and deletion of elements are simpler
       * No random access to the elements is possible
       * Elements are not contiguous
       * A pointer is required and requires additional memory 
	   
#### 3.2. Linked lists in C++
   * A node is declared as a class or struct
   * Data type of a node depends on the specific application
   * Link component of each node is a pointer
   ```struct
   struct nodeType
   {
		int info;
		nodeType*link;
   };
   ```
   * Variable declaration:
   * Basic operations of a linked list:
     * Search for an item in the list
	 * Insert an item in the list
	 * Delete an item from the list
	 * Traversal: given a pointer to the first node of the list, step through the nodes of the list
#### 3.3. Single linked list
   * A linked list is a collection of items (nodes) that contains two components:
     * Data
	 * Address (link) to the next node in the list. 
   * Example of a single linked list:
     * A singly linked list is a type of linked list that is unidirectional, i.e., it can be traversed in only one direction from the head to the last node.
	 * The link  points to the next node as seen in the LinkedList code:
   * Where:
     * The `Head` of the LinkedList contains the Address of the First Element in the List.
	 * The `Last node` (sometimes referred to as the `tail`) contains null in the pointer to indicate that this is the end of the LinkedList.
	 * As each node includes a pointer to the next node, the data elements in the linked list do not need to retain contiguous locations.  The nodes are dispersed throughout memory.
	 * It is rather easy to add or remove a data item as the address (pointer) only has to be updated.
	 *  As the number of nodes is not required to be declared at the start of the program, the number of elements can be dynamic.  The only cost is memory as the node has to store the pointer to the next node.