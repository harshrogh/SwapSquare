#ifndef __LATERALSQUARE_H__
#define __LATERALSQUARE_H__


#include "square.h"
#include <string>

class Board;
class Xwindow;
class LateralSquare: public Square{

public:
	LateralSquare(int row, int col, int colour);
	// ~LateralSquare();
	std::string print();
	int notify(Board*);
	void printToWindowSpecialType(Xwindow *w);
};

#endif