#include "lateralsquare.h"
#include "board.h"
#include "square.h"
#include "window.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
LateralSquare::LateralSquare(int row, int col, int colour)
{
	this->row = row;
	this->col = col;
	this->colour = colour;
	this->isLocked = '_';
}
// LateralSquare::~LateralSquare(){}
string LateralSquare::print()
{
	string s = "";
	s += isLocked;
	s += "h";
	s += colour + '0';
	return s;
}

int LateralSquare::notify(Board *b){
   int del = 0;
   for(int i=0;i<col;i++)
   {
   	del += b->deleteSq(row,i);
   }//col instead of 10 
   for(int i=col+1;i<10;i++)
   {
   	del += b->deleteSq(row,i);
   }
   return del;
}

void LateralSquare::printToWindowSpecialType(Xwindow *w)
{
	int dim = 50;
	int x = col*dim;
	int y = row*dim;
	int lineLength = 10;
	w->fillRectangle(x, y, dim, lineLength, colour);
	w->fillRectangle(x, (y + lineLength), dim, lineLength, Square::black);

	w->fillRectangle(x, (y + (lineLength*2)), dim, lineLength, colour);
	w->fillRectangle(x, (y + (lineLength*3)), dim, lineLength, Square::black);

	w->fillRectangle(x, (y + (lineLength*4)), dim, lineLength, colour);}