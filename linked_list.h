#ifndef LINKED_LIST
#define LINKED_LIST

#include "node.h"

class Linked_List {
private:
	unsigned int length; // the number of nodes contained in the list
	Node* head; // a pointer to the first node in the list
	// anything else you need...
	Node* first_pos;
	bool descending;
public:
	Linked_List();
	
	int get_length();
	// note: there is no set_length(unsigned int) (the reasoning should be intuitive)
   
	void print(); // output a list of all integers contained within the list
	void clear(); // delete the entire list (remove all nodes and reset length to 0)
   
	void push_front(int); // insert a new value at the front of the list 
	void push_back(int); // insert a new value at the back of the list 
	void insert(int val, unsigned int index); // insert a new value in the list at the specified index 

	void sort_ascending(); // sort the nodes in ascending order. You must implement the recursive Merge Sort algorithm
	// Note: it's okay if sort_ascending() calls a recursive private function to perform the sorting.
	void sort_descending(); // sort the nodes in descending order
	
	~Linked_List();

	// you can add extra member variables or functions as desired

	Node* merge_sort(Node*);
	Node* merge_sorted_list(Node*, Node*);
	Node* find_middle_node(Node*);
	Node* ascending_help(Node*, Node*, Node*);
	Node* descending_help(Node*, Node*, Node*);

	int get_value();
	Node* get_next();
	Node* get_head();
	void set_next();
	void get_first();
	void set_first();

	
};

unsigned int count_prime(Linked_List&); //count and return the number of prime numbers within the list
void user_choice(Linked_List&);
void direct_choice(char, Linked_List&);


#endif
