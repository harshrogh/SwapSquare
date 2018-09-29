#include "level0.h"
#include "basicsquare.h"
#include "lateralsquare.h"
#include "uprightsquare.h"
#include "unstablesquare.h"
#include "psychedelicsquare.h"
using namespace std;
Level0::Level0(){
	scoreNeed = 200;
	colorIndex = 0;
	locked = 0;
}



Square* Level0::createSq(){
	if(colorIndex>=colorInput.length()){
		colorIndex =0;
	}
	return new BasicSquare(0,0,colorInput[colorIndex++] - '0');
}

Square* Level0::createSq(int r,int c){
	if(colorIndex>=colorInput.length()){
		colorIndex =0;
	}
	return new BasicSquare(r,c,colorInput[colorIndex++] - '0');
}

Square*** Level0::createBoard(){
	if(fname!="no file"){
		return readFile();
	}
	else{
		setFileName("sequence.txt");
		return readFile();
	}
}