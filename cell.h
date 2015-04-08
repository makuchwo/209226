#include <iostream>
#include <math.h>
#ifndef  CELLH
#define  CELLH


class cell{
    int value;
    cell * next;
    cell * prev;

public:
	void set_value(int value);
	int get_value();
    void set_next(cell * next);
    void set_prev(cell * prev);
    cell * get_next();
    cell * get_prev();
    cell(int value);
    ~cell();

};

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


#endif // CELL




