#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetLineWidth(1);
  ofSetVerticalSync(true);
  ofEnableDepthTest();
  ofEnableNormalizedTexCoords();
  base.loadImage("rocks.jpg");
  base.resize(width, height);
  num_particles = 1000;
  width = ofGetWidth();
  height = ofGetHeight();
  for(int i = 0; i < num_particles; i++){
    particles.push_back(Particle(ofVec3f(width/2+ofRandom(-20, 20), height/2+ofRandom(-20, 20), ofRandom(-200, 200)), &base));
  }
  ofEnableDepthTest();
  glEnable(GL_POINT_SMOOTH); // use circular points instead of square points
  glPointSize(5);
  ofBackground(255);
  ofSetBackgroundAuto(true);
}

//--------------------------------------------------------------
void ofApp::update(){
  for(int i = 0; i < num_particles; i++){
    particles[i].update();
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  cam.begin();
  ofTranslate(-width/2, -height/2, 300);
  for(int i = 0; i < num_particles; i++){
    particles[i].display();
  }
  cam.end();
  mesh.clear();
}



