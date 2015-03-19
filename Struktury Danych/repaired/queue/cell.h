#include <iostream>
#include <math.h>
#ifndef  CELLH
#define  CELLH

class cell{

private:
/* Deklaracja pól */
    int value;
    cell * next;

public:

/* Deklaracja funkcji */
	void set_value(int value);
	int get_value();
    void set_next(cell * next);
    cell * get_next();
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
}

cell * cell::get_next(){

	return this->next;
}

void cell::set_next(cell * next){
	this->next=next;
}

#endif // CELL
