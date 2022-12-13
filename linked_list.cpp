#include <iostream>
#include "linked_list.h"

using namespace std;

/*********************************************************************
** Function: Linked_List
** Description: default constructor initializes values

** Parameters: there are no parameters
** Pre-Conditions: there are no pre conditions
** Post-Conditions:  there are no post conditions
*********************************************************************/
Linked_List::Linked_List(){
    this->length = 0;
    this->head = NULL;
    this->first_pos = head;
    this->descending = false;
}

/*********************************************************************
** Function: get_length
** Description: gets the length of the list
** Parameters: there are no parameters
** Pre-Conditions: there are no pre conditions
** Post-Conditions:  there are no post conditions
*********************************************************************/
int Linked_List::get_length(){
    Node* temp = head;
    length = 0;
    while (temp != NULL){ //iterates until it reaches end
        length++;
        temp = temp->next;
    }

    return length;
}

/*********************************************************************
** Function: push_front
** Description: adds value at the front of the function
** Parameters: int value
** Pre-Conditions: there are no pre conditions
** Post-Conditions:  there are no post conditions
*********************************************************************/
void Linked_List::push_front(int value){
    Node* new_node = new Node();
    new_node->val = value;
    new_node->next = head;
    head = new_node; // makes the new node point to first position value

    length++;
}

/*********************************************************************
** Function:push_back
** Description: adds value at the end of the list
** Parameters: value
** Pre-Conditions: there are no pre conditions
** Post-Conditions:  there are no post conditions
*********************************************************************/
void Linked_List::push_back(int value){
    Node* new_node = new Node();
    new_node->val = value;
    new_node->next = NULL;
   
    Node* temp = head;
    while (temp->next != NULL){ // iterates until temp is at the end
        temp = temp->next;
    }
    temp->next = new_node;

    length++;
}

/*********************************************************************
** Function: insert
** Description: allows to insert value into list
** Parameters: int value, unsigned int target
** Pre-Conditions: there are no pre conditions
** Post-Conditions:  there are no post conditions
*********************************************************************/
// justification for more than 15 lines: I didn't feel modularization was necessary
// I thought it would make it hard to read
void Linked_List::insert(int value, unsigned int target){
    bool skip = false;
    //checks if they want it at front or end 
    if (target == 0){
        push_front(value);
        return;
    }
    else if(target == length){
        push_back(value);
        return;
    }

    if (target > length){ // needed to skip length increase
        skip = true;
    }

    int count = 0;
    Node* new_node = new Node(); // allocates new node
    Node* previous = head;
    Node* current = head->next;

    new_node->val = value;
    new_node->next = NULL;
   
    while (current != NULL){ // goes through list until target is reached
        if(count + 1 == target){
            new_node->next = current;
            previous->next = new_node;
        }
        previous = current;
        current = current->next;
        count++;
    }

    if (!skip){
        length++;
    }
}

