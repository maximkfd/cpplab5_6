//
// Created by 1 on 17.03.2015.
//

#include <cmath>
#include "Ell.h"
#include "Circle.h"

using namespace std;

Ell::Ell(double x, double y, double r, double R) {
    Ell::x = x;
    Ell::y = y;
    Ell::r = r;
    Ell::R = R;
}
Ell::Ell(double x, double y, double r, double R, double angle) {
    Ell::x = x;
    Ell::y = y;
    Ell::r = r;
    Ell::R = R;
    Ell::angle = angle;
}
double Ell::perimeter() {

    return 2*sqrt((r*r+R*R/2))*PI;
}
double Ell::square() {

    return PI*r*R;
}
bool Ell::in(Point p) {
    p.rotate(angle);
    double a = (p.x - x);
    a *= p.x - x;
    a /= Ell::r;
    a /= r;
    double b = p.y - y;
    b *= p.y - y;
    b /= R;
    b /= R;
    if (a+b <= 1){
        return true;
    }
    return false;
}
void Ell::print() {

}
vector<Point>* Ell::arr(int n) {
    vector<Point> *p = new vector<Point>(40);
    double da = 2*PI/n;
    double dx = (2*R)/(n/2+1);
    int i = 0;
    double ix = x-R;
    while (ix <= x+R){
        (*p)[i].x = ix;
        (*p)[i].y = sqrt(R*R-R*R*ix*ix/r/r);
        (*p)[i].rotate(angle);
        ix += dx;
        i++;
    }
    while (ix > x-R ){
        (*p)[i].x = ix;
        (*p)[i].y = sqrt(R*R-R*R*ix*ix/r/r);
        (*p)[i].rotate(angle);
        ix -= dx;
        i++;
    }
    return p;
}
void Ell::rotate(double angle) {

}

Point Ell::center() {
    Point p;
    p.x = x;
    p.y = y;
    return p;
}
double Ell::Radius() {
    return r;
}

void Point::rotate(double a) {
    x = x*cos(a) + y*sin(a);
    y = y*cos(a) - x*sin(a);
}