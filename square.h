#ifndef __SQUARE_H__
#define __SQUARE_H__


#include "square.h"
#include <string>
class Board;
class Xwindow;
class Square{
	protected:
	int row, col, colour;
	Xwindow *x;
	char isLocked;
public:
	//enum {BasicSquare=0, LateralSquare, UprightSquare, UnstableSquare, PsychedelicSquare} //square types
	//enum {White=0, Black, Red, Green, Blue, Cyan, Yellow, Magenta, Orange, Brown};
	
	static int black;
	void setCoords(int row, int col); 
	void setCoords(int row, int col,Xwindow*); 
 	
 	// void setType(int type);
 	int getColour();
 	void setColour(int);
 	
 	int getRow();
 	int getColumn();
 	void setWindow(Xwindow *x);
 	virtual std::string print()=0;
 	virtual int notify(Board *)=0;
 	 // virtual ~Square();
 	void setLock(char);
 	char getLock();
 	void printToWindow(Xwindow *w);
 	void printLockToWindow(Xwindow *w);
 	virtual void printToWindowSpecialType(Xwindow* window) = 0;
};

#endif