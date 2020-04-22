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
const int kRacket_speed = 3;

class Racket  {
  //racket position
  float x;
  float y;

 public:
  Racket() { x = 0.0f; y = 0.0f; }
  Racket( float a, float b) { x = a; y = b; }

  void init( float a, float b) { x = a; y = b; }

  void draw() {

    cinder::gl::color(Color(0, 1, 0));
    cinder::gl::drawSolidRect(Rectf(x,
                                    y,
                                    x + kRacket_width,
                                    y + kRacket_height));
  }
};

}  // namespace mylibrary

#endif  // FINALPROJECT_RACKET_H
