//
// Created by Riya Gupta on 4/27/20.
//

#include "mylibrary/ball.h";
#include "math.h"
#include <cinder/gl/gl.h>
#include <cinder/gl/draw.h>
#include <cinder/Vector.h>

using namespace cinder;

Ball::Ball() {
  
}

void Ball::init(float ball_x, float ball_y, float ball_dir_x, float ball_dir_y, float ball_size, float ball_speed ) {
  // ball
  x = ball_x;
  y = ball_y;
  dir_x = ball_dir_x;
  dir_y = ball_dir_y;
  size = ball_size;
  speed = ball_speed;
}

void Ball::draw() {

  vec2 center(x,y);
  //std::cout<<center<<std::endl;
  //gl::ScopedColor color( Color( CM_HSV, 0.72f, 1.0f, 1.0f ) );
  gl::color(Color(1, 0, 0));

  gl::drawSolidCircle( center, size);
}

void Ball::move() {
  // fly a bit
  x += dir_x * speed;
  y += dir_y * speed;

  // make sure that length of dir stays at 1
  vec2_norm();
}


void Ball::vec2_norm() {
  // sets a vectors length to 1 (which means that x + y == 1)
  float length = sqrt((x * x) + (y * y));
  if (length != 0.0f) {
    length = 1.0f / length;
    x *= length;
    y *= length;
  }
}


