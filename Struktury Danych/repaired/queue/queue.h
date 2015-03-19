#include <iostream>
#include <math.h>
#include "cell.h"
#ifndef  QUEUEH
#define  QUEUEH

using namespace std;

class queue{

private:
/* Deklaracja pól */
	int size;
	cell * first;

public:
/* Deklaracja funkcji */
	void append(cell * other);
	cell * get_queue();
	void set_queue(cell * new_first);
	void print_queue();
	void pop();

    queue();
    ~queue();

};

void queue::print_queue(){
	cell * current=first;

	while(current!=NULL){
		cout<<current->get_value()<<" ";
		current=current->get_next();
	}

	cout<<endl;
}

/* getter : first */
cell * queue::get_queue(){
	return first;
}

/* setter : first */
void queue::set_queue(cell * new_first){
	this->first=new_first;
}


/* Konstruktor bazowy */
queue::queue(){
	first = NULL;
	size = 0;
}

/* Destruktor bazowy */
queue::~queue(){

	cell * rubbish = first;
	cell * rubbish_parent=NULL;
//znajdź jej rodzica i usuń
	while(rubbish_parent->get_next()!=NULL)
    {
		rubbish_parent = rubbish->get_next();
		delete rubbish;
		rubbish=rubbish_parent;
	}
//zostaje sam rubbish_parent
	delete rubbish_parent;
	delete first;
}

/* Dodaje element na koniec listy */

void queue::append(cell * other){

	if(this->first==NULL){
		this->first=other;
		return;
	}
	cell * destination = first;

	while(destination->get_next()!=NULL)
    {
		destination=destination->get_next();
	}
	destination->set_next(other);
	size++;
}
void queue::pop()
{
    cell * temp = first;
    if (temp->get_next()!=NULL)
    {
        first = first->get_next();
        delete temp;
    }
    else
        {
            //usuwanie ostanitego elementu listy
            first = NULL;
            delete temp;
        }
    size --;
}
#endif
