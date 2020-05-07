//
// Created by Riya Gupta on 4/27/20.
//
#ifndef FINALPROJECT_BALL_H
#define FINALPROJECT_BALL_H
#include "math.h"
#include <cinder/gl/gl.h>
#include <cinder/gl/draw.h>
#include <cinder/Vector.h>

class Ball {
 private:
  float size;
  float x;
  float y;
  float dir_x;
  float dir_y;
  int speed;

 public:
  void Init(float ball_x, float ball_y, float ball_dir_x,
      float ball_dir_y, float ball_size, int ball_speed);
  void Draw();
  void Move();
  float getX() const;
  float getY() const;
  float getDirX() const;
  float getDirY() const;
  void setDirX(float dirX);
  void setDirY(float dirY);
  void setX(float x);
  void setY(float y);
  void setSpeed(int speed);
};
#endif  // FINALPROJECT_BALL_H
