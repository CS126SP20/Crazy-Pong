//
// Created by Riya Gupta on 5/5/20.
//

#ifndef FINALPROJECT_DISTRACTIONS_H
#define FINALPROJECT_DISTRACTIONS_H

#include <cinder/gl/gl.h>
#include <cinder/gl/draw.h>
#include <choreograph/Output.hpp>
#include <choreograph/Timeline.h>
#include <cinder/Vector.h>
#include <math.h>
#include <chrono>
#include <choreograph/Choreograph.h>
#include <choreograph/Timeline.h>
#include <cinder/timer.h>

using namespace choreograph;
using namespace cinder;
class Distraction {

  PhraseRef<vec2> bounce;
  PhraseRef<vec2> slide;
  PhraseRef<vec2> bounce_and_slide;
  PhraseRef<vec2> bounce_and_slide_negative;
  choreograph::Output<ci::vec2> _position_a;
  choreograph::Timeline _timeline;
  cinder::Timer mytimer;
  int _width;
  int _height;

 private:
  // Computes a random starting y position for
  // each animation
  void ComputeDistraction();
 public:
  // Initializes distraction object
  void init(int width, int height);
  // Draws distraction object
  void draw();
  // Moves distraction object with Choreograph
  void move();
};
#endif  // FINALPROJECT_DISTRACTIONS_H