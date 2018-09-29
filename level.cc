
#include "level.h"
#include "basicsquare.h"
#include "lateralsquare.h"
#include "uprightsquare.h"
#include "unstablesquare.h"
#include "psychedelicsquare.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

Level::Level(){
	scoreNeed = 0;
	fname = "no file";
	colorIndex = 0;
	locked = 0;
}

void Level::setFileName(string fname)
{
	this->fname = fname;
}

int Level::getScoreNeed(){
	return scoreNeed;
}

Square*** Level::readFile(){
	Square*** g;
	g = new Square**[10];
	for (int i = 0; i < 10; i++) {
		g[i] = new Square*[10];
		for(int j=0;j<10;j++)
		{
			g[i][j] = NULL;
		}
	}
	int colour;
	
	ifstream ifs(fname.c_str());
	string s;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(g[i][j]!=NULL)
			{
				delete g[i][j];
				g[i][j] = NULL;
			}
			ifs>>s;
			 colour = s[2] - '0';
			
			if(s[1]=='_')
			{				 
				g[i][j] = new BasicSquare(i,j,colour);
			}				
			if(s[1]=='h')
			{
				 
				g[i][j] = new LateralSquare(i,j,colour);
			}
			 if(s[1]=='v')
			{
				 
				g[i][j] = new UprightSquare(i,j,colour);
			}
			 if(s[1]=='b')
			{
				 
				g[i][j] = new UnstableSquare(i,j,colour);
			}
			if(s[1]=='p')
			{
				 
				g[i][j] = new PsychedelicSquare(i,j,colour);
			}
		}
	}
 
	ifs>>colorInput;
	return g;
}
Level::~Level(){}

int Level::getLocked()
{
	return locked;
}
void Level::setLocked(int lock)
{
	this->locked = lock;
}