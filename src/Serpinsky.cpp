#include <iostream>
#include "gwindow.h"
#include "math.h"

using namespace std;
/*
 * @param triangleApex - apex points of the triangle
 * @param sideLgth - side length of the main triangle
 * @param order - recursion depth
 */
void triangle(GWindow &gw, GPoint triangleApex, double sideLgth, int order);

int main(){
    int sideLgth;
    int order;
    cout << "Please, enter lenth of triangle side: ";
    cin >> sideLgth;
    cout << "Please, enter fractal order: ";
    cin >> order;
    int a = sideLgth/sqrt(3)*2; // double radius of the circumscribed circle
    GWindow gw(a,a);
    double startPointX = (gw.getWidth()-sideLgth)/2;
    double startPointY = (gw.getHeight() +  sqrt(3)/2*sideLgth)/2;
    GPoint startPoint(startPointX, startPointY);
    triangle(gw, startPoint, sideLgth,order);
    return 0;
}

void triangle(GWindow &gw, GPoint triangleApex, double sideLgth, int order){
    
    if (order == 0) { // when the order is reduced (or equal) to zero, we draw a simple triangle
        /*
         * @param triangleApex - apex points of the triangle
         * @param sideLgth - side length of the triangle
         * @param - direction angle from the initial point
         */
        triangleApex = gw.drawPolarLine(triangleApex, sideLgth, 0);
        triangleApex = gw.drawPolarLine(triangleApex, sideLgth, 120);
        triangleApex = gw.drawPolarLine(triangleApex, sideLgth, -120);        
    } else {
        // new coordinate of all three new triangles that are drawing recursively (left-right-top),
        // and every time fractal order reduced by one
        GPoint triangleApex1(triangleApex.getX(), triangleApex.getY());
        triangle(gw,triangleApex1, (sideLgth/2), order-1);
        GPoint triangleApex2(triangleApex.getX()+(sideLgth/2), triangleApex.getY());
        triangle(gw,triangleApex2, (sideLgth/2), order-1);
        GPoint triangleApex3(triangleApex.getX()+(sideLgth/4), triangleApex.getY()-(sqrt(3)*sideLgth)/4);
        triangle(gw,triangleApex3, sideLgth/2, order-1);
    }
}
