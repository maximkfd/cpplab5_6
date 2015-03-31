//
// Created by 1 on 17.03.2015.
//

#ifndef _LAB5_MENU_H_
#define _LAB5_MENU_H_

#include <iostream>
#include "Ell.h"
#include "Circle.h"

using namespace std;

class Menu {
private:
    class Field {
    public:
        int number;
        char text[40];
        Field(int, char[]);
        Field* next;

    };
    void setColor(int, int);
    int field_count;
    Field* head;
public:
    Menu(int);
    void setField(int, char[]);
    void show(int focused, Ell*, Circle*);

};


#endif //_LAB5_MENU_H_
