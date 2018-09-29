#include "unstablesquare.h"
#include "window.h"
#include "square.h"
#include <string>
#include <sstream>
#include "board.h"
#include "match.h"
#include <iostream>
using namespace std;
UnstableSquare::UnstableSquare(int row, int col, int colour){
	this->row = row;
	this->col = col;
	this->colour = colour;
	
}

string UnstableSquare::print()
{
	string s = "";
	s += "_";
	s += "b";
	s += colour + '0';
	return s;
}

int UnstableSquare::notify(Board *b){
	int del = 0;
	int hole = 0;
	if(b->m)
	{
		hole = b->m->len;
	}
	if(hole==3)
	{
		for(int i=col-1;i<=col+1;i++)
		{
			del += b->deleteSq(row-1,i);
			del += b->deleteSq(row+1,i);
		}
		del += b->deleteSq(row,col-1);
		del += b->deleteSq(row,col+1);
	}
	if(hole==4)
	{
		for(int i=col-2;i<=col+2;i++)
		{
			del += b->deleteSq(row-2, i);
			del += b->deleteSq(row-1, i);
			del += b->deleteSq(row+1, i);
			del += b->deleteSq(row+2, i);
		}
		del += b->deleteSq(row-2, col-1);
		del += b->deleteSq(row-1, col+1);
		del += b->deleteSq(row+1, col-2);
		del += b->deleteSq(row+2, col+2);
	}
	return del;
}

void UnstableSquare::printToWindowSpecialType(Xwindow *w)
{
	int dim = 50;
	int x = col*dim;
	int y = row*dim;
	int offset = 10;
	int size = dim - (2*offset);
	w->fillRectangle(x+offset,y+offset,size,size,Square::black);
}