#include "basicsquare.h"
#include "window.h"
#include <string>

using namespace std;
BasicSquare::BasicSquare(int row,int col, int colour){
	this->row = row;
	this->col = col;
	this->colour = colour;
	this->isLocked = '_';
}
BasicSquare::~BasicSquare(){delete x;}
string BasicSquare::print()
{
	string s = "";
	s += isLocked;
	s += "_";
	s += colour + '0';
	return s;
}

int BasicSquare::notify(Board* b)
{
	return 0;
}

void BasicSquare::printToWindowSpecialType(Xwindow *w)
{
	//do nothing because basic square.
}