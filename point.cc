#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class Point {
	private:
		int x = 0; 
		int y = 0;
	public:
		Point() {
			x = 0;
			y = 0;
		}
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

		ostream& operator <<(ostream& outs, const Point p) {
			//outs << setprecision(2) << fixed; //Set precision
			outs << "(" << p.x << ", " << p.y << ")";
			return outs;
		}
};
