#ifndef __MATCHAXIS_H__
#define __MATCHAXIS_H__
#include "match.h"
class Board;

class MatchHorizontal:public Match{
public:
	MatchHorizontal(int,int,Board*);
	
	static bool isMatch(int , int , Board*  );
	int clearSquares(Board*,bool);
	bool insertSquareType(Board* , int,int,int,int );
	bool insertSquareType(Board* , int);
	int getColour(Board* );
};

class MatchVertical:public Match{
public:
	MatchVertical(int,int,Board*);

	static bool isMatch(int , int , Board*  );
	int clearSquares(Board*,bool);
	bool insertSquareType(Board* , int ,int,int,int);
	bool insertSquareType(Board* , int);
	int getColour(Board* );
};

#endif