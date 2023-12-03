# pragma once
#include <set>
#include "Personal2DVector.h"

class FruitGenerator {
private:
	std::set<P2DVec> freeCells;
public:
	// initialize the set with n*m-1
	FruitGenerator(P2DVec head, int n, int m);

};