#include "level1.h"
#include "basicsquare.h"
#include "lateralsquare.h"
#include "uprightsquare.h"
#include "unstablesquare.h"
#include "psychedelicsquare.h"
#include <iostream>
#include <cstdlib>

Level1::Level1()
{
	scoreNeed = 300;
}

Square* Level1::createSq(){
	int color;
	Square* bs;
	if(colorInput.length()==0)
	{
		int randomNum = rand()%9 + 1;
		if(randomNum==1 || randomNum==2)
			color = 0;
		else if(randomNum==3 || randomNum==4)
			color = 1;
		else if(randomNum==5)
			color=2;
		else if(randomNum==6)
			color = 3;
		else if(randomNum==7)
			color = 4;
		else if(randomNum==8)
			color = 5;
		else{
		color = 6;
		}
			int x = rand()%10 +1;
			if(x==1)
			{
				x = rand()%4 + 1;
				if(x==1)
					bs = new LateralSquare(0,0,color);
				else if(x==2)
					bs = new UprightSquare(0,0,color);
				else if(x==3)
					bs = new UnstableSquare(0,0,color);
				else
					bs = new PsychedelicSquare(0,0,color);
			}	
	else{
		bs = new BasicSquare(0,0,color);
	}
}
	else
	{
		if(colorIndex>=colorInput.length())
			colorIndex = 0;
		bs = new BasicSquare(0,0,colorInput[colorIndex++]-'0');
	}
	return bs;
}

Square* Level1::createSq(int r,int c)
{
	int color;
	Square *bs;
	if(colorInput.length()==0)
	{
		int randomNum = rand()%9 + 1;
		if(randomNum==1 || randomNum==2)
			color = 0;
		else if(randomNum==3 || randomNum==4)
			color = 1;
		else if(randomNum==5)
			color=2;
		else if(randomNum==6)
			color = 3;
		else if(randomNum==7)
			color = 4;
		else if(randomNum==8)
			color = 5;
		else{
		color = 6;
		}
			int x = rand()%10 +1;
			if(x==1)
			{
				x = rand()%4 + 1;
				if(x==1)
					bs = new LateralSquare(r,c,color);
				else if(x==2)
					bs = new UprightSquare(r,c,color);
				else if(x==3)
					bs = new UnstableSquare(r,c,color);
				else
					bs = new PsychedelicSquare(r,c,color);
			}	
	else{
		bs =  new BasicSquare(r,c,color);		
	}
	}
	else
	{
		if(colorIndex>=colorInput.length())
			colorIndex = 0;
		bs =  new BasicSquare(r,c,colorInput[colorIndex++]-'0');
	}
	return bs;
}

Square*** Level1::createBoard(){
	if(fname!="no file")
	{
		return readFile();
	}
	else
	{
		Square*** t;
		t = new Square**[10];
		for (int i = 0; i < 10; i++) {
			t[i] = new Square*[10];
			for(int j=0;j<10;j++)
			{
				t[i][j] = NULL;
			}
		}
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++)
			{
				t[i][j] = createSq(i,j);
			}
		}
		return t;
	}
}