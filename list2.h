#include <iostream>
#include <math.h>
#include <ctime>
#include "cell.h"
#ifndef  LIST2H
#define  LIST2H

using namespace std;

class dllist{
	int size;
	cell * first;

public:
	void append(cell * other);
	int add(cell * other, int where);
	cell * get_list();
	void set_list(cell * new_first);
	void print_list();
	int delete_cell(int index);
	void pop();

	int get_size()const { return size; }
    int quicksort(int lewy, int prawy);
    int Zamien(int q1, int q2);
    int idz(int indeks)const;

void KopcowanieDolem(int ojciec,int ostatni);
void BudujKopiec(int ostatni);
void KopcowanieGora(int ostatni);
void heapsort(int ostatni);

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




int dllist::idz(int indeks)const
    {
        if(indeks<0) { cout << "blad1" << endl; return -1; }
        if(indeks>=size) { cout << "blad2" << endl; return -1; }
        if(first==NULL) {cout << "blad3" << endl; return -1; }

        cell *wsk=first;
        for(int i=0;i<indeks;i++)
        {
            wsk=wsk->get_next();
        }
        return wsk->get_value();
  //      cout << wsk->get_value() << endl;
    }


 int dllist::Zamien(int q1, int q2)
    {
        if(q1==q2)
        {
            return 0;
        } else {
        int tmp=idz(q1);
        int tmp2=idz(q2);

       delete_cell(q1);
       add(new cell(tmp2),q1);

        delete_cell(q2);
        add(new cell(tmp),q2);
        }
        return 0;
    }



int dllist::quicksort(int lewy, int prawy)
        {
            int i=lewy;
            int j=prawy;
            int piwot=idz((lewy+prawy)/2);
            do
            {
                while(idz(i)<piwot)
                    i++;
                while(idz(j)>piwot)
                    j--;

                if(i<=j)
                {
                    Zamien(i,j);
                    i++;
                    j--;
                }
            }while(i<=j);

            if(lewy<j)   quicksort(lewy,j);
            if(prawy>i)  quicksort(i,prawy);
        }

 void dllist::KopcowanieDolem(int ojciec,int ostatni)
    {
    int dziecko;
    dziecko=2*ojciec;
        while(dziecko<=ostatni)
        {
            if((dziecko+1<=ostatni)&&(idz(dziecko+1)>idz(dziecko)))
            dziecko++;
                if(idz(ojciec)<idz(dziecko))
                Zamien(ojciec,dziecko);

        ojciec=dziecko;
        dziecko=2*ojciec;
        }
    }

    void dllist::BudujKopiec(int ostatni)
    {
    int i;
        for(i=ostatni/2;i>0;i--)
            KopcowanieDolem(i,ostatni);
    }


    void dllist::KopcowanieGora(int ostatni)
    {
    int ojciec, dziecko;
    int tmp;
    ojciec=1;
    dziecko=2*ojciec;
        while(dziecko<=ostatni)
        {
            if((dziecko+1<=ostatni)&&(idz(dziecko+1)>idz(dziecko)))
            dziecko++;

        Zamien(ojciec,dziecko);
        ojciec=dziecko;
        dziecko=2*ojciec;
        }
            while((ojciec>1)&&(idz(ojciec)>idz(ojciec/2)))
            {
            tmp=ojciec/2;
            Zamien(ojciec,tmp);
            ojciec=ojciec/2;
            }
    }

    void dllist::heapsort(int ostatni)
    {
    int l=1;
    BudujKopiec(ostatni);
        while(ostatni>1)
        {
        Zamien(l,ostatni);
        ostatni--;
        KopcowanieGora(ostatni);
        }
    }







/* Usuwa element o zadanym indeksie */
/* Zwraca -1 w przypadku niepowodzenia */

int dllist::delete_cell(int index){

	cell *destination = first;

	if(index<0||first==NULL||index>=size)
    {
        cout << "BLLLADDD" << endl;
        return -1;
    } else

   if(size==1)
    {
        if(index==0)
        {
            --size;
            first=NULL;
            return destination->get_value();
        } else
        cout << "tu blad. rozmiar 1, index: " << index <<  endl;
        return -1;
    } else


	if(index==0){
		first->get_next()->set_prev(NULL);
		first=first->get_next();
		--size;
		return destination->get_value();
		delete destination;
	} else

if(index==size-1)
{
	for(int i=0; i<index; i++){
		destination=destination->get_next();
	}

    cell * before = destination->get_prev();
    before->set_next(NULL);

    --size;
    return destination->get_value();
	delete destination;
} else

if(index==1)
{
		destination=destination->get_next();
		destination=destination->get_next();

	cell * before = destination->get_prev();
	cell * after = destination->get_next();

	after->set_prev(before);
	before->set_next(after);
	--size;
	  return destination->get_value();
	delete destination;

} else

	for(int i=0; i<index; i++){
		destination=destination->get_next();
	}


	cell * before = destination->get_prev();
	cell * after = destination->get_next();

	after->set_prev(before);
	before->set_next(after);

    --size;
    return destination->get_value();
	delete destination;
}



/* getter : first */
cell * dllist::get_list(){
	return first;
}

/* setter : first */
void dllist::set_list(cell * new_first){
	this->first=new_first;
	size++;
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
//znajdŸ jej rodzica i usuñ
	while(rubbish_parent!=first){
		rubbish_parent = rubbish->get_prev();
		delete rubbish;
		rubbish_parent->set_next(NULL);
		rubbish=rubbish_parent;
	}
//zosta³a ju¿ tylko komórka first
	delete first;
}


/* Dodaje element na koniec listy */

void dllist::append(cell * other){

	if(this->first==NULL){
		this->first=other;
		++size;
		return;
	}

	cell * destination = first;

	while(destination->get_next()!=NULL){
		destination=destination->get_next();
	}

	destination->set_next(other);
	other->set_prev(destination);

	++size;

}

/* Wstawia element w wyznaczone miejsce */
/* Zwraca 0, jesli sie udalo, -1 w. p.p. */
int dllist::add(cell * other, int where){

	if(where>size||where<0){
        cout << "tu blad2" << endl;
		return -1;
	}

	cell * destination = first;
	cell * dest2 = first;

    if(where==size)
    {
        append(other);
    } else {

	if(where==0){
        other->set_next(first);
        first=other;
		++size;
	} else
	{

	for(int i=0; i<where; i++)
		destination=destination->get_next();


	for(int i=0; i<where-1; i++)
        dest2=dest2->get_next();

	other->set_next(destination);
	other->set_prev(dest2);

	destination->set_prev(other);
	dest2->set_next(other);

	++size;
	return 0;
	}
    }
}

#endif
