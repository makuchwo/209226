#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "stack.h"
#include "cell.h"
#include <ctime>
#include <windows.h>
#include "spine.h"




int main()
{
    cout<<"Benchmark czasowy"<<endl;
    stack * stos;
    cout<<"Lista ok"<<endl;
    int initial=10;
    int steps=1;
    int repetitions=1;
    int finish = 0;
    char choice;
    string input;
    int array_size=1;
    bool Debug_Mode = 0;

    cout<<"***INIT DONE***"<<endl<<endl;

    while (finish!=1)
    {
        stos = new stack();
        cout<<"Wybierz jedna z opcji:"<<endl<<"d/data/dane: zmien liczbe danych na ktorych bedzie pracowac program"<<endl;
        cout<<"s/steps/kroki: zmien liczbe krokow ktore wykona program w trakcie testu"<<endl;
        cout<<"r/repetitions/powtorzenia: zmien liczbe powtorzen w kazdym kroku"<<endl;
        cout<<"g/go/execute/wykonaj: wykonaj program przy wczesniej okreslonej liczbie danych"<<endl;
        cout<<"x/exit/wyjdz/zakoncz: zakoncz dzialanie programu"<<endl;
        cout<<"h/help/pomoc: wyswietl pomoc"<<endl;
        cout<<endl<<"wyjsciowe dane: 10 danych, 1 krok, 1 powtorzenie"<<endl<<endl;
        cin>>input;
        cout<<endl;
        if (input=="DebugMode=0")
        {
            choice = 'q';
        }
        else
        if (input=="DebugMode=1")
        {
            choice = 'z';
        }
        else
        if (input=="d"||input=="data"||input=="dane")
        {
            choice = 'd';
        }
        else
        if (input=="s"||input=="steps"||input=="kroki")
        {
            choice = 's';
        }
        else
        if (input=="r"||input=="repetitions"||input=="powtorzenia")
        {
            choice = 'r';
        }
        else
        if (input =="g"||input=="go"||input=="execute"||input=="wykonaj")
        {
            choice = 'g';
        }
        else
        if (input =="x"||input=="exit"||input=="wyjdz"||input=="zakoncz")
        {
            choice = 'x';
        }
        else
        if (input == "h"||input=="help"||input=="pomoc")
        {
            choice = 'h';
        }
        else
        {
            choice = '0';
        }

       switch(choice)
       {
       case 'q':
        {
            Debug_Mode = 0;
            break;
        }
       case 'z':
        {
            Debug_Mode = 1;
            break;
        }
       case 'd':
        {
            cout<<"poczatkowa liczba danych?"<<endl;
            cin>>initial;
            break;
        }
       case 's' :
        {
            cout<<endl<<"liczba krokow (10x wiecej danych w kazdym)?"<<endl;
            cin>>steps;
            break;
        }
       case 'r':
        {
            cout<<endl<<"liczba powtorzen w kazdym kroku?"<<endl;
            cin>>repetitions;
            break;
        }
       case 'g' :
        {
            array_size=initial;
            for(int i=1;i<steps;i++)
            {
                array_size = array_size*10;
            }
            benchmark* test1 = new benchmark(array_size, Debug_Mode);

            cout<<"***BENCHMARK CREATED***"<<endl;
            test1->file(test1->generate_data(array_size, Debug_Mode),Debug_Mode);
            cout<<"***DATA CREATED***"<<endl;
            test1->test(stos, initial, steps, repetitions, Debug_Mode);
            cout<<"***TEST DONE***"<<endl;
            delete test1;
            break;
        }
       case 'h':
           {
                cout<<"d/dane/data: zmien liczbe danych na ktorych bedzie pracowac program"<<endl;
                cout<<"s/kroki/steps: zmien liczbe krokow ktore wykona program w trakcie testu"<<endl;
                cout<<"r/powtorzenia/repetitions: zmien liczbe powtorzen w kazdym kroku"<<endl;
                cout<<"go/wykonaj/execute: wykonaj program przy wczesniej okreslonej liczbie danych"<<endl;
                cout<<"x/koniec/exit: zakoncz dzialanie programu"<<endl;
                cout<<"h/pomoc/help: wyswietl pomoc"<<endl;
                cout<<"DebugMode = 1 lub 0 aby wlaczyc lub wylaczyc wyswietlanie danych na ekran"<<endl;
                cout<<endl<<"wyjsciowe dane: 10 danych, 1 krok, 1 powtorzenie"<<endl;
              break;
           }
       case 'x':
           {
        finish = 1;
        break;
           }
       default :
           {
           cout<<"niewlasciwa opcja. Sprobuj ponownie"<<endl;
           }
        }
    }
 return 0;
}
