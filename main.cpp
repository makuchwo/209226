#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include "list2.h"
#include "cell.h"
#include "Stoper.hh"
#include <windows.h>


int main()
{

    srand(time(NULL));
    dllist *lista=new dllist();

    Benchmark(lista);

    return 0;
}

