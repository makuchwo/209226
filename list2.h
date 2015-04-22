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
    int quicksortMedianaZTrzech(int lewy, int prawy);
    int quicksortSkrajnyElement(int lewy, int prawy);
    int Zamien(int q1, int q2);
    int idz(int indeks)const;


void KopcowanieDolem(int ojciec,int ostatni);
void BudujKopiec(int ostatni);
void KopcowanieGora(int ostatni);
void heapsort(int ostatni);

    dllist();
    ~dllist();

};



#endif
