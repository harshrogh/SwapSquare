#ifndef __UPRIGHTSQUARE_H__
#define __UPRIGHTSQUARE_H__

#include "square.h"
#include <string>
class Board;
class Xwindow;
class UprightSquare: public Square{

public:
	UprightSquare(int row, int col, int colour);
	// ~UprightSquare();
	std::string print();
	int notify(Board *b);
	void printToWindowSpecialType(Xwindow *w);
};

#endif