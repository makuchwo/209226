#include "cell.h"
#include <iostream>

using namespace std;

void cell::set_value(int value){
	this->value=value;
}

int cell::get_value(){
	return value;
}

cell::~cell(){
}

cell::cell(int value){
	this->value=value;
	next=NULL;
	prev=NULL;
}

cell * cell::get_next(){

	return this->next;
}

void cell::set_next(cell * next){
	this->next=next;
}

cell * cell::get_prev(){
	return this->prev;
}

void cell::set_prev(cell * prev){
	this->prev=prev;
}
