//
// Created by 1 on 17.03.2015.
//

#include <math.h>
#include "Circle.h"

Circle::Circle(double x, double y, double r): Ell(x,y,r,r) {
//    section = NULL;
}
void Circle::addLine(double a, double b, double c) {
    Circle::section.a = a;
    Circle::section.b = b;
    Circle::section.c = c;
    Point m = this->center();
    double d = (m.x*section.a + section.b*m.y + section.c)/sqrt(section.a*section.a+section.b*section.b);
    section.alpha = 2*acos(d/ Radius());


}
double Circle::segmentPerimeter() {
    Point c = this->center();
    return (this->section.alpha*Radius() + 2*Radius()*sin(section.alpha/2));

}
double Circle::segmentSquare() {
    return((Radius()*Radius()*section.alpha/2) - Radius()*Radius()*sin(section.alpha)/2);
}
