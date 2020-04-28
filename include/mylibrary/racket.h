//
// Created by Riya Gupta on 4/21/20.
//

#ifndef FINALPROJECT_RACKET_H

#include <cinder/gl/gl.h>

#define FINALPROJECT_RACKET_H

using namespace cinder;

namespace  mylibrary {

const int kRacket_width = 10;
const int kRacket_height = 80;
const int kRacket_speed = 10;

class Racket  {
  //racket position
  float x;
  float y;
  int score;

 public:
  Racket();
  void init( float a, float b);
  void draw();
  void move_up();
  void move_down();
  float getX() const;
  float getY() const;
  int getScore() const;
  void setScore(int score);
};
}  // namespace mylibrary

#endif  // FINALPROJECT_RACKET_H
