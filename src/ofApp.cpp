#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetLineWidth(1);
  ofSetVerticalSync(true);
  ofEnableDepthTest();
  ofEnableNormalizedTexCoords();
  mesh.setMode(OF_PRIMITIVE_POINTS);
  num_particles = 1000;
  width = ofGetWidth();
  height = ofGetHeight();
  for(int i = 0; i < num_particles; i++){
    particles.push_back(Particle(Particle(ofVec3f(ofRandom(width), ofRandom(height), ofRandom(-200, 200)))));
  }
  ofEnableDepthTest();
  glEnable(GL_POINT_SMOOTH); // use circular points instead of square points
  glPointSize(1);
  ofBackground(0);
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

