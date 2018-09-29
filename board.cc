#include "board.h"
#include "lateralsquare.h"
#include "matchaxis.h"
#include "matchl.h"
#include "window.h"
#include <math.h>
#include <cstdlib>
#include <ctime>

using namespace std;
Board::Board(string fname,int levl,bool textOnly,string winColour,bool testing,int highscore){
	this->score = 0;
	this->winningScore = 200;
	movesleft = 20;
	lvl=NULL;
	m=NULL;
	grid = NULL;
	level = levl;
	this->textOnly = textOnly;
	this->highscore = highscore;
	isTesting = testing;
	if(!textOnly)
	{
		w = new Xwindow(800, 500,winColour);
  		w->drawString(550, 50, level, score, winningScore, movesleft, highscore);
	}
	else
		w = NULL;
	this->fname = fname;
	start();
}
void Board::swap(int x, int y, int z){
	if(x>=0 && y>=0 && x<10 && y<10)
	{
		Square *t = grid[x][y];
		if(t->getLock()!='l')
		{
			if(z==0 && x>0 && grid[x-1][y]->getLock()!='l')
			{
				setGridSquare(x,y,grid[x-1][y]);
				setGridSquare(x-1,y,t);
				 
				if (!determineMatches()) {
					cout << "invalid move: no matches" << endl;
					setGridSquare(x-1, y, grid[x][y]);
					setGridSquare(x, y, t);
				}
			else
				movesleft--;

			} 

		else if ( z==1 && x<10 && grid[x+1][y]->getLock()!='l'){
			setGridSquare(x,y,grid[x+1][y]);
			setGridSquare(x+1,y,t);
				
			if (!determineMatches()) {
					cout << "invalid move: no matches" << endl;
					setGridSquare(x+1, y, grid[x][y]);
					setGridSquare(x, y, t);
				}
			else
				movesleft--;
		}

		else if ( z==2 && y>0 && grid[x][y-1]->getLock()!='l'){
			setGridSquare(x,y,grid[x][y-1]);
			setGridSquare(x,y-1,t);
				 
			if (!determineMatches()) {
					cout << "invalid move: no matches" << endl;
					setGridSquare(x, y-1, grid[x][y]);
					setGridSquare(x, y, t);
				}
			else
				movesleft--;
		}
		else if ( z==3 && y<10 && grid[x][y+1]->getLock()!='l'){
			setGridSquare(x,y,grid[x][y+1]);
			setGridSquare(x,y+1,t);
				 
			if (!determineMatches()) {
					cout << "invalid move: no matches" << endl;
					setGridSquare(x, y+1, grid[x][y]);
					setGridSquare(x, y, t);
				}
			else
				movesleft--;
		}
		}
	else
		cout<<"invalid move"<<endl;
	}
}

int Board::getMovesLeft(){
	return movesleft;
}



void Board::setMovesLeft(int o){
	movesleft = o;
}



/*int Board::getHighScore(){
	return highscore ;
}

void Board::setHighScore(int o){
	highscore = o;
}*/

void Board::setWindow(Xwindow *w)
{
	this->w = w;
}

void Board::setGridSquare(int r,int c,Square *s){
	//add xwindow later

	if(s)
		{
			s->setCoords(r,c,w);
			#ifndef TEXT_ONLY
			s->printToWindow(w);
			#endif
		}
	else
	{
		int dim = 50;
		if(w)
		{
			w->fillRectangle(c*dim,r*dim,dim,dim,Square::black);
		}
	}
	grid[r][c] =  s;
}

int Board::deleteSq(int r,int c)
{
	int del =0;
	if(r>=0 && c>=0 && c<10 && r<10 )
	{
		if(grid[r][c])
		{
			Square* t = grid[r][c];
			setGridSquare(r,c,NULL);
			del += t->notify(this);
			del += 1;
			delete t;
		}
	}
	else
		return del;
	return del;
}

Square*** Board::getBoard(){
	return grid;
}

void Board::start(){
	if(lvl!=NULL)
		{delete lvl; lvl=NULL;}

	if(level==0){
		
		lvl = new Level0();
		movesleft = 20;
		winningScore = score + lvl->getScoreNeed();
	}
	if(level==1){
		lvl = new Level1();
		movesleft = 25;
		winningScore = score + lvl->getScoreNeed();
	}
	if(level==2){
		lvl = new Level2();
		movesleft = 25;
		winningScore = score + lvl->getScoreNeed();
		//level 2 shit here
	}
	lvl->setFileName(fname);
	grid = lvl->createBoard();
	#ifndef TEXT_ONLY
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			grid[i][j]->printToWindow(w);
			//xwindow shit
		}
	}
	#endif
	while(determineMatches()){
		setGridSquare(m->row,m->col,lvl->createSq(m->row,m->col));
	}
}

