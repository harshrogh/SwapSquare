#ifndef __LEVEL2_H__
#define __LEVEL2_H__

#include "level.h"

class Level2: public Level{

public:
	Level2();
	Square* createSq();
	Square* createSq(int,int);
	Square*** createBoard();
};


#endif