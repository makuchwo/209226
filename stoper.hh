#ifndef STOPER_HH_INCLUDED
#define STOPER_HH_INCLUDED


#include <windows.h>
#include <ctime>
#include <fstream>
#include "cell.h"
#include "list2.h"

using namespace std;

LARGE_INTEGER startTimer();


LARGE_INTEGER endTimer();

double liczSkrajny(dllist *obiekt, int N);

double liczSrodkowy(dllist *obiekt, int N);

double liczMedianaZTrzech(dllist *obiekt, int N);

int Benchmark(dllist *lista);

#endif // STOPER_HH_INCLUDED
