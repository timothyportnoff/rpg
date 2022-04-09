#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

struct Point {
    float x, y;
    //default
    //Point() = default;
    //Better constructor
    Point() {
	    x = 0;
	    y = 0;
    }
    //nondefault
    Point(int new_x, int new_y) {
        x = new_x;
        y = new_y;
    }
    void set_x(int x) { this->x = x; }
    void set_y(int y) { this->y = y; }
    ~Point () {}
};
ostream& operator <<(ostream& outs, const Point& p) {
    outs << setprecision(2) << fixed;
    outs << "(" << p.x << "," << p.y << ")";
    return outs;
}
