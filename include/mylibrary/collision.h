//
// Created by Riya Gupta on 5/6/20.
//

#ifndef FINALPROJECT_COLLISION_H
#include "mylibrary/ball.h"
#include "mylibrary/racket.h"

#define FINALPROJECT_COLLISION_H


using namespace mylibrary;

namespace collision {
// Method returns true if ball collided with the left or right racket
bool DidBallHitRacket(Ball& ball, Racket& left, Racket& right);
// Method returns true if ball collided with the left or right wall
bool DidBallHitWall(Ball& ball, Racket& left, Racket& right, int width,
                    int height);
}
#endif  // FINALPROJECT_COLLISION_H