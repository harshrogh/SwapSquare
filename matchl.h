#ifndef __MATCHL_H__
#define __MATCHL_H__
#include "match.h"
class Board;

class MatchL:public Match{
	static int getWestMatches(int r, int c, Board* b);
	static int getEastMatches(int r, int c, Board* b);
	static int getNorthMatches(int r, int c, Board* b);
	static int getSouthMatches(int r, int c, Board* b);
	public:
		int finalRow,finalCol;
		MatchL(int r,int c,Board *b);
		int clearSquares(Board*,bool) ;
		static bool isMatch(int r,int c,Board *b);
		bool insertSquareType(Board*,int,int,int,int) ; 
		bool insertSquareType(Board*,int) ; 
		int getColour(Board *);

};

#endif