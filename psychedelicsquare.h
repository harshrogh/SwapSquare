#ifndef __PSYCHEDELICQUARE_H__
#define __PSYCHEDELICQUARE_H__

#include "square.h"
#include <string>
class Board;
class Xwindow;
class PsychedelicSquare: public Square{

public:
	PsychedelicSquare(int row, int col, int colour);
	// ~PsychedelicSquare();
	std::string print();
	int notify(Board *b);
	void printToWindowSpecialType(Xwindow *w);
};

#endif