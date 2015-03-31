//
// Created by 1 on 17.03.2015.
//

#ifndef _LAB5_ELLIPSE_H_
#define _LAB5_ELLIPSE_H_

#include <vector>
const double PI = 3.1415926535897;
using namespace std;
struct Point{
    double x,y;
    void rotate(double a);
};


class Ell {
private:
    double x,y,r,R,angle;
public:
    Ell(double x, double y, double r, double R, double angle);
    Ell(double x, double y, double r, double R);
    double perimeter();
    double square();
    bool in(Point p);
    void rotate(double angle);
    vector<Point>* arr(int n);
    void print();
    Point center();
    double Radius();
};


#endif //_LAB5_ELLIPSE_H_
