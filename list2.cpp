#include "list2.h"
#include <iostream>
#include <cstdlib>

using namespace std;

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

        int tmp1=idz(q1);
        int tmp2=idz(q2);

        if(q1==0 && q2==1)
        {
int tmp1=idz(0);
int tmp2=idz(1);
dllist *nowa=new dllist();

for(int i=0; i<size; i++)
{
    nowa->append(new cell(idz(i)));
}


    nowa->delete_cell(1);
    nowa->add(new cell(tmp1),1);
    nowa->delete_cell(0);
    nowa->add(new cell(tmp2),0);

    for(int i=0; i<size; i++)
    {
        delete_cell(i);
        add(new cell(nowa->idz(i)),i);
    }
        } else {

        if(q2==size-1)
        {
            this->delete_cell(q2);
            this->append(new cell(tmp1));
            this->delete_cell(q1);
            this->add(new cell(tmp2),q1);
        } else {


       delete_cell(q1);
       add(new cell(tmp2),q1);

        delete_cell(q2);
        add(new cell(tmp1),q2);
        }
        }
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


int dllist::quicksortSkrajnyElement(int lewy, int prawy)
        {
            int i=lewy;
            int j=prawy;
            int piwot=idz(lewy);
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



        int dllist::quicksortMedianaZTrzech(int lewy, int prawy)
        {
            int i=lewy;
            int j=prawy;
            int x,y,z;
            int indeks, piwot;
            indeks=rand()%9;
            x=idz(indeks);
            y=idz(indeks+1);
            z=idz(indeks+2);

            if(x>=y && x>=z )
            {
                if(y>=z)
                    piwot=y;
                else
                    piwot=z;
            } else {

                if(y>=x && y>=z)
                {
                    if(x>=z)
                        piwot=x;
                    else
                        piwot=z;
                    } else {

            if(z>=x && z>=y)
            {
                if(x>=y)
                    piwot=x;
                else
                    piwot=y;
            }
                    }
            }

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



int dllist::delete_cell(int index)
{
     cell *pom2=first;
     int zm;

    if(index>=size || index<0) return -1;

    if(index==0)
    {
        int tmp=first->get_value();
        cell *pom=first->get_next();
        delete first;
        first=pom;
        size--;
        return tmp;
    } else


    if(index==size-1)
    {
        for(int i=0; i<index; i++)
            pom2=pom2->get_next();

        cell *before = pom2->get_prev();
        before->set_next(NULL);

        zm=pom2->get_value();
        size--;
        delete pom2;
        return zm;
    } else

    if(index==1)
    {
        cell *tmp1=first;
        tmp1=tmp1->get_next();

        int pom=tmp1->get_value();

        cell *after=tmp1->get_next();
        cell *before=tmp1->get_prev();

        after->set_prev(before);
        before->set_next(after);

        delete tmp1;
        size--;
        return pom;
    } else

    if(index>0)
    {
        for(int i=0; i<index; i++)
        pom2=pom2->get_next();

        cell *after = pom2->get_next();
        cell *before = pom2->get_prev();

        before->set_next(after);
        after->set_prev(before);


        zm=pom2->get_value();
        delete pom2;
        size--;
        return zm;
}
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
	delete first;
}



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
    } else

	if(where==0){
        other->set_next(first);
        first=other;
		++size;
	} else {

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
