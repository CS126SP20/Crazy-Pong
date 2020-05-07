//
// Created by Riya Gupta on 4/27/20.
//

#include "mylibrary/ball.h";

using namespace cinder;

Ball::Ball() {
  
}

void Ball::Init(float ball_x, float ball_y, float ball_dir_x,
    float ball_dir_y, float ball_size, int ball_speed ) {
  x = ball_x;
  y = ball_y;
  dir_x = ball_dir_x;
  dir_y = ball_dir_y;
  size = ball_size;
  speed = ball_speed;
}

void Ball::Draw() {
  vec2 center(x,y);
  gl::color( Color( CM_HSV, 0.96f, 1.0f, 1.0f ) );
  gl::drawSolidCircle( center, size);
}

void Ball::Move() {
  x += dir_x * speed;
  y += dir_y * speed;
}
float Ball::getSize() const { return size; }
float Ball::getX() const { return x; }
void Ball::setX(float x) { Ball::x = x; }
void Ball::setY(float y) { Ball::y = y; }
void Ball::setSpeed(int speed) { Ball::speed = speed; }
void Ball::setDirX(float dirX) { dir_x = dirX; }
void Ball::setDirY(float dirY) { dir_y = dirY; }
float Ball::getY() const { return y; }
float Ball::getDirX() const { return dir_x; }
float Ball::getDirY() const { return dir_y; }
float Ball::getSpeed() const { return speed; }