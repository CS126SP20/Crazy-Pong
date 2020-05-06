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

#endif  // FINALPROJECT_DISTRACTIONS_H

using namespace choreograph;
using namespace cinder;
class Distraction {

  PhraseRef<vec2> bounce;
  PhraseRef<vec2> slide;
  PhraseRef<vec2> bounce_and_slide;
  PhraseRef<vec2> bounce_and_slide_negative;


  choreograph::Output<ci::vec2> _position_a;
  choreograph::Output<ci::vec2>  variable;
  choreograph::Output<ci::vec2> _position_b;

  choreograph::Output<ci::vec2> _reference_bounce;
  choreograph::Output<ci::vec2> _reference_slide;
  choreograph::Timeline            _timeline;
  int _width;
  int _height;

 public:
  void init(int width, int height);
  void draw();
  void move(Timer &timer);
};
