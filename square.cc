#include "square.h"
#include <iostream>
#include "window.h"

enum {White=0, Red, Green, Blue,Cyan,Yellow};
int Square::black = 7;
void Square::setWindow(Xwindow *w)
{
	x = w;
}
// Square::~Square(){}

int Square::getColour()
{
	return colour;
}

void Square::setColour(int colour){
	this->colour = colour;
}

void Square::setCoords(int row,int col,Xwindow *w){
	this->row = row;
	this->col = col;
	printToWindow(w);
}
void Square::setCoords(int row,int col){
	this->row = row;
	this->col = col;
	// printToWindow(w);
}

int Square::getRow(){
	return row;
}
int Square::getColumn(){
	return col;
}
void Square::setLock(char isLocked)
{
	this->isLocked = isLocked;
}
char Square::getLock()
{
	return isLocked;
}

void Square::printToWindow(Xwindow *w)
{
	if(w)
	{
		int dim = 50;
		w->fillRectangle(col*dim,row*dim,dim,dim,colour);
		printToWindowSpecialType(w);
		if(getLock()=='l')
		{
			printLockToWindow(w);
		}
		int x = col*dim;
		int y = row*dim;
		int l = 2;
		int offset = 0;
		int len = dim - (2*offset);
		w->fillRectangle(x+offset,y+offset,l,len,black);
		w->fillRectangle(x+offset,y+offset,len,l,black);
		w->fillRectangle(x+offset, y+dim-l-offset, len, l, black);
		w->fillRectangle(x+dim-l-offset, y+offset, l, len, black);

	}
}

void Square::printLockToWindow(Xwindow *w)
{
	int dim = 50;
	int x = col*dim;
	int y = row*dim;
	int l = 2;
	int offset = 10;
	int len = dim - (2*offset);
	w->fillRectangle(x+offset,y+offset,l,len,black);
	w->fillRectangle(x+offset,y+offset,len,l,black);
	w->fillRectangle(x+offset, y+dim-l-offset, len, l, black);
	w->fillRectangle(x+dim-l-offset, y+offset, l, len, black);
}