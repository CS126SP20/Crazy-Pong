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
  // Initialize ball object
  void Init(float ball_x, float ball_y, float ball_dir_x,
      float ball_dir_y, float ball_size, int ball_speed);
  // Draw ball object
  void Draw();
  // Move ball object in certain direction
  void Move();
  // Getter for x coordinate of ball
  float getX() const;
  // Getter for y coordinate of ball
  float getY() const;
  // Getter for x direction of ball
  float getDirX() const;
  // Getter for y direction of ball
  float getDirY() const;
  // Setter for x direction of ball
  void setDirX(float dirX);
  // Setter for y direction of ball
  void setDirY(float dirY);
  // Setter for x coordinate of ball
  void setX(float x);
  // Setter for y coordinate of ball
  void setY(float y);
  // Setter for speed of ball
  void setSpeed(int speed);
};
#endif  // FINALPROJECT_BALL_H