/*********************************************************************
** Function: print
** Description: prints the function
** Parameters: there are no parameters
** Pre-Conditions: there are no pre conditions
** Post-Conditions:  there are no post conditions
*********************************************************************/
void Linked_List::print(){
    Node* temp = head;
    while (temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

/*********************************************************************
** Function: sort_ascending
** Description: used to call the sorting function
** Parameters: there are no parameters
** Pre-Conditions: there are no pre conditions
** Post-Conditions:  there are no post conditions
*********************************************************************/
void Linked_List::sort_ascending(){
    descending = false;
    head = merge_sort(head);
}

/*********************************************************************
** Function: sort_descending
** Description: used to call the sorting function
** Parameters: there are no parameters
** Pre-Conditions: there are no pre conditions
** Post-Conditions:  there are no post conditions
*********************************************************************/
void Linked_List::sort_descending(){
    descending = true;
    head = merge_sort(head);
}

/*********************************************************************
** Function: merge_sorted_list
** Description: merges the two lists together is order
** Parameters: Node* first_half, Node* second_half
** Pre-Conditions: there are no pre conditions
** Post-Conditions:  there are no post conditions
*********************************************************************/
Node* Linked_List::merge_sorted_list(Node* first_half, Node* second_half){
    if (first_half == NULL){
        return second_half;
    }
    if (second_half == NULL){
        return first_half;
    }
     Node* temp = NULL;
    

    if (!descending){
        temp = ascending_help(temp, first_half, second_half);
    }
    else{
        temp = descending_help(temp, first_half, second_half);
    }

    return temp;
}

/*********************************************************************
** Function: descending_help
** Description: if the user chooses ascending this function will sort it that way
** Parameters: Node* temp, Node* first_half, Node* second_half
** Pre-Conditions: descending is false
** Post-Conditions:  there are no post conditions
*********************************************************************/
Node* Linked_List::ascending_help(Node* temp, Node* first_half, Node* second_half){
    if (first_half->val <= second_half->val){
        temp = first_half;
        temp->next = merge_sorted_list(first_half->next, second_half);
    }
    else{
        temp = second_half;
        temp->next = merge_sorted_list(first_half, second_half->next);
    }
    return temp;
}

/*********************************************************************
** Function: descending_help
** Description: if the user chooses descending this function will sort it that way
** Parameters: Node* temp, Node* first_half, Node* second_half
** Pre-Conditions: descending is true
** Post-Conditions:  there are no post conditions
*********************************************************************/
Node* Linked_List::descending_help(Node* temp, Node* first_half, Node* second_half){
    if (first_half->val >= second_half->val){
        temp = first_half;
        temp->next = merge_sorted_list(first_half->next, second_half);
    }
    else{
        temp = second_half;
        temp->next = merge_sorted_list(first_half, second_half->next);
    }
    return temp;
}

/*********************************************************************
** Function: merge_sort
** Description: using recursion this splits up the list then merges them together
** Parameters: Node* head
** Pre-Conditions: there are no pre conditions
** Post-Conditions:  there are no post conditions
*********************************************************************/
Node* Linked_List::merge_sort(Node* head){
    if (head == NULL || head->next == NULL){
        return head;
    }

    Node* middle_node = find_middle_node(head);
    Node* second_half_start = middle_node->next;
    middle_node->next = NULL;
    
    Node* first_half = merge_sort(head);
    Node* second_half = merge_sort(second_half_start);

    Node* sorted_list = merge_sorted_list(first_half, second_half);

    return sorted_list;
}  


/*********************************************************************
** Function: find_middle_node
** Description: finds the middle of the list
** Parameters: Node* head
** Pre-Conditions: head can't be null
** Post-Conditions:  there are no post conditions
*********************************************************************/
Node* Linked_List::find_middle_node(Node* head){
    if (head == NULL){
        return head;
    }

    Node* mid = head;
    Node* skip = head;

    while (skip->next != NULL && skip->next->next != NULL){
        skip = skip->next->next;
        mid = mid->next;
    }

    return mid;
}

/*********************************************************************
** Function: 
** Description: 
** Parameters: there are no parameters
** Pre-Conditions: there are no pre conditions
** Post-Conditions:  there are no post conditions
*********************************************************************/
void Linked_List::clear(){
    head = NULL;
}

/*********************************************************************
** Function: get_value
** Description: gets the first value in the linked list
** Parameters: there are no parameters
** Pre-Conditions: there are no pre conditions
** Post-Conditions:  there are no post conditions
*********************************************************************/
int Linked_List::get_value(){
    return first_pos->val;
}

/*********************************************************************
** Function: get_next
** Description: gets the next value in the linked list
** Parameters: there are no parameters
** Pre-Conditions: there are no pre conditions
** Post-Conditions:  there are no post conditions
*********************************************************************/
Node* Linked_List::get_next(){
    return first_pos->next;
}

/*********************************************************************
** Function: set_next
** Description: sets first position to the next
** Parameters: there are no parameters
** Pre-Conditions: there are no pre conditions
** Post-Conditions:  there are no post conditions
*********************************************************************/
void Linked_List::set_next(){
    first_pos = first_pos->next;
}

/*********************************************************************
** Function: get_head
** Description: returns head of node object
** Parameters: there are no parameters
** Pre-Conditions: there are no pre conditions
** Post-Conditions:  there are no post conditions
*********************************************************************/
Node* Linked_List::get_head(){
    return first_pos;
}

/*********************************************************************
** Function: get_first
** Description: assigns head to first position
** Parameters: there are no parameters
** Pre-Conditions: there are no pre conditions
** Post-Conditions:  there are no post conditions
*********************************************************************/
void Linked_List::get_first(){
    first_pos = head;
}

/*********************************************************************
** Function: set_first
** Description: sets the fist position of the list
** Parameters: there are no parameters
** Pre-Conditions: there are no pre conditions
** Post-Conditions:  there are no post conditions
*********************************************************************/
void Linked_List::set_first(){
    head->next = first_pos->next;
}

/*********************************************************************
** Function: count_prime
** Description: counts the number of primes in list
** Parameters: Linked_List &l
** Pre-Conditions: there are no pre conditions
** Post-Conditions:  there are no post conditions
*********************************************************************/
unsigned int count_prime(Linked_List &l){
    l.get_first();
    int prime_count = 0;
    while(l.get_head() != NULL){
        if ((l.get_value() % 2 != 0) && (l.get_value() > 0)){
            for (int i = 2; i < l.get_value(); i++){
                if(l.get_value() % i == 0){
                    break;
                }
                else if(i == l.get_value() - 1){
                    prime_count++;
                }
            } 
        } 
        if (l.get_value() == 2){
            prime_count++;
        }
        l.set_next();
    }

    return prime_count;
    l.get_first();
}

/*********************************************************************
** Function: user_choice
** Description: allows to user to chose an option
** Parameters: Linked_List& l
** Pre-Conditions: there are no pre conditions
** Post-Conditions:  user inputs q
*********************************************************************/
void user_choice(Linked_List& l){
    char user_choice = ' ';
    while (user_choice != 'q'){
        cout << endl << "How would you like to manipulate the linked list?" << endl;
        cout << "1. Get length of linked list" << endl;
        cout << "2. Print linked list" << endl;
        cout << "3. Push front" << endl;
        cout << "4. Push back" << endl;
        cout << "5. Insert" << endl;
        cout << "6. Sort ascending" << endl;
        cout << "7. Sort descending" << endl;
        cout << "8. Get prime count" << endl;
        cout << "9. Clear linked list" << endl;
        cout << "q. Quit" << endl << "Enter Choice: ";
        cin >> user_choice;
        cout << endl;

        direct_choice(user_choice, l);
    }
}

/*********************************************************************
** Function: direct_choice
** Description: directs user choice
** Parameters: char choice, Linked_List& l
** Pre-Conditions: there are no pre conditions
** Post-Conditions:  there are no post conditions
*********************************************************************/
// justificaiton for more than 15 lines : use of switch statement modularizes
// the program and it mostly made of cout statements
void direct_choice(char choice, Linked_List& l){
    int i, j;
    switch(choice){
        case '1': // print length
            cout << "Length: " << l.get_length();
            break;
        case '2': // prints the list
            l.print();
            break;
        case '3': // insersts value at front
            cout << "What value would you like to insert? ";
            cin >> i;
            cout << endl;
            l.push_front(i);
            break;
        case '4': // inserts value at back
            cout << "What value would you like to insert? ";
            cin >> i;
            cout << endl;
            l.push_back(i);
            break;
        case '5': // inserts value
            cout << "What value would you like to insert? ";
            cin >> i;
            cout << endl;
            cout << "Where would you like to insert? ";
            cin >> j;
            cout << endl;
            l.insert(i, j);
            break;
        case '6': // sorts ascending order
            l.sort_ascending();
            cout << "Sorted" << endl;
            break;
        case '7': // sorts descending order
            l.sort_descending();
            cout << "Sorted" << endl;
            break;
        case '8': // prime count
            cout << "Prime count: " << count_prime(l) << endl;
            break;
        case '9': // clears list
            l.clear();
            cout << "Cleared" << endl;
            break;
    }
}

/*********************************************************************
** Function: Linked_List
** Description: destructor frees memory
** Parameters: there are no parameters
** Pre-Conditions: there are no pre conditions
** Post-Conditions:  there are no post conditions
*********************************************************************/
Linked_List::~Linked_List(){
    if (this->head != NULL){
        delete this->head;
        this->head = NULL;
    }

    if (this->first_pos != NULL){
        delete this->first_pos;
        this->first_pos = NULL;
    }
}
