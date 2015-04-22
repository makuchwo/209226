#include <iostream>
#include <math.h>
#ifndef  CELLH
#define  CELLH


class cell{
    short int value;
    cell * next;
    cell * prev;

public:
	void set_value(int value);
	int get_value();
    void set_next(cell * next);
    void set_prev(cell * prev);
    cell * get_next();
    cell * get_prev();
    cell(int value);
    ~cell();

};



#endif // CELL




