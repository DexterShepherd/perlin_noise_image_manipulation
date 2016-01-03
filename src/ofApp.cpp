#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetLineWidth(1);
  ofSetVerticalSync(true);
  ofEnableDepthTest();
  ofEnableNormalizedTexCoords();
  mesh.setMode(OF_PRIMITIVE_POINTS);
  num_particles = 50000;
  width = ofGetWidth();
  height = ofGetHeight();
  for(int i = 0; i < num_particles; i++){
    particles.push_back(Particle(Particle(ofVec3f(ofRandom(width), ofRandom(height), ofRandom(-200, 200)))));
  }
  ofEnableDepthTest();
  glEnable(GL_POINT_SMOOTH); // use circular points instead of square points
  glPointSize(2);
  ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){
  for(int i = 0; i < num_particles; i++){
    particles[i].update();
  }
  for(int i = 0; i < num_particles; i++){
    mesh.addColor(ofColor(255));
    mesh.addVertex(particles[i].display());
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  cam.begin();
  ofTranslate(-width/2, -height/2, 700);
  mesh.draw();
  cam.end();
  mesh.clear();
}

