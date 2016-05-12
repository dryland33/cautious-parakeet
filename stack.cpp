#include "stack.hpp"

Stack::Stack(const int& size){
	dat_ptr = new char[size];       //make an array of chars
	the_top = 0;                    //point at the begining of it
	this->size = size;              //set size property of stack
}

bool Stack::is_empty(){
	return the_top == 0;              //true when no elements on stack  
}                                   //top->(index 0)   

bool Stack::is_full(){
	return the_top == size;           //true when capacity is reached
}                                   //top->(final index)

bool Stack::push(const char& elem){
	if (is_full()) return false;     //the cup shall not runneth over
	dat_ptr[the_top++] = elem;      //top equals pushed value, move forward one
	return true;                    //denotes a successful push
}

bool Stack::pop(char& elem){
	if (is_empty()) return false;    //you can't bleed a stone
	elem = dat_ptr[--the_top];      //move back to pop the highest value off the stack  
}

bool Stack::top(char& elem){
	if (is_empty()) return false;    //nothing in here
	elem = dat_ptr[elem - 1];        //what's on top?
	return true;                    //a successful look at the top value
}

