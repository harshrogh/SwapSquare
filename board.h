#ifndef __BOARD_H__
#define __BOARD_H__


#include "square.h"
#include "level.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include <string>
#include <iostream>

class Match;
class Xwindow;
class Level;

class Board{
	std::string fname;
	
	int level,movesleft;
	 Level *lvl;
	Square ***grid;
	bool textOnly;
	bool isTesting;
	bool contin;
	int highscore;
public:
	int score,winningScore;
	Xwindow *w;
	Match *m;
	Board(std::string,int,bool,std::string,bool,int h=0);
	void swap(int x, int y, int z);
	~Board();
	
	void start();	 
	void setBoard(Square ***);
	Square*** getBoard();
	bool hint();
	void setGridSquare(int,int,Square *); 
	int getMovesLeft();
	void setMovesLeft(int);

	int getScore();
	void setScore(int);

	int getLevel();
	void setLevel(int);

	int deleteSq(int,int);
	void setWindow(Xwindow *w);

	void levelup();
	void leveldown();

	void restart();
	void scramble();  
	void setTextOnly(bool textOnly);

	void placeRandomSquare(int,int); 
	bool determineMatches();
	void notifyBoard();
	int getPoints(int,int);
	void fillEmptySquares(); 
	int executeMatches(int,int,int);
	int executeMatches();
	int getLocked();
	friend std::ostream& operator<<(std::ostream&,Board&);
	int getHighScore();
};

#endif