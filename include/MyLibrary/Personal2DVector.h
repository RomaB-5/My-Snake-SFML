#pragma once
#include <utility>

class P2DVec {
private:
	short x = 0, y = 0;
public:
	P2DVec(){}
	P2DVec(short x1, short y1) { this->x = x1; this->y = y1;}

	short get_x() { return this->x; }

	void set_x(short x) { this->x = x; }

	short get_y() { return this->y; }

	void set_y(short y) { this->y = y; }
	
	friend bool operator<(const P2DVec& d1, const P2DVec& d2) {
		return std::pair<short, short>(d1.x, d1.y) < std::pair<short, short>(d2.x, d2.y);
	}
};
