//---------------------------------------------------------------------------

#ifndef PlayerH
#define PlayerH
//---------------------------------------------------------------------------

#include <iostream>
#include "Unit2.h"

class Player {
  int speed;
  int posX;
  int x,y,width,height;
  int margin;
  int tableWidth;
  int tableHeight;
  TColor color;
  TShape *sh_PlayerX;
public:
  Player(int positionX);
  Player(int x,int y, int width, int height, TColor color, int speed);
  ~Player();
  void hide();
  void show();
  void move(int direction);
};

#endif
