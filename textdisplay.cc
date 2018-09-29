#include "textdisplay.h"
#include <iostream>
using namespace std;
TextDisplay::TextDisplay() {
  gridSize = 10;
	theDisplay = new char**[gridSize];
	for(int i=0;i<gridSize;i++)
    {
        theDisplay[i] = new char*[gridSize];
        for(int j=0;j<gridSize;j++)
        {
           theDisplay[i][j][0] = '_';
           theDisplay[i][j][1] = '_';
           theDisplay[i][j][2] = '_';
        }
    }
    for(int i=0;i<5;i++)
    {
    	squareCount[i] = 0;
    }
}

void TextDisplay::notify(int r, int c, int colour,int type){
  theDisplay[r][c][2] = '0' + colour;
  if(type==0)
  {
    theDisplay[r][c][1] = '_';
  }
  if(type==1)
  {
    theDisplay[r][c][1] = 'h';
  }
  if(type==2)
  {
    theDisplay[r][c][1] = 'v';
  }
  if(type==3)
  {
    theDisplay[r][c][1] = 'b';
  }
  if(type==4)
  {
    theDisplay[r][c][1] = 'p';
  }
}

TextDisplay::~TextDisplay(){
	for(int i=0;i<gridSize;i++)
	{
		for(int j=0;j<gridSize;j++)
			delete [] theDisplay[i][j];
		delete [] theDisplay[i];
	}		
	delete [] theDisplay;
}

std::ostream &operator<<(std::ostream &out, const TextDisplay &td){
	for(int i=0;i<td.gridSize;i++)
    {
        for(int j=0;j<td.gridSize;j++)
        {
           out<<td.theDisplay[i][j][0];
           out<<td.theDisplay[i][j][1];
           out<<td.theDisplay[i][j][2];
           out<<" ";
        }
        out<<std::endl;
    }
    return out;
}
