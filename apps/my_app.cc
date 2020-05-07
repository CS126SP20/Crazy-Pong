// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

namespace myapp  {

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace mylibrary;
using cinder::app::KeyEvent;
using namespace choreograph;
using namespace collision;
using cinder::app::KeyEvent;
using cinder::audio::VoiceRef;

DECLARE_bool(crazy);
DECLARE_uint64(speed);
DECLARE_uint64(duration);

MyApp::MyApp() {
  ball.setSpeed(FLAGS_speed);
  duration = FLAGS_duration;
  paused = false;
}

void MyApp::setup() {
  cinder::gl::enableDepthWrite();
  cinder::gl::enableDepthRead();
  cinder::audio::SourceFileRef source_background = cinder::audio::load
      (cinder::app::loadAsset("background.mp3"));
  background_music = cinder::audio::Voice::create(source_background);
  background_music -> start();
  left_racket.Init(0.0f, kScreen_height/kHalf);
  right_racket.Init(kScreen_width - kRacket_width - 0.0f,
      kScreen_height/kHalf);
  ball.Init(kScreen_height/kHalf, kScreen_width/kHalf,
      -1.0f,
      0.0f, kDefault_ball_size, FLAGS_speed);

  if (FLAGS_crazy) {
    distraction.init(getWindowWidth(), getWindowHeight());
    distraction2.init(getWindowWidth(), getWindowHeight());
    distraction3.init(getWindowWidth(), getWindowHeight());
    distraction4.init(getWindowWidth(), getWindowHeight());
  }
    _timer.start();
}

void MyApp::update() {
  if (game_over) {
    return;
  }

  if (FLAGS_crazy) {
    distraction.move();
    distraction2.move();
    distraction3.move();
    distraction4.move();
  }
  DidBallHitRacket(ball, left_racket, right_racket);
  DidBallHitWall(ball, left_racket, right_racket,
      getWindowWidth(), getWindowHeight() );
  ball.Move();


}

void MyApp::draw() {

  gl::clear();

  if (_timer.getSeconds() > duration * kMin_in_sec) {
     DrawGameOver();
     return;
  }

  left_racket.Draw();
  right_racket.Draw();
  ball.Draw();
  const cinder::vec2 center = getWindowCenter();
  const cinder::ivec2 size = {300, 100};
  const Color colors = Color::white();

  std::stringstream ss;
  int remaining_time = duration * kMin_in_sec - _timer.getSeconds();
  ss<< "Time Left: "<<remaining_time<< " sec\n"<<  "Left = " <<
  left_racket.getScore() << ": Right = " << right_racket.getScore() ;

  PrintText(ss.str(), colors, size, {center.x, 50});

  if(FLAGS_crazy) {
    distraction.draw();
    distraction2.draw();
    distraction3.draw();
    distraction4.draw();
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
    }
}

template <typename C>
void MyApp::PrintText(const string& text, const C& color,
    const cinder::ivec2& size,
               const cinder::vec2& loc) {
  cinder::gl::color(color);

  auto box = TextBox()
      .alignment(TextBox::CENTER)
      .font(cinder::Font(kNormalFont, 20))
      .size(size)
      .color(color)
      .backgroundColor(ColorA(0, 0, 1, 0))
      .text(text);

  const auto box_size = box.getSize();
  const cinder::vec2 locp = {loc.x - box_size.x / kHalf,
                             loc.y - box_size.y / kHalf};
  const auto surface = box.render();
  const auto texture = cinder::gl::Texture::create(surface);
  cinder::gl::draw(texture, locp);
}

void MyApp::DrawGameOver() {
  const cinder::vec2 center = getWindowCenter();
  const cinder::ivec2 size = {500, 500};
  const Color color = Color::white();

  _timer.stop();
  game_over = true;
  std::stringstream ss;
  ss<< "Game Over!" << " Congrats ";

  if (left_racket.getScore() > right_racket.getScore()) {
    ss<<"Left Player! You won " << left_racket.getScore()
      << ":"<< right_racket.getScore();
  } else if (right_racket.getScore() > left_racket.getScore()) {
    ss<<"Right Player! You won" << right_racket.getScore()
      << ":"<< left_racket.getScore();
  } else {
    ss<<"both players! It's a tie";
  }
  PrintText(ss.str(), color, size, center);
}

}  // namespace myapp
