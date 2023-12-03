# pragma once 
#include "Personal2DVector.h".
#include <ist>

class Snake {
private:
	list<P2DVec> body;
public:
	list<P2DVec>::iterator head() { return this.body.begin(); }
	
};