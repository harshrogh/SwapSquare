#include "psychedelicsquare.h"
#include "board.h"
#include "window.h"
#include "square.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
PsychedelicSquare::PsychedelicSquare(int row, int col, int colour ){
	this->row = row;
	this->col = col;
	this->colour = colour;
	this->isLocked = '_';
}
// PsychedelicSquare::~PsychedelicSquare(){}
string  PsychedelicSquare::print()
{
	string s = "";
	s += "_";
	s += "p";
	s += colour + '0';
	return s;
}

int PsychedelicSquare::notify(Board *b){
	int del = 0;
	Square ***t = b->getBoard();
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(t[i][j] && (i!=row || j!=col) && t[i][j]->getColour() == colour){
				del += b->deleteSq(i,j);
			}

		}
	}
	return del;
}

void PsychedelicSquare::printToWindowSpecialType(Xwindow *w)
{
	int dim = 50;
	int x = col*dim;
	int y = row*dim;
	int l = dim/3;
	int len = dim;
	int offset = dim/3;
	w->fillRectangle(x+offset,y,l,len,Square::black);
	w->fillRectangle(x,y+offset,len,l,Square::black);
}