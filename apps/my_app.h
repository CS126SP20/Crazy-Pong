// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <cinder/gl/gl.h>
#include <cinder/audio/audio.h>
#include <cinder/audio/Voice.h>

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

  // rackets in general
  int racket_width = 10;
  int racket_height = 80;
  int racket_speed = 3;

// left racket position
  float racket_left_x = 10.0f;
  float racket_left_y = 400.0f;

// right racket position
  float racket_right_x = 800 - racket_width - 10; // Later replace 800 by myapp::kWidth
  float racket_right_y = 400.0f;

  void drawRect(float x, float y, float width, float height) {

    cinder::gl::color(Color(0, 1, 0));
    cinder::gl::drawSolidRect(Rectf(x,
                                    y,
                                    x+width,
                                    y+height));
  }

 public:
  MyApp();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