bool Board::determineMatches(){
	bool matched = false;
	 if(m)
	 	{delete m; m = NULL;}
	for(int i=0;i<10 && !matched;i++){
		for(int j=0;j<10 && !matched;j++){
			if(MatchL::isMatch(i,j,this)){
				matched = true;
				m = new MatchL(i,j,this);
			}
		}
	}
	for(int i=0;i<10 && !matched;i++){
		for(int j=0;j<10 && !matched;j++){
			if(MatchHorizontal::isMatch(i,j,this)){
				matched = true;
				m = new MatchHorizontal(i,j,this);
			}
			else if(MatchVertical::isMatch(i,j,this)){
				matched = true;
				m = new MatchVertical(i,j,this);
			}
		}
	}
	return matched;
}
int Board::executeMatches(){
	int del = 0;
	if(m){
			int colour = m->getColour(this);
			del += m->clearSquares(this,isTesting);
			m->insertSquareType(this,colour);
	}
	delete m;
	m = NULL;
	return del;
}

int Board::executeMatches(int x,int y,int z){
	int del = 0;
	if(m){
			int colour = m->getColour(this);
			del += m->clearSquares(this,isTesting);
			m->insertSquareType(this,colour,x,y,z);
	}
	delete m;
	m = NULL;
	return del;
}

bool Board::hint(){
	bool hint = false;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++)
		{
			Square *t = grid[i][j];
			if(!hint && grid[i][j]->getLock()!='l')
			{
				if(i>0 && grid[i-1][j]->getLock()!='l') // AND NOT LOCKED
				{
					setGridSquare(i,j,grid[i-1][j]);
					setGridSquare(i-1,j,t); 	
					if(determineMatches())
					{
						cout<<i<< " " << j << " " << 0 <<endl;
						hint = true;
					}
					setGridSquare(i-1,j,grid[i][j]);
					setGridSquare(i,j,t); 
				}
				else if(i<9 && !hint && grid[i+1][j]->getLock()!='l') //AND NOT LOCKED
				{
					setGridSquare(i,j,grid[i+1][j]);
					setGridSquare(i+1,j,t);
					if(determineMatches()){
						cout<<i<<" "<<j<<" "<<1<<endl;
						hint=true;
					}
					setGridSquare(i+1,j,grid[i][j]);
					setGridSquare(i,j,t);
				}
				else if(j>0 && !hint && grid[i][j-1]->getLock()!='l')//AND NOT LOCKED
				{
					setGridSquare(i,j,grid[i][j-1]);
					setGridSquare(i,j-1,t);
					if(determineMatches())
					{
						cout<<i<<" "<<j<<" "<<1<<endl;
						hint = true;
					}
					setGridSquare(i,j-1,grid[i][j]);
					setGridSquare(i,j,t);
				}
				else if(j<9 && !hint && grid[i][j+1]->getLock()!='l'){//AND NOT LOCKED
					setGridSquare(i,j,grid[i][j+1]);
					setGridSquare(i,j+1,t);
					if(determineMatches())
					{
						cout<<i<<" "<<j<<" "<< 3<<endl;
					}
					setGridSquare(i,j+1,grid[i][j]);
					setGridSquare(i,j,t);
				}				
			}
		}
	}
	if(!hint)
		cout<<"No possible moves :("<<endl;
	return hint;
}

int Board::getPoints(int sq,int consecutive)
{
	if(sq==3){
		// cout<<sq<<" "<<consecutive<<" " <<sq*pow(2,consecutive)<<endl;
		return sq*pow(2,consecutive);
	}
	else if(sq==4){
		// cout<<sq<<" "<<consecutive<<" " <<2*sq*pow(2,consecutive)<<endl;
		return 2*sq*pow(2,consecutive);
	}
	else if(sq==5){
		// cout<<sq<<" "<<consecutive<<" " <<3*sq*pow(2,consecutive)<<endl;
		return 3*sq*pow(2,consecutive);
	}
	else if(sq>5){
		// cout<<sq<<" "<<consecutive<<" " <<4*sq*pow(2,consecutive)<<endl;
		return 4*sq*pow(2,consecutive);
	}
	else
		return 0;
}

