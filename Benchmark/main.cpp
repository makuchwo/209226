#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <list>
#include <ctime>
#include <windows.h>



using namespace std;

class benchmark
{
        int* data;
    public:
        void file(string);
        string generate_data(int);
        void test(list<int>, int, int, int);
        int getdatapiece(int);
        void resize_array(int);
        benchmark(int);
};



void benchmark::resize_array(int array_size)
{/*niezbedne do konstruktora*/
    int* temp = new int[array_size];
    delete data;
    data = temp;
    delete temp;
}



benchmark::benchmark(int array_size)
{/*Bardzo brzydkie rozwiazanie, ale nie mam pomyslu jak to zrobic ladniej*/
    resize_array(array_size);
}



string benchmark::generate_data(int array_size)
{/*generowanie danych*/
 int i, j, number;
 number = array_size;
 string filename;
 srand( time( NULL ) );
 cout<<"Wpisz nazwe pliku"<<endl;
 cin>>filename;
 filename.append(".txt");
 fstream plik;
 plik.open(filename.c_str(),ios::out);
 for( i = 0; i < number; i++ )
 {
 j = rand(); //losuj liczbê
 cout << j << endl; //wypisz na ekran
 plik << j << endl; //zapisz liczbê do pliku
 }
 plik.close();
 return filename;
}

void benchmark::file(string filename)
{/*wczytanie pliku txt*/
    cout<<"Wczytuje plik "<<filename<<endl;
    int j;
    int i=0;
    fstream plik; //zadeklarowanie obiektu strumieniowego typu fstream
    //pod nazw¹ "plik"
    plik.open(filename.c_str(), ios::in); //otwórz plik do odczytu
    cout<<"Wczytano plik"<<endl;
    if ( plik.is_open()){ //je¿eli plik zosta³ otwarty
            cout<<"Plik jest otwarty"<<endl;
            while( !plik.eof() ) //dopóki nie spotkasz koniec pliku
            {
                plik >> j; //czytaj liczbê z pliku
                cout<<"wczytano liczbe "<<j<<" z pliku"<<endl;
                data[i]=j;
                cout<<"wczytano "<<j<<endl;
                i++;
            }
            plik.close();
            cout<<"zamknieto plik"<<endl;
            }

    else
        cout<<"nie otwarto pliku"<<endl;
}
void benchmark::test(list<int> lista, int initial,int steps, int repetitions)
{/*Pisane bezposrednio pod liste. Modyfikacja tej funkcji bedzie niezbedna do badania jakichkolwiek innych programow*/
    int i;
    int j;
    int k;
    int l;
    int m=0;
    double milisec;
    double* total_time = new double[repetitions];
    double mean_time=0;
    int amount_of_data=initial;
    for(i=0; i<steps; i++)
    {
        cout<<"liczba danych w powtorzeniu"<<amount_of_data<<endl;
        cout<<"krok "<<i+1<<endl;
        for(j=0;j<repetitions;j++)
        {
            cout<<"powtorzenie "<<j+1<<endl;
            for(k=0; k<amount_of_data; k++)
            {
                cout<<"pushing "<<data[k]<<endl;
                lista.push_back(data[k]); //przypisanie okreslonej ilosci danych do listy
            }
            list<int>::iterator it;
            /*stoper start*/
            LONGLONG Frequency, CurrentTime, LastTime;
            double TimeScale;
            QueryPerformanceFrequency( (LARGE_INTEGER*) &Frequency);
            TimeScale = (1.0/Frequency)*1000.0;
            QueryPerformanceCounter( (LARGE_INTEGER*) &LastTime);
            for (list<int>::iterator it=lista.begin(); it != lista.end(); ++it)
            {
            cout<<"liczba przed zmiana: "<<*it<<endl;
            *it=*it*2;
            cout<<"liczba po zmianie: "<<*it<<endl;
            }
            QueryPerformanceCounter( (LARGE_INTEGER*) &CurrentTime);
            milisec = (CurrentTime-LastTime)*TimeScale;
            total_time[m]=milisec;
            mean_time = mean_time+total_time[m];
            cout<<"czas: "<<total_time[m]<<endl;
            m++;
            /*stoper stop*/
            mean_time = mean_time/repetitions;
            cout<<"sredni czas: "<<mean_time<<endl;
            for(j=0; j<amount_of_data; j++)
            {
                lista.pop_back(); //oczyszczenie listy i przygotowanie do kolejnej fazy testu
                cout<<"popping"<<endl;
            }
        }
        amount_of_data = amount_of_data*10;
    }
    delete total_time;
}

int main()
{
    cout<<"Benchmark czasowy, wersja 0.1 alpha tailored"<<endl;
    list<int> lista;
    int initial=10;
    int steps=1;
    int repetitions=1;
    int finish = 0;
    char choice;
    string input;
    int array_size=1;
while (finish!=1)
{
    cout<<"Wybierz jedna z opcji:"<<endl<<"d/data/dane: zmien liczbe danych na ktorych bedzie pracowac program"<<endl;
    cout<<"s/steps/kroki: zmien liczbe krokow ktore wykona program w trakcie testu"<<endl;
    cout<<"r/repetitions/powtorzenia: zmien liczbe powtorzen w kazdym kroku"<<endl;
    cout<<"g/go/execute/wykonaj: wykonaj program przy wczesniej okreslonej liczbie danych"<<endl;
    cout<<"x/exit/wyjdz/zakoncz: zakoncz dzialanie programu"<<endl;
    cout<<"h/help/pomoc: wyswietl pomoc"<<endl;
    cout<<endl<<"wyjsciowe dane: 10 danych, 1 krok, 1 powtorzenie"<<endl<<endl;
    cin>>input;
    cout<<endl;
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
        for(int i=0;i<steps;i++)
        {
            array_size = array_size*10;
        }
        benchmark test1(array_size);
        test1.file(test1.generate_data(array_size));
        test1.test(lista, initial, steps, repetitions);
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
