// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

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

const char kNormalFont[] = "Arial";

namespace myapp  {
using namespace ci;
using namespace ci::app;
using namespace std;
using namespace mylibrary;
using cinder::app::KeyEvent;
using namespace choreograph;

DECLARE_bool(crazy);
DECLARE_uint64(speed);
DECLARE_string(name);

MyApp::MyApp() {
  ball.setSpeed(FLAGS_speed);
  paused = false;
}

void MyApp::setup() {
  cinder::gl::enableDepthWrite();
  cinder::gl::enableDepthRead();
  left_racket.init(0.0f, 400.0f);
  right_racket.init(800 - kRacket_width - 0.0f, 400.0f);
  ball.init(kScreen_height/2, kScreen_width/2, -1.0f,
      0.0f, 30.0f, FLAGS_speed);

  if (FLAGS_crazy) {
    distraction.init(getWindowWidth(), getWindowHeight());
  }
    _timer.start();
}

void MyApp::update() {
  if (FLAGS_crazy) {
    distraction.move();
    _timer.start();
  }

  // hit by left racket?
  if (ball.getX() < left_racket.getX() + mylibrary::kRacket_width &&
      ball.getX() > left_racket.getX() &&
      ball.getY() < left_racket.getY() + mylibrary::kRacket_height &&
      ball.getY() > left_racket.getY()) {
    // set fly direction depending on where it hit the racket
    // (t is 0.5 if hit at top, 0 at center, -0.5 at bottom)
    float t = ((ball.getY() - left_racket.getY()) / mylibrary::kRacket_height) - 0.5f;
    ball.setDirX(fabs(ball.getDirX())); // force it to be positive
    ball.setDirY(t);
  }

  // hit by right racket?
  if (ball.getX() > right_racket.getX() &&
      ball.getX() < right_racket.getX() + mylibrary::kRacket_width &&
      ball.getY() < right_racket.getY() + mylibrary::kRacket_height &&
      ball.getY() > right_racket.getY()) {
    // set fly direction depending on where it hit the racket
    // (t is 0.5 if hit at top, 0 at center, -0.5 at bottom)
    float t = ((ball.getY() - right_racket.getY()) /
        mylibrary::kRacket_height) - 0.5f;
    ball.setDirX(-fabs(ball.getDirX())); // force it to be negative
    ball.setDirY(t);
  }

  // hit left wall?
  if (ball.getX() < 0) {
    right_racket.setScore(right_racket.getScore() + 1);
    ball.setX(app::getWindowWidth() / 2);
    ball.setY(app::getWindowHeight() / 2);
    ball.setDirX(fabs(ball.getDirX())); // force it to be positive
    ball.setDirY(0);
  }

  // hit right wall?
  if (ball.getX() > app::getWindowWidth()) {
    left_racket.setScore(left_racket.getScore() + 1);
    ball.setX(app::getWindowWidth() / 2);
    ball.setY(app::getWindowHeight() / 2);
    ball.setDirX(-fabs(ball.getDirX())); // force it to be negative
    ball.setDirY(0);
  }

  // hit top wall?
  if (ball.getY() > app::getWindowHeight()) {
    ball.setDirY(-fabs(ball.getDirY())); // force it to be negative
  }

  // hit bottom wall?
  if (ball.getY() < 0) {
    ball.setDirY(fabs(ball.getDirY())); // force it to be positive
  }

  ball.move();
}

void MyApp::draw() {

  gl::clear();
  float r = 20;

  left_racket.draw();
  right_racket.draw();
  ball.draw();
  const cinder::vec2 center = getWindowCenter();
  const cinder::ivec2 size = {200, 200};
  const Color colors = Color::white();

  std::stringstream ss;
  ss<< "Score = " << left_racket.getScore() << ":" << right_racket.getScore();

  PrintText(ss.str(), colors, size, {center.x, center.y});

  if(FLAGS_crazy) {
    distraction.draw();
  }

}

void MyApp::keyDown(KeyEvent event) {
    switch (event.getCode()) {
      case KeyEvent::KEY_UP:
     {
        right_racket.move_up();
        break;
      }
      case KeyEvent::KEY_DOWN:
      {
        right_racket.move_down();
        break;
      }
      case KeyEvent::KEY_w:
        {
          left_racket.move_up();
        break;
      }
      case KeyEvent::KEY_s:
        {
          left_racket.move_down();
        break;
      }
      case KeyEvent::KEY_p: {
//        paused = !paused;
//
//        if (paused) {
//          last_pause_time  = system_clock::now();
//        } else {
//          last_intact_time_ += system_clock::now() - last_pause_time_;
//        }
        break;
      }
      case KeyEvent::KEY_r: {
        // ResetGame();
        break;
      }
    }
}

template <typename C>
void MyApp::PrintText(const string& text, const C& color, const cinder::ivec2& size,
               const cinder::vec2& loc) {
  cinder::gl::color(color);

  auto box = TextBox()
      .alignment(TextBox::CENTER)
      .font(cinder::Font(kNormalFont, 30))
      .size(size)
      .color(color)
      .backgroundColor(ColorA(0, 0, 1, 0))
      .text(text);

  const auto box_size = box.getSize();
  const cinder::vec2 locp = {loc.x - box_size.x / 2, loc.y - box_size.y / 2};
  const auto surface = box.render();
  const auto texture = cinder::gl::Texture::create(surface);
  cinder::gl::draw(texture, locp);
}


}  // namespace myapp
