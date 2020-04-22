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
#include <cinder/gl/gl.h>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <string>
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

namespace myapp {

using cinder::app::KeyEvent;

MyApp::MyApp() {

//    // initialize opengl (via glut)
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//    glutInitWindowSize(width, height);
//    glutCreateWindow("noobtuts.com Pong");
//
//    // start the whole thing
//    glutMainLoop();
   // return 0;

}


void MyApp::setup() {
  // cout<< "Hello World"<<endl;

}

void MyApp::update() { }

void MyApp::draw() {

  gl::clear();
  vec2 center = getWindowCenter();
  float r = 20;

  gl::color( Color( 1, 0, 0 ) ); // red
  gl::drawSolidCircle( center + vec2( -r, r ), r );

  drawRect(racket_left_x, racket_left_y, racket_width,  racket_height);
  drawRect(racket_right_x, racket_right_y,  racket_width,  racket_height);
}

void MyApp::keyDown(KeyEvent event) { }

}  // namespace myapp
