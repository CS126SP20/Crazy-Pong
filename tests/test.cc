// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <string>
#include "mylibrary/collision.h"
#include "mylibrary/ball.h"
#include "mylibrary/racket.h"
#include <catch2/catch.hpp>

TEST_CASE("Collision", "[collision]") {
  Ball ball;
  Racket left_racket, right_racket;
  left_racket.Init(0.0f, 400.0f);
  right_racket.Init(800 - kRacket_width - 0.0f, 400.0f);

  SECTION("Ball Hitting Left Wall") {
    ball.Init(0, 0, -1.0f,
              0.0f, 30.0f, 5);
    ball.Move();
    REQUIRE(collision::DidBallHitWall(ball, left_racket, right_racket,
        800, 800) == true);
  }

  SECTION("Ball Hitting Right Wall") {
    ball.Init(800, 0, 1.0f,
              0.0f, 30.0f, 5);
    ball.Move();
    REQUIRE(collision::DidBallHitWall(ball, left_racket, right_racket,
        800, 800) == true);
  }

  SECTION("Ball Hitting Left Racket") {
    ball.Init(0, 400, -1.0f,
              0.0f, 30.0f, 5);

    REQUIRE(collision::DidBallHitRacket(ball, left_racket,
        right_racket) == true);

  }

  SECTION("Ball Hitting Right Racket") {
    ball.Init(800 - kRacket_width - 0.0f, 400.0f, 1.0f,
              0.0f, 30.0f, 5);
    REQUIRE(collision::DidBallHitRacket(ball, left_racket,
        right_racket) == true);

  }

}

TEST_CASE("Score", "[score]") {
  Ball ball;
  Racket left_racket, right_racket;
  left_racket.Init(0.0f, 400.0f);
  right_racket.Init(800 - kRacket_width - 0.0f, 400.0f);

  SECTION("Left Player Point") {
    int score = left_racket.getScore();
    ball.Init(800, 0, 1.0f,
              0.0f, 30.0f, 5);
    ball.Move();
    REQUIRE(collision::DidBallHitWall(ball, left_racket, right_racket,
                                      800, 800) == true);
    REQUIRE(left_racket.getScore() > score);

  }

  SECTION("Right Player Point") {
    int score = right_racket.getScore();
    ball.Init(0, 0, -1.0f,
              0.0f, 30.0f, 5);
    ball.Move();
    REQUIRE(collision::DidBallHitWall(ball, left_racket, right_racket,
                                      800, 800) == true);
    REQUIRE(right_racket.getScore() > score);
  }
}

