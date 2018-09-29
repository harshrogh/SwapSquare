#ifndef __LEVEL_H__
#define __LEVEL_H__
#include <string>
class Square;
class Level{
public:
	int scoreNeed;
	std::string fname;
	unsigned int colorIndex;
	std::string colorInput;
	int locked;
	Level();
	virtual Square* createSq()=0;
	virtual Square* createSq(int,int)=0;
	virtual Square*** createBoard()=0;
	virtual ~Level();
	int getScoreNeed();
	void setFileName(std::string fname);
	Square*** readFile();
	int getLocked();
	void setLocked(int n);
};

#endif