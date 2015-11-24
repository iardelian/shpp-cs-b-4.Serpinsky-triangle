#include <iostream>
#include "gwindow.h"
#include "math.h"

using namespace std;

void triangle(GWindow &gw, GPoint apex, double sideLgth, int order);

int main() {
    int sideLgth;
    int order;
    cout << "Please, enter lenth of triangle side: ";
    cin >> sideLgth;
    cout << "Please, enter factorial order: ";
    cin >> order;
    int a = sideLgth/sqrt(3)*2; // double radius of the circumscribed circle
    GWindow gw(a,a);
    double stX = (gw.getWidth()-sideLgth)/2;
    double stY = (gw.getHeight() +  sqrt(3)/2*sideLgth)/2;
    GPoint stPoint(stX,stY);
    triangle(gw, stPoint, sideLgth,order);
    return 0;
}

void triangle(GWindow &gw, GPoint apex, double sideLgth, int order) {
    if (order == 0){ // when the order is reduced to zero, we draw a simple triangle
        apex = gw.drawPolarLine(apex, sideLgth, 0);
        apex = gw.drawPolarLine(apex, sideLgth, 120);
        apex = gw.drawPolarLine(apex, sideLgth, -120);
    }else{
        GPoint apex1(apex.getX(),apex.getY()); // new coordinate of all three new triangles
        triangle(gw,apex1,sideLgth/2,order-1); // that are drawing recursively (left-right-top)
        GPoint apex2(apex.getX()+sideLgth/2, apex.getY());
        triangle(gw,apex2,sideLgth/2,order-1);
        GPoint apex3(apex.getX()+sideLgth/4, apex.getY()-(sqrt(3)*sideLgth)/4);
        triangle(gw,apex3,sideLgth/2,order-1);
    }
}
