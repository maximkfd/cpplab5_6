//
// Created by 1 on 17.03.2015.
//

#ifndef _LAB5_CIRCLE_H_
#define _LAB5_CIRCLE_H_


#include "Ell.h"

class Circle : public Ell {
private:
    struct Line {
        double a,b,c, alpha;
    };
    Line section;
public:
    Circle(double x, double y, double r);
    void addLine(double, double, double);
    double segmentSquare();
    double segmentPerimeter();
};



#endif //_LAB5_CIRCLE_H_
