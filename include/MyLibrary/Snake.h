# pragma once 
#include "Personal2DVector.h".
#include <list>

class Snake {
private:
	list<P2DVec> body;
public:
	list<P2DVec>::iterator head() { return this.body.begin(); }
	
};