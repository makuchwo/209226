#include "stoper.hh"
#include <windows.h>
#include <ctime>
#include <fstream>

using namespace std;

LARGE_INTEGER startTimer()
{
LARGE_INTEGER start;
DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
QueryPerformanceCounter(&start);
SetThreadAffinityMask(GetCurrentThread(), oldmask);
return start;
}


LARGE_INTEGER endTimer()
{
LARGE_INTEGER stop;
DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
QueryPerformanceCounter(&stop);
SetThreadAffinityMask(GetCurrentThread(), oldmask);
return stop;
}


double liczSkrajny(dllist *obiekt, int N)
{
LARGE_INTEGER performanceCountStart,performanceCountEnd;

obiekt->append(new cell(0));
for(int i=0; i<N-1; i++)
{
obiekt->append(new cell(rand()%10));
}
performanceCountStart = startTimer(); //zapamiêtujemy czas pocz¹tkowy'
obiekt->quicksortSkrajnyElement(1,N-1);
performanceCountEnd = endTimer(); //zapamiêtujemy koniec czasu

double tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
return tm;
}

double liczSrodkowy(dllist *obiekt, int N)
{
LARGE_INTEGER performanceCountStart,performanceCountEnd;

obiekt->append(new cell(0));
for(int i=0; i<N-1; i++)
{
obiekt->append(new cell(rand()%10));
}
performanceCountStart = startTimer(); //zapamiêtujemy czas pocz¹tkowy'
obiekt->quicksort(1,N-1);
performanceCountEnd = endTimer(); //zapamiêtujemy koniec czasu

double tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
return tm;
}


double liczMedianaZTrzech(dllist *obiekt, int N)
{
LARGE_INTEGER performanceCountStart,performanceCountEnd;

obiekt->append(new cell(0));
for(int i=0; i<N-1; i++)
{
obiekt->append(new cell(rand()%10));
}
performanceCountStart = startTimer(); //zapamiêtujemy czas pocz¹tkowy'
obiekt->quicksortMedianaZTrzech(1,N-1);
performanceCountEnd = endTimer(); //zapamiêtujemy koniec czasu

double tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
return tm;
}



int Benchmark(dllist *lista){
    fstream plik;
    plik.open("pomiar_czasu_6.txt",ios::out);

    if(!plik.good())
    {
        cerr << "blad otwarcia pliku do zapisu" << endl;
        return -1;
    }

        cout << "Piwot - skrajny element tablicy." << endl;
        plik << "Piwot - skrajny element tablicy." << endl;
        cout << "Ilosc elementow sortowanych\t\t" << "Czas" << endl;
        plik << "Ilosc elementow sortowanych\t\t" << "Czas" << endl;

     for(int i=2; i<10; i++)
    {
        cout << i << "\t\t\t" << liczSkrajny(lista,i) << endl;
          plik << i << "\t\t\t" << liczSkrajny(lista,i) << endl;
    }

    for(int i=10; i<100; i+=10)
    {
        cout << i << "\t\t\t" << liczSkrajny(lista,i) << endl;
        plik << i << "\t\t\t" << liczSkrajny(lista,i) << endl;
    }
     for(int i=100; i<1000; i+=100)
    {
        cout << i << "\t\t\t" << liczSkrajny(lista,i) << endl;
         plik << i << "\t\t\t" << liczSkrajny(lista,i) << endl;
    }
    for(int i=1000; i<10000; i+=1000)
    {
        cout << i << "\t\t\t" << liczSkrajny(lista,i) << endl;
         plik << i << "\t\t\t" << liczSkrajny(lista,i) << endl;
    }




      cout << "Piwot - mediana z losowego ciagu trzech liczb." << endl;
        plik << "Piwot - mediana z losowego ciagu trzech liczb." << endl;
        cout << "Ilosc elementow sortowanych\t\t" << "Czas" << endl;
        plik << "Ilosc elementow sortowanych\t\t" << "Czas" << endl;

        for(int i=2; i<10; i++)
    {
        cout << i << "\t\t\t" << liczMedianaZTrzech(lista,i) << endl;
          plik << i << "\t\t\t" << liczMedianaZTrzech(lista,i) << endl;
    }

    for(int i=10; i<100; i+=10)
    {
        cout << i << "\t\t\t" << liczMedianaZTrzech(lista,i) << endl;
        plik << i << "\t\t\t" << liczMedianaZTrzech(lista,i) << endl;
    }
     for(int i=100; i<1000; i+=100)
    {
        cout << i << "\t\t\t" << liczMedianaZTrzech(lista,i) << endl;
         plik << i << "\t\t\t" << liczMedianaZTrzech(lista,i) << endl;
    }
    for(int i=1000; i<10000; i+=1000)
    {
        cout << i << "\t\t\t" << liczMedianaZTrzech(lista,i) << endl;
         plik << i << "\t\t\t" << liczMedianaZTrzech(lista,i) << endl;
    }




    cout << "Piwot - srodkowy element tablicy." << endl;
        plik << "Piwot - srodkowy element tablicy." << endl;
        cout << "Ilosc elementow sortowanych\t\t" << "Czas" << endl;
        plik << "Ilosc elementow sortowanych\t\t" << "Czas" << endl;

     for(int i=2; i<10; i++)
    {
        cout << i << "\t\t\t" << liczSkrajny(lista,i) << endl;
          plik << i << "\t\t\t" << liczSkrajny(lista,i) << endl;
    }

    for(int i=10; i<100; i+=10)
    {
        cout << i << "\t\t\t" << liczSkrajny(lista,i) << endl;
        plik << i << "\t\t\t" << liczSkrajny(lista,i) << endl;
    }
     for(int i=100; i<1000; i+=100)
    {
        cout << i << "\t\t\t" << liczSkrajny(lista,i) << endl;
         plik << i << "\t\t\t" << liczSkrajny(lista,i) << endl;
    }
    for(int i=1000; i<10000; i+=1000)
    {
        cout << i << "\t\t\t" << liczSkrajny(lista,i) << endl;
         plik << i << "\t\t\t" << liczSkrajny(lista,i) << endl;
    }

        cout << "Piwot - srodkowy element tablicy." << endl;
        plik << "Piwot - srodkowy element tablicy." << endl;
        cout << "Ilosc elementow sortowanych\t\t" << "Czas" << endl;
        plik << "Ilosc elementow sortowanych\t\t" << "Czas" << endl;

        for(int i=2; i<10; i++)
    {
        cout << i << "\t\t\t" << liczSrodkowy(lista,i) << endl;
          plik << i << "\t\t\t" << liczSrodkowy(lista,i) << endl;
    }

    for(int i=10; i<100; i+=10)
    {
        cout << i << "\t\t\t" << liczSrodkowy(lista,i) << endl;
        plik << i << "\t\t\t" << liczSrodkowy(lista,i) << endl;
    }
     for(int i=100; i<1000; i+=100)
    {
        cout << i << "\t\t\t" << liczSrodkowy(lista,i) << endl;
         plik << i << "\t\t\t" << liczSrodkowy(lista,i) << endl;
    }
    for(int i=1000; i<10000; i+=1000)
    {
        cout << i << "\t\t\t" << liczSrodkowy(lista,i) << endl;
         plik << i << "\t\t\t" << liczSrodkowy(lista,i) << endl;
    }

    plik.close();
    cout << "Zapisano" << endl;
    return 0;
}
