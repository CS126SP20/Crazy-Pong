// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

const char kNormalFont[] = "Arial";

namespace myapp  {
using namespace ci;
using namespace ci::app;
using namespace std;
using namespace mylibrary;
using cinder::app::KeyEvent;
using namespace choreograph;
using namespace collision;

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
  left_racket.Init(0.0f, 400.0f);
  right_racket.Init(800 - kRacket_width - 0.0f, 400.0f);
  ball.Init(kScreen_height/2, kScreen_width/2, -1.0f,
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


  DidBallHitRacket(ball, left_racket, right_racket);


  DidBallHitWall(ball, left_racket, right_racket, getWindowWidth(), getWindowHeight() );

  ball.Move();
}

void MyApp::draw() {

  gl::clear();
  float r = 20;

  left_racket.Draw();
  right_racket.Draw();
  ball.Draw();
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
        right_racket.MoveUp();
        break;
      }
      case KeyEvent::KEY_DOWN:
      {
        right_racket.MoveDown();
        break;
      }
      case KeyEvent::KEY_w:
        {
          left_racket.MoveUp();
        break;
      }
      case KeyEvent::KEY_s:
        {
          left_racket.MoveDown();
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
