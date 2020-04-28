//
// Created by Riya Gupta on 4/27/20.
//
#include "mylibrary/racket.h";
using namespace mylibrary;

Racket::Racket() { x = 0.0f; y = 0.0f; score = 0; }
float Racket::getX() const { return x; }
float Racket::getY() const { return y; }
void Racket::init( float a, float b) { x = a; y = b; }
int Racket::getScore() const { return score; }
void Racket::setScore(int score) { Racket::score = score; }

void Racket::draw() {
  cinder::gl::color(Color(0, 1, 0));
  cinder::gl::drawSolidRect(Rectf(x,
                                  y,
                                  x + kRacket_width,
                                  y + kRacket_height));
}

void Racket::move_up() {
  y -= kRacket_speed;

}

void Racket::move_down() {
  y += kRacket_speed;
}