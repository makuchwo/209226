#include <iostream>
#include <cstdlib>
#include <math.h>
#ifndef ARRAY1H
#define ARRAY1H

class darray
{
private:
    int* tab;
    int size;
public:
    darray(int, bool);
    ~darray(bool);
    int getsize(bool);
    int get_elem(int, bool);
    void set_elem(int, int, bool);
    int* get_array(bool);
    void set_array(int*, bool);
    void print_array(bool);
    void resize(int, bool);
};
int darray::getsize(bool DM)
{
    if(DM){cout<<"array size: "<<size<<endl;}
    return size;
}
int darray::get_elem(int index; bool DM)
{
    if(DM){cout<<"----getting element with index "<<index<<"----"<<endl;}
    return tab[index];
}
void darray::set_elem(int index, int value, bool DM)
{
    if(DM){cout<<"----setting element with index "<<index<<"to value: "<<value<<"----"<<endl;}
    tab[index]=value;
    if(DM){cout<<"...done"<<endl;}
}
int* darray::get_array(bool DM)
{
    if(DM){cout<<"----getting array----"<<endl;}
    return tab;
}
void darray::set_array(int input[], bool DM)
{
    if(((sizeof input)/(sizeof int))>size)
    {
        cout<<"Error: input array is too big. Aborting operation..."<<endl;
    }
    else
        for (i=0; i<((sizeof input)/(sizeof int)); i++)
        {
            if(DM){cout<<"----setting element with index "<<i<<"to value "<<input[i]<<"----"<<endl;}
            tab[i]=input[i];
            if(DM){cout<<"...done"<<endl;}
        }
}
void darray::print_array()
{
    for(i=0;i<size;i++)
    {
        cout<<"The element with index "<<i<<" has value "<<tab[i]<<endl;
    }
}
void darray::resize(int increase, bool DM)
{
    if(DM){cout<<"----creating temp----"<<endl;}
    int temp[size] = tab;
    if(DM){cout<<"...done"<<endl;}
    if(DM){cout<<"resizing array"<<endl;}
    size = size+increase;
    delete tab[];
    delete tab;
    tab = new int[size];
    if(increase>=0)
    {
        for(int i=0; i<size-increase; i++)
        {
            tab[i] = temp[i];
        }
    }
    else
    {
        for(int i=0; i<size; i++)
        {
            tab[i] = temp[i];
        }
    }
}
darray::darray(int init, bool DM;)
{
    if(DM){cout<<"----initializing array----"<<endl;}
    tab = new int[init];
    size=init;
    if(DM){cout<<"...done"<<endl;}
    if(DM){cout<<"array size is: "<<size<<endl;}
}
#endif // ARRAY1H
