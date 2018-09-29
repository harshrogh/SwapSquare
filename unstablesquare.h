#ifndef __UNSTABLESQUARE_H__
#define __UNSTABLESQUARE_H__

#include "square.h"
#include <string>
class Board;
class Xwindow;
class UnstableSquare: public Square{

public:
	UnstableSquare(int row, int col, int colour);
	
	std::string print();
	int notify(Board *b);
	void printToWindowSpecialType(Xwindow *w);
};

#endif