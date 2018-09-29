#ifndef __LEVEL0_H__
#define __LEVEL0_H__
#include "level.h"
#include <string>
class Level0: public Level{
	 
public:
	Level0();
	
	 Square* createSq();
	 Square* createSq(int,int);
	 Square*** createBoard();
};


#endif