//
// Created by Riya Gupta on 4/27/20.
//

#ifndef FINALPROJECT_BALL_H
#define FINALPROJECT_BALL_H

#endif  // FINALPROJECT_BALL_H

class Ball {
 private:
  float size;
  float x;
  float y;
  float dir_x;
  float dir_y;
  float speed;

  void vec2_norm();
 public:
  Ball();
  void init(float ball_x, float ball_y, float ball_dir_x, float ball_dir_y, float ball_size, float ball_speed);
  void draw();
  void move();
  float getSize() const;
  float getX() const;
  float getY() const;
  float getDirX() const;
  float getDirY() const;
  float getSpeed() const;
  void setDirX(float dirX);
  void setDirY(float dirY);
  void setX(float x);
  void setY(float y);
};
