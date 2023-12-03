# pragma once
class Tile {
private:
	short x = 0, y = 0;
public:
	Tile(short x, short y) { this->x = x; this->y = y;}

	short get_x() { return this->x; }

	void set_x(short x) { this->x = x; }

	short get_y() { return this->y; }

	void set_y(short x) { this->y = y; }
	
};