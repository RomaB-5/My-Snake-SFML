# pragma once 
#include "Tile.h".
#include <list>

class Snake {
private:
	list<Tile> body;

public:
	list<Tile>::iterator head() { return this.body.begin(); }
	
};