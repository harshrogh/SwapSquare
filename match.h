#ifndef __MATCH_H__
#define __MATCH_H__

#include "square.h"
class Board;
class Match{
	protected:
	 	int removed;
	public:
		static int maxRow,maxCol;
		int row,col,len;
		
		virtual int clearSquares(Board*,bool)=0;
		virtual bool insertSquareType(Board*,int,int,int,int)=0;
		virtual bool insertSquareType(Board*,int)=0;// Special square types ( Lateral+Psychedelic/Upright+Psychedelic/Unstable)
		virtual int getColour(Board *)=0; // get yo colur
};

#endif