#include <iostream>
#include <math.h>
#ifndef  CELLH
#define  CELLH

class cell{

private:
/* Deklaracja pól */
    int value;
    cell * prev;

public:

/* Deklaracja funkcji */
	void set_value(int value);
	int get_value();
    void set_prev(cell * prev);
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
	prev=NULL;
}

cell * cell::get_prev(){
	return this->prev;
}

void cell::set_prev(cell * prev){
	this->prev=prev;
}


#endif // CELL
