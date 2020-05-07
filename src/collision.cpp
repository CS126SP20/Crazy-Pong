//
// Created by Riya Gupta on 5/6/20.
//
#include "mylibrary/collision.h"

bool collision::DidBallHitRacket(Ball& ball, Racket& left, Racket& right) {
  // hit by left racket?
  if (ball.getX() <= left.getX() + mylibrary::kRacket_width &&
      ball.getX() >= left.getX() &&
      ball.getY() <= left.getY() + mylibrary::kRacket_height &&
      ball.getY() >= left.getY()) {
    std::cout << "Hit left racket\n";
    // set fly direction depending on where it hit the racket
    // (t is 0.5 if hit at top, 0 at center, -0.5 at bottom)
    float t = ((ball.getY() - left.getY()) / mylibrary::kRacket_height) - 0.5f;
    ball.setDirX(fabs(ball.getDirX())); // force value positive
    ball.setDirY(t);
    return true;
  }

  // hit by right racket?
  if (ball.getX() >= right.getX() &&
      ball.getX() <= right.getX() + mylibrary::kRacket_width &&
      ball.getY() <= right.getY() + mylibrary::kRacket_height &&
      ball.getY() >= right.getY()) {
    std::cout << "Hit right racket\n";
    // set fly direction depending on where it hit the racket
    // (t is 0.5 if hit at top, 0 at center, -0.5 at bottom)
    float t = ((ball.getY() - right.getY()) /
               mylibrary::kRacket_height) - 0.5f;
    ball.setDirX(-fabs(ball.getDirX())); // force value negative
    ball.setDirY(t);
    return true;
  }
  return false;
}


bool collision::DidBallHitWall(Ball& ball, Racket& left, Racket& right,
    int width, int height){
    // hit left wall?
    if (ball.getX() < 0) {
      // std::cout << "Hit left wall\n";
      right.setScore(right.getScore() + 1);
      ball.setX( width / 2);
      ball.setY(height / 2);
      ball.setDirX(fabs(ball.getDirX())); // force value positive
      ball.setDirY(0);
      return true;
    }

    // hit right wall?
    if (ball.getX() > width) {
      // std::cout << "Hit right wall\n";
      left.setScore(left.getScore() + 1);
      ball.setX(width / 2);
      ball.setY( height / 2);
      ball.setDirX(-fabs(ball.getDirX())); // force value negative
      ball.setDirY(0);
      return true;
    }

    // hit top wall?
    if (ball.getY() > height ) {
      ball.setDirY(-fabs(ball.getDirY())); // force value negative
      return true;
    }

    // hit bottom wall?
    if (ball.getY() < 0) {
      ball.setDirY(fabs(ball.getDirY())); // force value positive
      return true;
    }
    return false;
}

