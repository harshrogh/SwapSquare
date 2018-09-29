#include "level2.h"
#include "basicsquare.h"
#include "lateralsquare.h"
#include "uprightsquare.h"
#include "unstablesquare.h"
#include "psychedelicsquare.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

Level2::Level2(){
	scoreNeed = 500;
}

Square* Level2::createSq(){
	if(colorInput.length()==0)
	{
		int colour;
		int x = rand() % 7 + 1;     // x in the range 1 to 6
		if (x == 1) {
			colour = 0;
		}
		else if (x == 2) {
			colour = 1;
		}
		else if (x == 3) {
			colour = 2;
		}
		else if (x == 4) {
			colour = 3;
		}
		else if (x == 5) {
			colour = 4;
		}
		else if (x == 6) {
			colour = 5;
		}
		else {
			colour = 6;
		}
		Square *s = new BasicSquare(0,0,colour);
		//lock here
		 x = rand()%5+1;
		if(x==1)
		{
			s->setLock('l');
		}
		return s;
	}
	else
	{
		if(colorIndex>=colorInput.length())
			colorIndex = 0;
		return new BasicSquare(0,0,colorInput[colorIndex++]-'0');
	}
}

Square* Level2::createSq(int r,int c)
{
	if(colorInput.length()==0)
	{
		int colour;
		int x = rand() % 7 + 1;     // x in the range 1 to 6
		if (x == 1) {
			colour = 0;
		}
		else if (x == 2) {
			colour = 1;
		}
		else if (x == 3) {
			colour = 2;
		}
		else if (x == 4) {
			colour = 3;
		}
		else if (x == 5) {
			colour = 4;
		}
		else if (x == 6) {
			colour = 5;
		}
		else {
			colour = 6;
		}
		Square *s = new BasicSquare(r,c,colour);
		//lock here
		 x = rand()%5+1;
		if(x==1)
		{
			s->setLock('l');
		}
		return s;
	}
	else
	{
		if(colorIndex>=colorInput.length())
			colorIndex = 0;
		return new BasicSquare(r,c,colorInput[colorIndex++]-'0');
	}
}

Square*** Level2::createBoard()
{
 if(fname!="no file")
 {
 	return readFile();
 }
 else{
 	Square ***s;
 	s = new Square**[10];
 	for (int i = 0; i < 10; i++){
			s[i] = new Square*[10];
	}
	for (int i = 0; i < 10; i++) 
	{
		for (int j = 0; j < 10; j++) 
		{
			s[i][j] = createSq();
			s[i][j]->setCoords(i,j);
		} 
	}
	return s;
 }
}