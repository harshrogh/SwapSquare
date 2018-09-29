#include "matchaxis.h"
#include "lateralsquare.h"
#include "psychedelicsquare.h"
#include "board.h"
#include "uprightsquare.h"
#include <iostream>

using namespace std;
//start definitions for matchHorizontal class.

MatchHorizontal::MatchHorizontal(int r,int c,Board* b){
	int matches = 0;
	Square ***t = b->getBoard();
	for(int i=c; i<10 ; i++)
	{
		if(t[r][c]->getColour() == t[r][i]->getColour())
			matches++;
		else
			break;
	}
	this->row = r;
	this->col = c;
	this->len = matches;
}
bool MatchHorizontal::isMatch(int r,int c,Board *b){
	Square ***t = b->getBoard();
	int matches = 0;
	for(int i=c; i<10 ; i++)
	{
		if(t[r][c]->getColour() == t[r][i]->getColour())
			matches++;
		else
			break;
	}
	if(matches>=3){
		return true;
	}
	return false;
}

int MatchHorizontal::clearSquares(Board* b,bool test)
{
	int del = 0;
	if(test){
		cout<<"Horizontal match at ";
		cout<<"row: "<<row<<", col: "<<col<<endl;
	}
	for(int i=col; i < (col+len); i++)
	{
		del += b->deleteSq(row,i);
	}
	return del;
}
bool MatchHorizontal::insertSquareType(Board *b,int colour){
	if(len<=3)
		return false;
	else{
		Square* newType;
		int newCol = (col+len-1+col)/2;
		if(len==4){
			newType = new LateralSquare(row,newCol,colour);
		}
		if(len==5){
			newType = new PsychedelicSquare(row,newCol,colour);
		}
		b->setGridSquare(row,newCol,newType);
		return true;
	}
}

bool MatchHorizontal::insertSquareType(Board *b,int colour,int x ,int y ,int d){
	if(len<=3)
		return false;
	else{
		Square* newType;
		int newCol = (col+len-1+col)/2;
		if(len==4){
			newCol = y-1;
			newType = new LateralSquare(row,newCol,colour);
		}
		if(len==5){
			newType = new PsychedelicSquare(row,newCol,colour);
		}
		b->setGridSquare(row,newCol,newType);
		return true;
	}
}

int MatchHorizontal::getColour(Board *b){
	return (b->getBoard())[row][col]->getColour();
}
//end of matchHorizontal.

//Start of matchVertical

MatchVertical::MatchVertical(int r,int c,Board *b){
	int matches = 0;
	Square ***t = b->getBoard();
	for(int i=r; i<10 ; i++)
	{
		if(t[r][c]->getColour() == t[i][c]->getColour())
			matches++;
		else
			break;
	}
	this->row = r;
	this->col = c;
	this->len = matches;
	//cout<<"MATCHESSSSSSS"<<this->len<<endl;
}


bool MatchVertical::isMatch(int r,int c,Board *b){
	Square ***t = b->getBoard();
	int matches = 0;
	for(int i=r; i<10 ; i++)
	{
		if(t[r][c]->getColour() == t[i][c]->getColour())
			matches++;
		else
			break;
	}
	if(matches>=3){
		return true;
	}
	return false;
}

int MatchVertical::clearSquares(Board* b,bool test)
{
	int del = 0;
	if(test){
		cout<<"Vertical match at ";
	cout<<"row: "<<row<<", col: "<<col<<endl;}
	for(int i=row; i < (row+len); i++)
	{
		del += b->deleteSq(i,col);
	}
	return del;
}

bool MatchVertical::insertSquareType(Board *b,int colour){
	if(len<=3)
		return false;
	else{
		Square* newType;
		int newRow = (row+len-1+row)/2;
		if(len==4){			
			newType = new UprightSquare(newRow,col,colour);
		}
		if(len==5){
			newType = new PsychedelicSquare(newRow,col, colour);
		}
		b->setGridSquare(newRow,col,newType);
		return true;
	}
}

bool MatchVertical::insertSquareType(Board *b,int colour,int x ,int y ,int d){
	if(len<=3)
		return false;
	else{
		Square* newType;
		int newRow = (row+len-1+row)/2;
		if(len==4){
			newRow = x-1;
			newType = new UprightSquare(newRow,col, colour);
		}
		if(len==5){
			newType = new PsychedelicSquare(newRow,col,colour);
		}
		b->setGridSquare(newRow,col,newType);
		return true;
	}
}
int MatchVertical::getColour(Board *b){
	return (b->getBoard())[row][col]->getColour(); 
}