void Board::notifyBoard(){
	int consecutive = 0;
	contin = false;
	while(determineMatches())
	{
		string s;
		
		if(isTesting && consecutive>0)
		{
			
			while(!contin && cin>>s)
			{
				if(s=="next")
				{
					break;
				}
				if(s=="continue")
				{
					contin = true;
					break;
				}
			}
		}
		if(isTesting && !contin)
		{
			for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if(grid[i][j])
					cout << grid[i][j]->print() << " ";
				else
					cout<<"___ ";
		}
			cout << endl;
		}
	}
		int del = executeMatches();
		score += getPoints(del,consecutive);
		//if(score>lvl->getScoreNeed())
		
		consecutive++;
		fillEmptySquares();

	}
	if(!textOnly)
		w->drawString(550, 50, level, score, winningScore, movesleft, highscore);
	
}

void Board::scramble(){
	if(!hint()){
		cout<<"Scrambling"<<endl;
		for (int i = 0; i < 10; i++) {
			// direction = 0 for north, 1 for south, 2 for west and 3 for east
			int x = rand() % 9 + 0;     // x in the range 0 to 9
			int y = rand() % 9 + 0;     // y in the range 0 to 9
			int d= rand() % 3 + 0;     // x in the range 0 to 3
			Square* t = grid[x][y];
			if ((d == 0) && (x > 0)) {
				setGridSquare(x, y, grid[x-1][y]);
				setGridSquare(x-1, y, t);
			}
			else if ((d == 1) && (x < 9)) {
				setGridSquare(x, y, grid[x+1][y]);
				setGridSquare(x+1, y, t);
			}
			else if ((d == 2) && (y > 0)) {
				setGridSquare(x, y, grid[x][y-1]);
				setGridSquare(x, y-1, t);
			}
			else if ((d == 3) && (y < 9)) {
				setGridSquare(x, y, grid[x][y+1]);
				setGridSquare(x, y+1, t);
			}
		}
	}
	else
		cout<<"Cannot scramble. The above move is possible."<<endl;
}

void Board::placeRandomSquare(int r,int c)
{
	Square *t = grid[r][c];
	int x = rand()%10;
	int y = rand()%10;
	grid[r][c] = grid[x][y];
	grid[x][y] = t;

}

int Board::getScore() {
	return score;
}

void Board::setScore(int score) {
	this->score = score;
}

int Board::getLevel() {
	return level;
}

void Board::setLevel(int level) {
	this->level =  level;
}

void Board::setBoard(Square*** grid) {
	this->grid = grid;
}

void Board::levelup() {
	
	if (level <= 1){
		level++;
		delete m;

		start();	
	} else {
		cout << "No more levels :(" << endl;
	}
}

void Board::leveldown() {
	if (level >=1){
		level--;
		delete m;
		
		start();
	}
	else {
		cout << "No easier levels :( Try harder." << endl;	
	}
}

/*int Board::getLockedSquares() {
	return lvl->getLockedSquares();
}*/

void Board::restart() {
	grid = lvl->createBoard();
	score = 0;
	winningScore = lvl->getScoreNeed();
	movesleft = 20;
	start();
	
}

ostream& operator<< (ostream &out, Board &b) {
	out << "Level:           " << b.level << endl;
	out << "Score:           " << b.score << endl;
	out << "Winning Score:   " << b.winningScore << endl;
	out << "Moves remaining: " << b.movesleft << endl;
	out << "High Score: "<<b.highscore<<endl;
	out << "---------------"<<endl<<endl;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			out << b.grid[i][j]->print() << " ";
		}
		out << endl;
	}
	return out;
}

void Board::fillEmptySquares(){
	for (int i = 9; i >= 0; i--) {
		for (int j = 9; j >= 0; j--) {
			if (grid[i][j] == NULL) {
				bool squareFound = false;
				for (int k = i-1; (k >= 0); k--) {
					if (grid[k][j] != NULL) {
						setGridSquare(i, j, grid[k][j]);
						grid[i][j]->setCoords(i, j,w);
						setGridSquare(k, j, NULL);
						squareFound = true;
						break;
					}
				}
				if (!squareFound) {
					setGridSquare(i, j, lvl->createSq(i, j));
				} // end of if
			} // end of if
			//grid[i][j]->printToWindow(window);
		} // end of for
	} // end of for
}

int Board::getLocked()
{
	return lvl->getLocked();
}

Board::~Board(){
 for (int i = 0; i < 10; i++){
                for (int j = 0; j < 10; j++){
                        delete grid[i][j];
                }
                delete [] grid[i];
    }
	delete[] grid;
	delete m;
	delete lvl;
	delete w;
}
int Board::getHighScore(){
	return highscore;
}
