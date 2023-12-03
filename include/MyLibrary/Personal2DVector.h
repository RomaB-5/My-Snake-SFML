# pragma once
class P2DVec {
private:
	short x = 0, y = 0;
public:
	P2DVec(){}
	P2DVec(short x1, short y1) { this->x = x1; this->y = y1;}

	short get_x() { return this->x; }

	void set_x(short x) { this->x = x; }

	short get_y() { return this->y; }

	void set_y(short x) { this->y = y; }
	
};