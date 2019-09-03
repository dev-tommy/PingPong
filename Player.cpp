//---------------------------------------------------------------------------


#pragma hdrstop

#include "Player.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)


Player::Player(int positionX) {
  tableWidth = fr_GameWindow->im_Game->Width;
  tableHeight = fr_GameWindow->im_Game->Height;
  speed = 40;
  color = clMaroon;
  width = 25;
  height = 150;
  margin = 10;
  x = positionX;
  y = (tableHeight - height) /2;

  Player(x, y, width, height, color, speed);

}
Player::Player(int newX,int newY, int newWidth, int newHeight, TColor newColor, int newSpeed) {
  x = newX;
  y = newY;
  width = newWidth;
  height = newHeight;
  color = newColor;
  speed = newSpeed;

  sh_PlayerX = new TShape(fr_GameWindow);
  sh_PlayerX->Parent = fr_GameWindow;
  sh_PlayerX->Top = y;
  sh_PlayerX->Left = x;
  sh_PlayerX->Width = width;
  sh_PlayerX->Height = height;
  sh_PlayerX->Brush->Color = color;
  sh_PlayerX->Pen->Color = clGreen;

}

Player::~Player() {
  //delete sh_PlayerX;

}
void Player::hide() {

}
void Player::show() {

}
void Player::move(int direction) {
  sh_PlayerX->Top += direction * speed;
}
