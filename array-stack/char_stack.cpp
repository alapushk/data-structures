/* File: char_stack.cpp

  Implementation of functions for basic simple array-based implementation of a stack.

*/
#include "char_stack.h"// contains the declarations of the variables and functions.
#include <iostream>

char_stack::char_stack(){
    top_index=-1;   //indicates the empty array
}

void char_stack::push(char item){
    top_index = top_index +1;
    A[top_index] = item;
}

char char_stack::pop (){
    top_index = top_index - 1;
    return A[top_index];
}

char char_stack::top(){
    return A[top_index];
}

bool char_stack::empty(){
    return top_index == -1;
}

int char_stack::size(){
    return top_index+1;
}
// function to print the contents of the stack:
/*
void char_stack::print(){
    std::cout << "stack is:"<< std::endl;
    for (int i =0; i<=top_index; i++) {
        std::cout << A[i];
    }
    std::cout << std::endl;
}
*/
