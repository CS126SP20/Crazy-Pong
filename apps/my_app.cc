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



namespace myapp  {

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace mylibrary;
using cinder::app::KeyEvent;
using namespace choreograph;

MyApp::MyApp() {

}


void MyApp::setup() {
  left_racket.init(1.0f, 400.0f);
  right_racket.init(800 - kRacket_width - 1.0f, 400.0f);
  // Ball::init(float ball_x, float ball_y, float ball.getDirX(), float ball.getDirY(), float ball_size, float ball_speed )
  ball.init(kScreen_height/2, kScreen_width/2, -1.0f, 0.0f, 30.0f, 2.0f);
  paused = false;

//  // Create a procedural phrase that moves vertically on a sine wave.
//  // Procedural phrases can evaluate any function you like.
//  PhraseRef<vec2> bounce = makeProcedure<vec2>( 2.0, [] ( Time t, Time duration ) {
//    // return vec2( 0, sin( easeInOutQuad(t) * 6 * M_PI ) * 100.0f );
//    return vec2( 0,  100.0f );
//  } );
//
//  // Create a ramp phrase from the left to the right side of the window.
//  float w = (float)app::getWindowWidth();
//  float x1 = w * 0.08f;
//  float x2 = w - x1;
//  PhraseRef<vec2> slide = makeRamp( vec2( x1, 0 ), vec2( x2, 0 ), 2.0f, EaseInOutCubic() );
//
//  // Combine the slide and bounce phrases using an AccumulatePhrase.
//  // By default, the accumulation operation sums all the phrase values with an initial value.
//  float center_y = app::getWindowHeight() / 2.0f;
//  PhraseRef<vec2> bounce_and_slide = makeAccumulator( vec2( 0, center_y ), bounce, slide );
//
//  // Provide an explicit combine function.
//  // In this case, we subtract each value from the initial value.
//  PhraseRef<vec2> bounce_and_slide_negative = makeAccumulator( vec2( w, center_y ), bounce, slide, [] (const vec2 &a, const vec2 &b) {
//    return a - b;
//  } );

//  // Apply our Sequences to Outputs.
//  _timeline.apply( &_position_a, bounce_and_slide );
//  _timeline.apply( &_position_b, bounce_and_slide_negative );
//  _timeline.apply( &_reference_bounce, bounce );
//  _timeline.apply( &_reference_slide, slide );
//
//  // Place Outputs at initial sequence values.
//  _timeline.jumpTo( 0 );
//
    _timer.start();
}

void MyApp::update() {
  // Time dt = (Time)_timer.getSeconds();
  // _timer.start();
  // _timeline.step( dt );

  ball.move();
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
    float t = ((ball.getY() - right_racket.getY()) / mylibrary::kRacket_height) - 0.5f;
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
  
}

void MyApp::draw() {

  gl::clear();
  // vec2 center = getWindowCenter();

  float r = 20;

//  gl::color( Color( 1, 0, 0 ) ); // red
//  gl::drawSolidCircle( center + vec2( -r, r ), r );

  left_racket.draw();
  right_racket.draw();
  ball.draw();

//  gl::ScopedColor color( Color( CM_HSV, 0.72f, 1.0f, 1.0f ) );
//  gl::drawSolidCircle( _position_a, 30.0f );

//  gl::color( Color( CM_HSV, 0.96f, 1.0f, 1.0f ) );
//  gl::drawSolidCircle( _position_b, 30.0f );

  // References are translated for visibility.
  float y = app::getWindowHeight() * 0.2f;
  gl::color( Color( CM_HSV, 0.15f, 1.0f, 1.0f ) );

//  gl::drawStrokedCircle( _reference_bounce() + vec2( app::getWindowWidth() * 0.08f, y ), 4.0f );
//  gl::drawStrokedCircle( _reference_slide() + vec2( 0, y ), 4.0f );


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

}  // namespace myapp
