//
// Created by Riya Gupta on 5/5/20.
//
#include "mylibrary/distractions.h"
#include "mylibrary/collision.h"
#include <cstdlib>
#include <ctime>
#include <thread>

using namespace choreograph;
using namespace cinder;


void Distraction::ComputeDistraction() {
  srand(time(NULL));

  bounce = makeProcedure<vec2>(2.0, [](Time t, Time duration) {
    return vec2(0, sin(easeInOutQuad(t) * 6 * M_PI) * 100.0f);
  });

  // Create a ramp phrase from the left to the right side of the window.
  float x1 = _width * 0.02f;
  float x2 = _width - x1;
  int y = rand() % _height / 2 + 1;
  slide =
      makeRamp(vec2(x1, y), vec2(x2, y), 2.0f,
          choreograph::EaseInOutCubic());

  // Combine the slide and bounce phrases using an AccumulatePhrase.
  // By default, the accumulation operation sums all the phrase values
  // with an initial value.
  float center_y = _height / 2.0f;
  bounce_and_slide = makeAccumulator(vec2(0, center_y),
      bounce, slide);

  // Provide an explicit combine function.
  // In this case, we subtract each value from the initial value.
  bounce_and_slide_negative =
      makeAccumulator(vec2(_width, center_y), bounce, slide,
                      [](const vec2 &a, const vec2 &b) { return a - b; });
}

void Distraction::init(int width, int height) {
  // Create a procedural phrase that moves vertically on a sine wave.
  // Procedural phrases can evaluate any function you like.
  _width = width;
  _height = height;

  std::chrono::milliseconds timespan(rand()%1000 + 1); // or whatever
  std::this_thread::sleep_for(timespan);
  ComputeDistraction();

  // Apply our Sequences to Outputs.
  _timeline.apply( &_position_a, bounce_and_slide );

  // Place Outputs at initial sequence values.
  _timeline.jumpTo( 0 );
  mytimer.start();
}

void Distraction::move() {
  static int count = 0;
  Time dt = (Time)mytimer.getSeconds();
  _timeline.step(1.0 / 60.0);

  if (dt > 2.0f) {
    count++;
    mytimer.stop();

    ComputeDistraction();

    if (count % 2 == 0) {
      _timeline.jumpTo( 0 );
      _timeline.apply(&_position_a, bounce_and_slide);
    } else {
      _timeline.apply(&_position_a, bounce_and_slide_negative);
    }
    mytimer.start();
  }
}

void Distraction::draw() {
  gl::color( Color( CM_HSV, 0.96f, 1.0f, 1.0f ) );
  gl::drawSolidCircle( _position_a, 30.0f );
}