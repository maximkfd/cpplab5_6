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
    sprintf(str, "Инициализировать эллипс");
    menu->setField(0, str);
    sprintf(str, "Периметр эллипса");
    menu->setField(1, str);
    sprintf(str, "Площадь эллипса");
    menu->setField(2, str);
    sprintf(str, "Проверить точку на попадание");
    menu->setField(3, str);
    sprintf(str, "Повернуть эллипс на угол");
    menu->setField(4, str);
    sprintf(str, "Вернуть массив из n точек");
    menu->setField(5, str);
    sprintf(str, "Инициализировать окружность");
    menu->setField(7, str);
    sprintf(str, "Периметр окружности");
    menu->setField(8, str);
    sprintf(str, "Площадь окружности");
    menu->setField(9, str);
    sprintf(str, "Проверить точку на попадание");
    menu->setField(10, str);
    sprintf(str, "Вернуть массив из n точек");
    menu->setField(11, str);
    sprintf(str, "Провести прямую сечения");
    menu->setField(12, str);
    sprintf(str, "Периметр сегмента");
    menu->setField(13, str);
    sprintf(str, "Площадь сегмента");
    menu->setField(14, str);
    menu->show(0, e, c);
    cout << "Hello, World!" << endl;
    return 0;
}