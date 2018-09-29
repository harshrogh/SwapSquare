#include "matchl.h"
#include "board.h"
#include "unstablesquare.h"
#include <iostream>
using namespace std;
int MatchL::getWestMatches(int r, int c, Board* b){
	Square ***t = b->getBoard();
	int westMatches = 0;
	for(int i=c-2;i>=0 && i<=c;i++)
	{
		if(t[r][c]->getColour() == t[r][i]->getColour())
		{
			westMatches++;
		}
	}
	return westMatches;
}
int MatchL::getEastMatches(int r, int c, Board* b){
	Square ***t = b->getBoard();
	int eastMatches = 0;
	for(int i=c;i<=c+2 && i<10;i++)
	{
		if(t[r][c]->getColour()==t[r][i]->getColour())
			eastMatches++;
	}
	return eastMatches;
}

int MatchL::getNorthMatches(int r, int c, Board* b){
	Square ***t = b->getBoard();
	int northMatches = 0;
	for(int i=r-2;i>=0 && i<=r;i++)
	{
		if(t[r][c]->getColour()==t[i][c]->getColour())
			northMatches++;
	}
	return northMatches;
}

int MatchL::getSouthMatches(int r, int c, Board* b){
	Square ***t = b->getBoard();
	int southMatches = 0;
	for(int i=r; i<=r+2 && i<10;i++){
		if(t[i][c]->getColour() == t[r][c]->getColour())
			southMatches++;
	}
	return southMatches;
}


MatchL::MatchL(int r,int c,Board *b){
	 int eastMatches = getEastMatches(r,c,b);
	 int westMatches = getWestMatches(r,c,b);
	 int northMatches = getNorthMatches(r,c,b);
	 int southMatches = getSouthMatches(r,c,b);
	 this->row = r;
	 this->col = c;
	 if ((westMatches == 3) && (northMatches == 3)){
		finalRow = r - 2;
		finalCol = c - 2;
	}
	else if ((westMatches == 3) && (southMatches == 3)){
		finalRow = r + 2;
		finalCol = c - 2;
	}
	else if ((eastMatches == 3) && (northMatches == 3)){
		finalRow = r - 2;
		finalCol = c + 2;
	}
	else if ((eastMatches == 3) && (southMatches == 3)){
		finalRow = r + 2;
		finalCol = c + 2;
	}
	len = 5;
}

bool MatchL::isMatch(int r,int c,Board *b){
	int eastMatches = getEastMatches(r,c,b);
	 int westMatches = getWestMatches(r,c,b);
	 int northMatches = getNorthMatches(r,c,b);
	 int southMatches = getSouthMatches(r,c,b);
	 if ((westMatches == 3) && (northMatches == 3)){
		return true;
	}
	else if ((westMatches == 3) && (southMatches == 3)){
		return true;
	}
	else if ((eastMatches == 3) && (northMatches == 3)){
		return true;
	}
	else if ((eastMatches == 3) && (southMatches == 3)){
		return true;
	}
	return false;
}

int MatchL::clearSquares(Board *b,bool test){
	int del = 0;
	if(test)
		{
			cout<<"L match at ";
			cout<<"row: "<<row<<", col: "<<col<<endl;
	}
	int rowTraversal = 1;
	int colTraversal = 1;
	if (finalCol < col){
		colTraversal = 1;
	}else {
		colTraversal = -1;
	}

	if (finalRow < row){
		rowTraversal = 1;
	}

	else{
		rowTraversal = -1;
	}
	for (int i = 0; i <= 2; i++){
		del += b->deleteSq(row, (finalCol + (colTraversal * i)));
	}
	for (int i =0; i < 2; i++){
		del += b->deleteSq((finalRow + (rowTraversal * i)), col);
	}
	return del;
}
bool MatchL::insertSquareType(Board *b,int colour)
{
	Square *newType = new UnstableSquare(row,col,colour);
	b->setGridSquare(row,col,newType);
	return true;
}
bool MatchL::insertSquareType(Board *b,int colour,int x,int y,int d)
{
	Square *newType = new UnstableSquare(row,col,colour);
	b->setGridSquare(row,col,newType);
	return true;
}

int MatchL::getColour(Board* b){
	return (b->getBoard())[row][col]->getColour();
}