#include "queue.h"
#include <cstring> // For declaration of NULL
#include <iostream>
using namespace std;


//Constructor
Queue::Queue(){
    front_p = NULL;
    back_p = NULL;
    current_size = 0;
}

//Copy constructor
Queue::Queue(const Queue& q){
    front_p = NULL;  
    back_p = NULL;
    current_size = 0;
    node* current = q.front_p;
    if (q.front_p != NULL) {
        while (current != NULL) {
            enqueue(current->data);
            current = current->next;
        }
    }
}

//Destructor
Queue::~Queue(){
    node* current = front_p;
    while (current != NULL) {
        node* next = current->next;
        delete current;
        current = next;
    }
    front_p = NULL;
    back_p = NULL;
    current_size = 0;
    
}

// Enqueue
void Queue::enqueue( int item ){
    node* back = new node(item, NULL);
    if (back_p == NULL) { //empty queue
        back_p = back;
        front_p = back;
    }
    else{
    back_p->next = back;
    back_p = back;
    }
    current_size++;
    
}

// Dequeues the front item
int Queue::dequeue(){
    node* current = front_p;
    int value = current->data;
    front_p = current->next;
    current_size--;
    delete current;
    return value;
    
}

// Returns the front item without dequeuing it.
int Queue::front(){
    return front_p->data;
    
}

// Returns true iff the queue contains no items.
bool Queue::empty(){
    return current_size==0;
    
}

// Returns the current number of items in the queue.
int Queue::size(){
    return current_size;
    
}


// If <item> occurs in the queue more
// than once, remove all occurrences of <item> except the first.
// Return the number of elements removed.
int Queue::makeUnique(int item){
//when queue is empty:
	if(front_p == NULL){return 0;}
//when queue is not empty:
	else{
   		node* current = front_p->next;
    		node* previous = front_p;
    		int occurrences = 0;
		if( previous->data == item ){ //if item is the first in the queue
			occurrences++; // must be 1
		}
    		while (current != NULL) { //start going through the queue
        		if (current->data == item and occurrences == 0) { //1st occurrence is not in the front  
            			occurrences++; //must be 1
				current = current->next; //move the pointers one step ahead
				previous = previous->next;
        		}
			else if (current->data == item and occurrences > 0){ //find another occurrence
				previous->next = current->next;
				delete current;
				current = previous->next; //move curent only
				occurrences++;
                current_size--;
    			}
			else{
				current = current->next; //move the pointers one step ahead
				previous = previous->next;
			}
		}
        if (occurrences == 0) {
            return occurrences;
        }
		occurrences--;
		return occurrences;
	}
    
}

void Queue::print(){
    node* current = front_p;
    cout << endl;
    if (current == NULL) {
        cout << "~queue is empty~" << endl;
    }
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

