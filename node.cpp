#include <iostream>
#include "node.h"

using namespace std;

/*********************************************************************
** Function: Node
** Description: node destructor frees memory
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions:  n/a
*********************************************************************/
Node::~Node(){
    if (this->next != NULL){
        delete this->next;
        this->next = NULL;
    }
}