#include <iostream>
#include <stdio.h>
#include "Menu.h"

using namespace std;



int main() {
    Ell* e ;
    Circle*  c;
    setlocale (LC_ALL,"");
    Menu *menu = new Menu(14);
    char str[40];
    sprintf(str, "���������������� ������");
    menu->setField(0, str);
    sprintf(str, "�������� �������");
    menu->setField(1, str);
    sprintf(str, "������� �������");
    menu->setField(2, str);
    sprintf(str, "��������� ����� �� ���������");
    menu->setField(3, str);
    sprintf(str, "��������� ������ �� ����");
    menu->setField(4, str);
    sprintf(str, "������� ������ �� n �����");
    menu->setField(5, str);
    sprintf(str, "���������������� ����������");
    menu->setField(7, str);
    sprintf(str, "�������� ����������");
    menu->setField(8, str);
    sprintf(str, "������� ����������");
    menu->setField(9, str);
    sprintf(str, "��������� ����� �� ���������");
    menu->setField(10, str);
    sprintf(str, "������� ������ �� n �����");
    menu->setField(11, str);
    sprintf(str, "�������� ������ �������");
    menu->setField(12, str);
    sprintf(str, "�������� ��������");
    menu->setField(13, str);
    sprintf(str, "������� ��������");
    menu->setField(14, str);
    menu->show(0, e, c);
    cout << "Hello, World!" << endl;
    return 0;
}