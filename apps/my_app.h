// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <choreograph/Timeline.h>
#include <cinder/app/App.h>
#include <cinder/audio/Voice.h>
#include <cinder/audio/audio.h>
#include <cinder/gl/gl.h>
#include <choreograph/Output.hpp>
#include "mylibrary/ball.h"
#include "mylibrary/distractions.h"
#include "mylibrary/racket.h"
#include <cinder/app/App.h>
#include <iostream>
#include "cinder/app/RendererGL.h"
#include "cinder/gl/gl.h"
#include <cinder/Font.h>
#include <cinder/Text.h>
#include <cinder/Vector.h>
#include <cinder/audio/audio.h>
#include <cinder/audio/Voice.h>
#include <cinder/gl/draw.h>
#include <math.h>
#include <algorithm>
#include <chrono>
#include <cmath>
#include <string>
#include "cinder/Rand.h"
#include "mylibrary/racket.h"
#include <choreograph/Choreograph.h>
#include <choreograph/Timeline.h>
#include <gflags/gflags_declare.h>
#include <gflags/gflags.h>>
#include "mylibrary/collision.h"

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
  int duration;  // duration of the game in minutes.
  Racket left_racket;
  Racket right_racket;
  Ball ball;
  Distraction distraction;
  Distraction distraction2;
  Distraction distraction3;
  Distraction distraction4;
  VoiceRef background_music;
  bool paused;
  bool game_over = false;
  const int kScreen_width = 800;
  const int kScreen_height = 800;
  const int kHalf = 2;
  const int kMin_in_sec = 60;
  const float kDefault_ball_size = 30.0f;
  const char *kNormalFont = "Arial";

 private:
  // Draws the screen for when the game ends
  // includes printing a congrats message for the
  // winning player
   void DrawGameOver();
 public:
  Timer _timer;
  MyApp();
  // Initializes ball, rackets, distractions
  void setup() override;
  // Updates/moves ball, racket, objects / handles timer
  void update() override;
  // Draws all objects on screen
  void draw() override;
  // Handles moving rackets with keys on keyboard
  void keyDown(cinder::app::KeyEvent) override;
  template <typename C>
  // Derived from CS126 Snake application
  void PrintText(const string& text, const C& color, const cinder::ivec2& size,
                 const cinder::vec2& loc);
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
