#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include "window.h"

using namespace std;

Xwindow::Xwindow(int width, int height, std::string colourScheme) {

  d = XOpenDisplay(NULL);
  if (d == NULL) {
    cerr << "Cannot open display" << endl;
    exit(1);
  }
  s = DefaultScreen(d);
  w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, width, height, 1,
                          BlackPixel(d, s), WhitePixel(d, s));
  XSelectInput(d, w, ExposureMask | KeyPressMask);
  XMapRaised(d, w);

  Pixmap pix = XCreatePixmap(d,w,width,
        height,DefaultDepth(d,DefaultScreen(d)));
  gc = XCreateGC(d, pix, 0,(XGCValues *)0);

  XFlush(d);
  XFlush(d);

  // Set up colours.
  XColor xcolour;
  Colormap cmap;
  char color_vals[8][15];
  char defaultC[8][15] = {"white", "dark red", "lime green", "royal blue", "cyan", "yellow", "gray", "black"};
  if (colourScheme == "default"){
    for (int i = 0; i < 8; i++){
          for (int j = 0; j < 15; j++){
            color_vals[i][j] = defaultC[i][j];  
          }      
    }
  }

  cmap=DefaultColormap(d,DefaultScreen(d));
  for(int i=0; i < 8; ++i) {
      XParseColor(d,cmap,color_vals[i],&xcolour);
      XAllocColor(d,cmap,&xcolour);
      colours[i]=xcolour.pixel;
  }

  XSetForeground(d,gc,colours[Black]);

  // Make window non-resizeable.
  XSizeHints hints;
  hints.flags = (USPosition | PSize | PMinSize | PMaxSize );
  hints.height = hints.base_height = hints.min_height = hints.max_height = height;
  hints.width = hints.base_width = hints.min_width = hints.max_width = width;
  XSetNormalHints(d, w, &hints);

  XSynchronize(d,True);

  usleep(1000);
}

Xwindow::~Xwindow() {
  XFreeGC(d, gc);
  XCloseDisplay(d);
}

void Xwindow::fillRectangle(int x, int y, int width, int height, int colour) {
  XSetForeground(d, gc, colours[colour]);
  XFillRectangle(d, w, gc, x, y, width, height);
  XSetForeground(d, gc, colours[Black]);
}

void Xwindow::drawString(int x, int y, int level, int score, int highscore, int movesLeft, int winscore) {
  stringstream ss1;
  stringstream ss2;
  stringstream ss3;
  stringstream ss4;
  stringstream ss5;
  string str;
  string str1 = "SQUARESWAPPER 5000";
  string str2 = "BY HARSH ROGHELIA AND ADITYA MENON";
  ss1 << level;
  ss1 >> str;
  string str3 = "LEVEL: " + str;
  ss2 << score;
  ss2 >> str;
  string str4 = "SCORE: " + str;
  ss3 << movesLeft;
  ss3 >> str;
  string str5;
  if (movesLeft >= 0) {
	str5 = "MOVES LEFT: " + str;
  }
  else {
	str5 = "MOVES LEFT: Infinite";
  }
  ss4 << highscore;
  ss4 >> str;
  
  string str6 = "SCORE NEEDED: " + str;
  ss5 << winscore;
  ss5 >> str;
  string str7 = "HIGH SCORE: " + str;

	XSetForeground(d, gc, colours[White]);
  XFillRectangle(d, w, gc, x, 0, 300, 600);
//  XDrawText(d, w, DefaultGC(d,s), x, y, &ti, 1); 
  XDrawString(d, w, DefaultGC(d, s), x, 100, str1.c_str(), str1.length()); 
  XDrawString(d, w, DefaultGC(d, s), x, 150, str2.c_str(), str2.length());
  XDrawString(d, w, DefaultGC(d, s), x, 250, str3.c_str(), str3.length());
  XDrawString(d, w, DefaultGC(d, s), x, 300, str4.c_str(), str4.length());
  XDrawString(d, w, DefaultGC(d, s), x, 350, str5.c_str(), str5.length());
  XDrawString(d, w, DefaultGC(d, s), x, 400, str6.c_str(), str6.length());
  XDrawString(d, w, DefaultGC(d, s), x, 450, str7.c_str(), str7.length());
	

}
