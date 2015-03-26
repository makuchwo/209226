#include <iostream>
#include <math.h>
#include "cell.h"
#ifndef  STACKH
#define  STACKH

using namespace std;

class stack{

private:
/* Deklaracja pól */
	int size;
	cell * last;

public:
/* Deklaracja funkcji */
	void append(cell * other);
	cell * get_stack();
	void set_stack(cell * new_last);
	void print_stack();
	void pop();

    stack();
    ~stack();

};

void stack::print_stack(){
	cell * current=last;

	while(current!=NULL){
		cout<<current->get_value()<<" ";
		current=current->get_prev();
	}

	cout<<endl;
}

/* getter : first */
cell * stack::get_stack(){
	return last;
}

/* setter : first */
void stack::set_stack(cell * new_last){
	this->last=new_last;
}


/* Konstruktor bazowy */
stack::stack(){
	last = NULL;
	size = 0;
}

/* Destruktor bazowy */
stack::~stack(){

	cell * rubbish = last;
	cell * rubbish_parent=NULL;
//znajdź jej rodzica i usuń
	while(rubbish_parent->get_prev()!=NULL)
    {
		rubbish_parent = rubbish->get_prev();
		delete rubbish;
		rubbish=rubbish_parent;
	}
//zostaje sam rubbish_parent
	delete rubbish_parent;
	delete last;
}

/* Dodaje element na koniec listy */

void stack::append(cell * other){

	if(this->last==NULL){
		this->last=other;
		return;
	}
	cell * destination = last;

	while(destination->get_prev()!=NULL)
    {
		destination=destination->get_prev();
	}
	destination->set_prev(other);
	size++;
}
void stack::pop()
{
    cell * temp = last;
    if (temp->get_prev()!=NULL)
    {
        last = last->get_prev();
        delete temp;
    }
    else
        {
            //usuwanie ostanitego elementu listy
            last = NULL;
            delete temp;
        }
    size --;
}
#endif
