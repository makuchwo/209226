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
        void file(string, bool);
        string generate_data(int, bool);
        void test(list<int>, int, int, int, bool);
        benchmark(int, bool);
        ~benchmark();
};


benchmark::~benchmark(){
    delete [] data;
    delete data;
}

benchmark::benchmark(int array_size, bool Debug_Mode)
{
    data = new int[array_size];
    if(Debug_Mode)
    {
        cout<<"rozmiar tablicy wynosi "<<array_size<<endl;
    }
}

string benchmark::generate_data(int array_size, bool Debug_Mode)
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
 j = rand(); //losuj liczbe
 j = j%100;
 if(Debug_Mode)
 {
    cout << j << endl; //wypisz na ekran
 }
 if (i==0)
    plik <<j;
 else
    plik << endl << j; //zapisz liczbe do pliku
 }
 plik.close();
 return filename;
}

void benchmark::file(string filename, bool Debug_Mode)
{/*wczytanie pliku txt*/
    if(Debug_Mode)
    {
        cout<<"Wczytuje plik "<<filename<<endl;
    }
    int j;
    int i=0;
    fstream plik; //zadeklarowanie obiektu strumieniowego typu fstream
    //pod nazwa "plik"
    plik.open(filename.c_str(), ios::in); //otworz plik do odczytu
    if(Debug_Mode)
    {
        cout<<"Wczytano plik"<<endl;
    }
    if ( plik.is_open())
        { //jezeli plik zostal otwarty
            if(Debug_Mode)
            {
                cout<<"Plik jest otwarty"<<endl;
            }
            while( !plik.eof() ) //dopoki nie spotkasz koniec pliku.
            {
                plik >> j; //czytaj liczbe z pliku
                if(Debug_Mode)
                {
                    cout<<"wczytano liczbe "<<j<<" z pliku"<<endl;
                }
                data[i]=j;
                if(Debug_Mode)
                {
                cout<<"wczytano "<<j<<endl;
                }
                i++;
            }
            plik.close();
            if(Debug_Mode)
            {
            cout<<"zamknieto plik"<<endl;
            }
        }
    else
        cout<<"nie otwarto pliku"<<endl;
}
void benchmark::test(list<int> lista, int initial,int steps, int repetitions, bool Debug_Mode)
{/*Pisane bezposrednio pod liste. Modyfikacja tej funkcji bedzie niezbedna do badania jakichkolwiek innych programow*/
    int i;
    int j;
    int k;
    int l;
    double milisec;
    double* total_time = new double[repetitions];
    double* result_time = new double[steps];
    double mean_time=0;
    int amount_of_data=initial;
    for(i=0; i<steps; i++)
    {
        if(Debug_Mode)
        {
            cout<<"liczba danych w powtorzeniu"<<amount_of_data<<endl;
            cout<<"krok "<<i+1<<endl;
        }
        for(j=0;j<repetitions;j++)
        {
            if(Debug_Mode)
            {
                cout<<"powtorzenie "<<j+1<<endl;
            }
            for(k=0; k<amount_of_data; k++)
            {
                if(Debug_Mode)
                {
                    cout<<"pushing "<<data[k]<<endl;
                }
                lista.push_back(data[k]); //przypisanie okreslonej ilosci danych do listy
            }
            list<int>::iterator it;
            /*stoper start*/
            LONGLONG Frequency, CurrentTime, LastTime;
            double TimeScale;
            QueryPerformanceFrequency( (LARGE_INTEGER*) &Frequency);
            TimeScale = (1.0/Frequency)*1000.0;
            QueryPerformanceCounter( (LARGE_INTEGER*) &LastTime);

            //stoper mierzy czas dla tej petli

            for (list<int>::iterator it=lista.begin(); it != lista.end(); ++it)
            {
                if(Debug_Mode)
                {
                    cout<<"liczba przed zmiana: "<<*it<<endl;
                }
                *it=*it*2;
                if(Debug_Mode)
                {
                    cout<<"liczba po zmianie: "<<*it<<endl;
                }
            }

            QueryPerformanceCounter( (LARGE_INTEGER*) &CurrentTime);
            milisec = (CurrentTime-LastTime)*TimeScale;
            total_time[j]=milisec;
            mean_time = mean_time+total_time[j];
            if(Debug_Mode)
            {
                cout<<"czas: "<<total_time[j]<<endl;
            }
            /*stoper stop*/
            for(int m=0; m<amount_of_data; m++)
            {
                lista.pop_back(); //oczyszczenie listy i przygotowanie do kolejnej fazy testu
                if(Debug_Mode)
                {
                    cout<<"popping"<<endl;
                }
            }
            mean_time = mean_time/repetitions;
            if(Debug_Mode)
            {
                cout<<"sredni czas: "<<mean_time<<endl;
            }
            result_time[i]=mean_time;
        }
        amount_of_data = amount_of_data*10;
    }
    cout<<"Wpisz nazwe pliku w ktorym zapisany zostanie wynik";
    cout<<endl;
    string filename;
    cin>>filename;
    filename.append(".txt");
    fstream plik;
    plik.open(filename.c_str(),ios::out);
    amount_of_data=initial;
    for( i = 0; i < steps; i++ )
        {
            plik<<"Dla "<<amount_of_data<<" danych :";
                j=total_time[i];
            plik << result_time[i]<<endl;
            amount_of_data = amount_of_data*10;
        }
    plik<<endl;
    plik.close();
    delete[] total_time;
    delete[] result_time;
}
