#include <iostream>
#include <cstdlib>
#include <fstream>
#include "list2.h"
#include "cell.h"
#include "Stoper.hh"
#include <windows.h>



int main()
{
    dllist *lista=new dllist();
    fstream plik;
    plik.open("pomiar_czasu_4.txt", ios::out);
    if(!plik.good())
    {
        cerr << "blad otwarcia pliku do zapisu" << endl;
    } else
    cout << "Pomiar czasu dla algorytmu sortowania szbkiego." << endl;
    cout << "Ilosc elementow listy\t\t Czas sortowania" << endl;


    for(int i=10; i<100; i+=10)
    {
        cout << i << "\t\t\t" << licz(lista,i) << endl;
        plik << i << "\t\t\t" << licz(lista,i) << endl;
    }

   for(int i=100; i<1000; i+=100)
    {
        cout << i << "\t\t\t" << licz(lista,i) << endl;
        plik << i << "\t\t\t" << licz(lista,i) << endl;
    }
       for(int i=1000; i<10000; i+=1000)
    {
        cout << i << "\t\t\t" << licz(lista,i) << endl;
        plik << i << "\t\t\t" << licz(lista,i) << endl;
    }
    cout << 10000 << "\t\t\t" << licz(lista,10000) << endl;
    plik << 10000 << "\t\t\t" << licz(lista,10000) << endl;


       cout << "Pomiar czasu dla algorytmu sortowania przez kopcowanie." << endl;
    cout << "Ilosc elementow listy\t\t Czas sortowania" << endl;


    for(int i=10; i<100; i+=10)
    {
        cout << i << "\t\t\t" << licz2(lista,i) << endl;
        plik << i << "\t\t\t" << licz2(lista,i) << endl;
    }

   for(int i=100; i<1000; i+=100)
    {
        cout << i << "\t\t\t" << licz2(lista,i) << endl;
        plik << i << "\t\t\t" << licz2(lista,i) << endl;
    }
       for(int i=1000; i<8001; i+=1000)
    {
        cout << i << "\t\t\t" << licz2(lista,i) << endl;
        plik << i << "\t\t\t" << licz2(lista,i) << endl;
    }


    plik.close();

    cout << "Zapisano." << endl;
    system("PAUSE");

    return 0;
}
