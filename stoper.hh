#ifndef STOPER_HH_INCLUDED
#define STOPER_HH_INCLUDED


#include <windows.h>
#include <ctime>
#include <fstream>

/*!
 *\file
  *\brief definicje funkcji zliczajacych czas operacji wypelnienia struktur danych
 */

/*!
 *\brief definicja funkcji StartTimer
 *Rozpoczyna pomiar czasu
 *Funkcja pobrana ze strony http://jaroslaw.mierzwa.staff.iiar.pwr.wroc.pl/
 */
LARGE_INTEGER startTimer()
{
LARGE_INTEGER start;
DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
QueryPerformanceCounter(&start);
SetThreadAffinityMask(GetCurrentThread(), oldmask);
return start;
}

/*!
 *\brief definicja funkcji endTimer
 *Konczy pomiar czasu
 *Funkcja pobrana ze strony http://jaroslaw.mierzwa.staff.iiar.pwr.wroc.pl/
 */
LARGE_INTEGER endTimer()
{
LARGE_INTEGER stop;
DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
QueryPerformanceCounter(&stop);
SetThreadAffinityMask(GetCurrentThread(), oldmask);
return stop;
}



double licz(dllist *obiekt, int N)
{
LARGE_INTEGER performanceCountStart,performanceCountEnd;

for(int i=0; i<N; i++)
{
obiekt->append(new cell(rand()%10));
}
performanceCountStart = startTimer(); //zapamiêtujemy czas pocz¹tkowy'
obiekt->quicksort(0,N-1);
performanceCountEnd = endTimer(); //zapamiêtujemy koniec czasu

double tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
return tm;
}


#endif // STOPER_HH_INCLUDED
