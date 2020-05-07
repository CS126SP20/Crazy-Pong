//
// Created by Riya Gupta on 4/21/20.
//

#ifndef FINALPROJECT_RACKET_H
#include <cinder/gl/gl.h>
#define FINALPROJECT_RACKET_H

using namespace cinder;

namespace  mylibrary {

const int kRacket_width = 10;
const int kRacket_height = 100;
const int kRacket_speed = 20;

class Racket  {
  //racket position
  float x;
  float y;
  int score;

 public:
  // Constructor to initialize score and
  // racket coordinates
  Racket();
  // Initializes racket object
  void Init( float a, float b);
  // Draws racket object
  void Draw();
  // Moves racket up
  void MoveUp();
  // Moves racket down
  void MoveDown();
  // Getter for x coordinate or racket
  float getX() const;
  // Getter for y coordinate or racket
  float getY() const;
  // Getter for player's score on a certain racket
  int getScore() const;
  // Setter for player's score on a certain racket
  void setScore(int score);
};
}  // namespace mylibrary

#endif  // FINALPROJECT_RACKET_H
