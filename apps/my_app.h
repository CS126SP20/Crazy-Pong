// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <cinder/audio/Voice.h>
#include <cinder/audio/audio.h>
#include <cinder/gl/gl.h>
//#include "cinder/Timeline.h"
#include <choreograph/Output.hpp>
#include <choreograph/Timeline.h>

#include "mylibrary/racket.h"
#include "mylibrary/ball.h"

using namespace mylibrary;
using namespace choreograph;

namespace myapp {
using cinder::Color;
using cinder::ColorA;
using cinder::Rectf;
using cinder::TextBox;
using cinder::app::KeyEvent;
using cinder::audio::VoiceRef;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::system_clock;
using std::string;

class MyApp : public cinder::app::App {

  Racket left_racket;
  Racket right_racket;
  Ball ball;
  bool paused;
  const int kScreen_width = 800;
  const int kScreen_height = 800;


  choreograph::Output<ci::vec2> _position_a;
  choreograph::Output<ci::vec2>  variable;
  choreograph::Output<ci::vec2> _position_b;

  choreograph::Output<ci::vec2> _reference_bounce;
  choreograph::Output<ci::vec2> _reference_slide;
  choreograph::Timeline            _timeline;
  Timer               _timer;

 public:
  MyApp();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;
  template <typename C>
  void PrintText(const string& text, const C& color, const cinder::ivec2& size,
                 const cinder::vec2& loc);
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
