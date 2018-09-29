#include "lateralsquare.h"
#include "board.h"
#include <string.h>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char* argv[])
{
	
	bool seedSet = false;
	string fileName = "no file";
	int lvlNum = 0;
	bool textOnly = false;
	string colourScheme = "default";
	bool testing = false;
	
	int highscore;
	for (int i = 1; i < argc; i++){
		if (strcmp(argv[i], "-seed") == 0) {
			int x = atoi(argv[i+1]);
			srand(x);
			seedSet = true;
		}
		else if (strcmp(argv[i], "-scriptfile") == 0) {
			fileName = argv[i+1];
		}
		else if (strcmp(argv[i], "-startlevel") == 0) {
			lvlNum = atoi(argv[i+1]);
		}
		else if (strcmp(argv[i], "-text") == 0){
			textOnly = true;
		}
		else if (strcmp(argv[i], "-colourscheme")==0){
			colourScheme = argv[i+1];
		}
		else if(strcmp(argv[i],"-testing")==0)
		{
			testing = true;
		}
		
	}
	if (!seedSet) {
		srand(time(NULL));
	}
		ifstream ifs("highscore.txt");
		if(ifs>>highscore)
		{}
		else
		{
			ofstream ofs("highscore.txt");
			highscore = 400;
			ofs<<highscore;
			ofs.close();
		}
			
	 Board* b = new Board(fileName	, lvlNum, textOnly, colourScheme,testing,highscore);

cout<<"                     ____     ___    _   _      _      ____    _____              " <<endl;  
cout<<"                    / ___|   / _ \\  | | | |    / \\    |  _ \\  | ____|             " <<endl;  
cout<<"                    \\___ \\  | | | | | | | |   / _ \\   | |_) | |  _|               " <<endl;  
cout<<"                     ___) | | |_| | | |_| |  / ___ \\  |  _ <  | |___              " <<endl;  
cout<<"                    |____/   \\__\\_\\  \\___/  /_/   \\_\\ |_| \\_\\ |_____|             " <<endl;  
cout<<"                                                                            " <<endl;  
cout<<"               ____   __        __     _      ____    ____    _____   ____  " <<endl;  
cout<<"              / ___|  \\ \\      / /    / \\    |  _ \\  |  _ \\  | ____| |  _ \\  " <<endl; 
cout<<"              \\___ \\   \\ \\ /\\ / /    / _ \\   | |_) | | |_) | |  _|   | |_) | " <<endl; 
cout<<"               ___) |   \\ V  V /    / ___ \\  |  __/  |  __/  | |___  |  _ <  " <<endl; 
cout<<"              |____/     \\_/\\_/    /_/   \\_\\ |_|     |_|     |_____| |_| \\_\\  " <<endl;
cout<<"                                  " <<endl;                               
cout<<"                            ____     ___     ___     ___     " <<endl;                              
cout<<"                           | ___|   / _ \\   / _ \\   / _ \\  " <<endl;                                
cout<<"                           |___ \\  | | | | | | | | | | | | " <<endl;                                
cout<<"                            ___) | | |_| | | |_| | | |_| |" <<endl;                                 
cout<<"                           |____/   \\___/   \\___/   \\___/  " <<endl<<endl;

	 cout << "Welcome to SquareSwapper5000! You can play the game using the following commands:" << endl << endl;
	cout << "-> swap x y z:" << endl << "     swaps the square at the (x,y) co-ordinate with the square in the z direction (0 for north, 1 for south, 2 for west and 3 for east)" << endl;
	cout << "-> hint:" << endl << "     the game returns a valid move (x,y, z as above) that would lead to a match." << endl;
	cout << "-> scramble:" << endl << "     Available only if no moves are possible, this command reshuffles the squares on the board (no new cells are created)" << endl;
	cout << "-> levelup:" << endl << "     Increases the difficulty level of the game by one. You may clear the board and create a new one suitable for that level. If there is no higher level, this command has no effect." << endl;
	cout << "->leveldown:" << endl << "     The same as above, but this time decreasing the difficulty level of the game by one." << endl;
	cout << "->restart:" << endl << "     Clears the board and starts a new game at the same level" << endl << endl;
	string input;
	string swapFunc = "swap";
	string hintFunc = "hint";
	string scrambleFunc = "scramble";
	string levelupFunc = "levelup";
	string leveldownFunc = "leveldown";
	string colourFunc = "colourscheme";
	string restartFunc = "restart";
	//string renameFunc = "rename";
	string quitFunc = "quit";
	while (b->getMovesLeft() > 0 && !cin.eof()) {
		if (b->score >= b->winningScore && b->getLocked()==0) { 
			cout << "Congratulations! You beat the level! :)" << endl;
			b->levelup();
		}
		cout << *b;
		cin >> input;
		if (input == swapFunc) {
			int x, y, d;
			cin >> x >> y >> d;
			b->swap(x,y,d);
			b->notifyBoard();
		}
		else if (input == hintFunc) {
			if(b->hint()){}
		}
		else if (input == scrambleFunc) {
			// check if there are moves remaining
			b->scramble();
		}
		else if (input == levelupFunc) {
			b->levelup();
		}
		else if (input == leveldownFunc) {
			b->leveldown();
		}
		else if (input == restartFunc) {
			b->restart();
		}
		/*else if (input == renameFunc) {
			cin >> input;
			if (input == swapFunc) {
				cin >> input;
				swapFunc = input;
			}
			else if (input == hintFunc) {
				cin >> input;
				hintFunc = input;
			}
			else if (input == scrambleFunc) {
				cin >> input;
				scrambleFunc = input;
			}
			else if (input == levelupFunc) {
				cin >> input;
				levelupFunc = input;
			}
			else if (input == leveldownFunc) {
				cin >> input;
				leveldownFunc = input;
			}
			else if (input == colourFunc) {
				cin >> input;
				colourFunc = input;
			}
			else if (input == restartFunc) {
				cin >> input;
				restartFunc = input;
			}
			else if (input == renameFunc) {
				cin >> input;
				renameFunc = input;
			}
			else if (input == quitFunc) {
				cin >> input;
				quitFunc = input;
			}
		}*/
		else if (input == quitFunc) {
			if(b->getHighScore() < b->getScore())
			{

cout<<"                     _   _   _____  __        __                              " <<endl;      
cout<<"                    | \\ | | | ____| \\ \\      / /                              " <<endl;
cout<<"                    |  \\| | |  _|    \\ \\ /\\ / /                               " <<endl;     
cout<<"                    | |\\  | | |___    \\ V  V /                                " <<endl;       
cout<<"                    |_| \\_| |_____|    \\_/\\_/                                 " <<endl;       
cout<<"                                                                        	     " <<endl;
cout<<"  _   _   ___    ____   _   _     ____     ____    ___    ____    _____     _ " <<endl;
cout<<" | | | | |_ _|  / ___| | | | |   / ___|   / ___|  / _ \\  |  _ \\  | ____|   | |" <<endl;
cout<<" | |_| |  | |  | |  _  | |_| |   \\___ \\  | |     | | | | | |_) | |  _|     | |" <<endl;
cout<<" |  _  |  | |  | |_| | |  _  |    ___) | | |___  | |_| | |  _ <  | |___    |_|" <<endl;
cout<<" |_| |_| |___|  \\____| |_| |_|   |____/   \\____|  \\___/  |_| \\_\\ |_____|   (_)" <<endl<<endl<<endl;
				cout<<"Congratulations, you got a highscore of "<<b->getScore()<<endl;
				ofstream ofs("highscore.txt");
				
				ofs<<b->getScore();
				ofs.close();
			}
			cout << "Thanks for playing!" << endl;
			break;
		}
		
	}
	delete b;
}
