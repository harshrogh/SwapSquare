#ifndef __BASICSQUARE_H__
#define __BASICSQUARE_H__
#include "square.h"
//#include "window.h"
#include <string>
class Board;
class Xwindow;
class BasicSquare: public Square{

public:
	BasicSquare(int row, int col, int colour);
	~BasicSquare();
	std::string print();
	int notify(Board *);
	void printToWindowSpecialType(Xwindow *w);
};

#endif