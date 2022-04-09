#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

struct Point {
	int x = 0; 
	int y = 0;
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
	public:
	int get_x() const { return x; }
	void set_x(int x) { this->x = x; }
	int get_y() const { return y; }
	void set_y(int y) { this->y = y; }
	~Point () {}
};
ostream& operator <<(ostream& outs, const Point p) {
	//outs << setprecision(2) << fixed;
	outs << "Position X: " << p.x << "\tY: " << p.y << endl; 
	//outs << "(" << p.x << "," << p.y << ")";
	return outs;
}
