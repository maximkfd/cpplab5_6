//
// Created by 1 on 17.03.2015.
//

#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <wincon.h>
#include <winbase.h>
#include <winnt.h>
#include "Ell.h"
#include "Menu.h"

using namespace std;

void Menu::setColor(int text, int background) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD) ((background << 4) | text));
}

Menu::Menu(int f) {
    field_count = f;
    head = NULL;
}

Menu::Field::Field(int number, char text[]) {
    Field::number = number;
    for (int i = 0; i < strlen(text); i++) {
        Field::text[i] = text[i];
    }
    Field::text[strlen(text)] = '\0';
    Field::next = NULL;
}

void Menu::setField(int number, char name[]) {

    if (Menu::head == NULL) {
        head = new Field(number, name);
    } else {
        Field *f = head;
        while ((f->next != NULL)) {
            f = f->next;
        };
        Field *p = new Field(number, name);
        f->next = p;
    }


}

void Menu::show(int focused, Ell *e, Circle *c) {
    int symbol = 0;
    while (symbol != 27) {
        Field *f = head;
        for (int i = 0; i < field_count; i++) {
            if (i == focused) {
                setColor(0, 7);
            }
            printf("%d. %s\n", i + 1, f->text);
            setColor(7, 0);
            f = f->next;
        }
        symbol = getch();
        if (symbol == 224) {
            symbol = getch();
            switch (symbol) {
                case 80:
                    focused = (focused + 1) % field_count;
                    break;
                case 72:
                    if (focused == 0) {
                        focused = field_count - 1;
                    } else {
                        focused--;
                    }
                    break;
                default:
                    break;
            }
        } else {
            if (symbol == 13) {
                switch (focused) {
                    case 0: {
                        system("cls");
                        cout << "������� ��������� ���������� �������\nX: ";
                        double x, y, r, R;
                        cin >> x;
                        cout << "Y: ";
                        cin >> y;
                        cout << "������\n�� ��� �: ";
                        cin >> r;
                        cout << "�� ��� Y: ";
                        cin >> R;
                        e = new Ell(x, y, r, R, 0);
                    }
                        break;
                    case 1: {
                        system("cls");
                        cout << e->center().x;
                        cout << "�������� ������� = " << e->perimeter();
                        getch();
                    }
                        break;
                    case 2: {
                        system("cls");
                        cout << "������� ������� = " << e->square();
                        getch();
                    }
                        break;
                    case 3: {
                        system(("cls"));
                        cout << "������� ���������� �����: \nX: ";
                        Point p;
                        cin >> p.x;
                        cout << "\nY: ";
                        cin >> p.y;
                        if (e->in(p)) {
                            cout << "����� ������";
                        } else {
                            cout << "����� �������";
                        }
                        getch();
                    }
                        break;
                    case 4: {
                        system("cls");
                        cout << "������� ���� ";
                        double angle;
                        cin >> angle;
                        e->rotate(angle);
                    }
                        break;
                    case 5: {
                        system("cls");
                        cout << "������� ���������� �����\nN: ";
                        int n;
                        cin >> n;
                        vector<Point> *parr;
                        parr = e->arr(n);
                        for (int i = 0; i < n; i++) {
                            cout << (*parr)[i].x << " " << (*parr)[i].y << endl;
                        }
                        getch();
                    }
                        break;
                    case 6: {
                        system("cls");
                        cout << "������� ��������� ���������� ����������\nX: ";
                        double x, y, r;
                        cin >> x;
                        cout << "Y: ";
                        cin >> y;
                        cout << "�����: ";
                        cin >> r;
                        c = new Circle(x, y, r);
                    }
                        break;
                    case 7: {
                        system("cls");
                        cout << "�������� ���������� = " << c->perimeter();
                        getch();
                    }
                        break;
                    case 8: {
                        system("cls");
                        cout << "������� ���������� = " << c->square();
                        getch();
                    }
                        break;
                    case 9: {
                        system(("cls"));
                        cout << "������� ���������� �����: \nX: ";
                        Point p;
                        cin >> p.x;
                        cout << "\nY: ";
                        cin >> p.y;
                        if (c->in(p)) {
                            cout << "����� ������";
                        } else {
                            cout << "����� �������";
                        }
                        getch();
                    }
                        break;
                    case 10: {
                        system("cls");
                        cout << "������� ���������� �����\nN: ";
                        int n;
                        cin >> n;
                        vector<Point> *parr;
                        parr = c->arr(n);
                        for (int i = 0; i < n; i++) {
                            cout << (*parr)[i].x << " " << (*parr)[i].y << endl;
                        }
                        getch();
                    }
                        break;
                    case 11:
                        system("cls");
                        cout << "������� ��������� ������ Ax+By+C=0\nA: ";
                        double a, b, cc;
                        cin >> a;
                        cout << "B: ";
                        cin >> b;
                        cout << "C: ";
                        cin >> cc;
                        c->addLine(a, b, cc);
                        break;
                    case 12: {
                        system("cls");
                        cout << "�������� �������� = ";
                        cout << c->segmentPerimeter();
                        getch();
                    }
                        break;
                    case 13:
                        system("cls");
                        cout << "������� �������� = ";
                        cout << c->segmentSquare();
                        getch();
                    default:
                        break;
                }
            }
        }
        system("cls");
    }
}