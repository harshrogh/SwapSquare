#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include <sstream>

class TextDisplay {
  char ***theDisplay;          //the n x n display 
  int gridSize;         //size of the grid (n)

  /*
   * The following field helps track how the game as progressed
   * The field should track how much Cells of the grid are of each color
   * Whenever a Cell changes color, the corresponding color count should
   * be updated.
   */
   int squareCount[5];  
 public:
  TextDisplay(int n); //one arg constructor where the parameter is the gridSize

  /*
   * The TextDisplay is an observer of each Cell. Cells call notify to 
   * update the (r,c) location to be ch
   */
  void notify(int r, int c, char ch);  

 
  ~TextDisplay(); //dtor
  friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif