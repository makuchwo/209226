#include <iostream>
#include <math.h>
#include "cell.h"
#ifndef  LIST2H
#define  LIST2H

using namespace std;

class dllist{

private:
/* Deklaracja pól */
	int size;
	cell * first;

public:
/* Deklaracja funkcji */
	void append(cell * other);
	int add(cell * other, int where);
	cell * get_list();
	void set_list(cell * new_first);
	void print_list();
	int delete_cell(int index);
	void pop();

    dllist();
    ~dllist();

};

void dllist::print_list(){
	cell * current=first;

	while(current!=NULL){
		cout<<current->get_value()<<" ";
		current=current->get_next();
	}

	cout<<endl;
}

/* Usuwa element o zadanym indeksie */
/* Zwraca -1 w przypadku niepowodzenia, 0 w p.p */

int dllist::delete_cell(int index){

	cout<<"^Deleting cell nr "<<index<<"^"<<endl;

	cell * destination = first;

	if(index<0||first==NULL||index>=size) return -1;

	if(index==0){
		first->get_next()->set_prev(NULL);
		first=first->get_next();
		delete destination;
		return 0;
	}

	for(int i=1; i<=index; i++){
		destination=destination->get_next();
	}

	cell * before = destination->get_prev();
	cell * after = destination->get_next();

	after->set_prev(before);
	before->set_next(after);


	delete destination;
	return 0;



}

/* getter : first */
cell * dllist::get_list(){
	return first;
}

/* setter : first */
void dllist::set_list(cell * new_first){
	this->first=new_first;
}


/* Konstruktor bazowy */
dllist::dllist(){
	first = NULL;
	size = 0;
}

/* Destruktor bazowy */
dllist::~dllist(){

	cell * rubbish = first;
	cell * rubbish_parent=NULL;

//znajdz ostatnia komorke (usuwamy od ostatniej)
	while(rubbish->get_next()!=NULL){
		rubbish=rubbish->get_next();
	}

	cout<<"^mam ostania komorke^"<<endl;
    cell * temp = rubbish;
//znajdź jej rodzica i usuń
	while(rubbish_parent!=first){
		rubbish_parent = rubbish->get_prev();
		delete rubbish;
		rubbish_parent->set_next(NULL);
		rubbish=rubbish_parent;
	}
//została już tylko komórka first
	delete first;
}

/* Dodaje element na koniec listy */

void dllist::append(cell * other){

	if(this->first==NULL){
		this->first=other;
		return;
	}

	cell * destination = first;

	while(destination->get_next()!=NULL){
		destination=destination->get_next();
	}

	destination->set_next(other);
	other->set_prev(destination);

	size++;

}

/* Wstawia element w wyznaczone miejsce */
/* Zwraca 0, jesli sie udalo, -1 w. p.p. */
int dllist::add(cell * other, int where){

	if(where>=size||where<0){
		return -1;
	}

	cell * destination = first;

	if(where==0){
		this->first=other;
	}

	for(int i=1; i<=where; i++){
		destination=destination->get_next();
	}

	other->set_next(destination);
	destination->set_prev(other);

	size++;
	return 0;

}

#endif
