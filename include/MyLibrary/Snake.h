# pragma once 
#include "Personal2DVector.h".
#include <list>

class Snake {
private:
	std::list<P2DVec> body;
	P2DVec direction;
public:
	std::list<P2DVec>::iterator head() { return this->body.begin(); }

	void grow(void);
	
	void move(void);
};