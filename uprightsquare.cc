#include "uprightsquare.h"
#include "board.h"
#include "window.h"
#include "square.h"
#include <string>
using namespace std;
UprightSquare::UprightSquare(int row, int col, int colour){
	this->row = row;
	this->col = col;
	this->colour = colour;
	this->isLocked = '_';
}
// UprightSquare::~UprightSquare(){}
string UprightSquare::print()
{
	string s = "";
	s += isLocked;
	s += "v";
	s += colour + '0';
	return s;
}

int UprightSquare::notify(Board *b){
	int del = 0;
	for(int i=0;i<row;i++)
	{
		del += b->deleteSq(i,col);
	}//row instead of 10 //0 to 10
	for(int i=row+1;i<10;i++)
	{
		del += b->deleteSq(i,col);
	}
	return del;
}

void UprightSquare::printToWindowSpecialType(Xwindow *w)
{
	int dim = 50;
	int x = col*dim;
	int y = row*dim;
	int lineLength = 10;
	w->fillRectangle((x + (lineLength * 0)), y, lineLength, dim, colour);
	w->fillRectangle((x + (lineLength * 1)), y, lineLength, dim, Square::black);

	w->fillRectangle((x + (lineLength * 2)), y, lineLength, dim, colour);
	w->fillRectangle((x + (lineLength * 3)), y, lineLength, dim, Square::black);

	w->fillRectangle((x + (lineLength * 4)), y, lineLength, dim, colour);
}