//
//  Particle.cpp
//  perlin_images
//
//  Created by Dexter Shepherd on 1/2/16.
//
//

#include "Particle.h"
Particle::Particle(ofVec3f l){
  loc = l;
  angle = 0;
  step_size = ofRandom(0.001, 1.00);
  noise_scale = 0.05;
  noise_max = 10;
  shape.setMode(OF_PRIMITIVE_POINTS);
  //add color code
}

void Particle::update(){
  if(edge_detect(loc)){
    loc.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), ofRandom(-500, 500));
    shape.clear();
  }
  angle = ofNoise(loc.x * noise_scale, loc.y * noise_scale, 0) * noise_max;
  delta.set(cos(angle) * step_size, sin(angle)*step_size, 0);
  loc += delta;
  
  shape.addVertex(loc);
  shape.addColor(ofColor(255));
  if (shape.getNumVertices() > 20) {
    shape.removeVertex(0);
    shape.removeColor(0);
  }
}

ofVec3f Particle::display(){
  shape.draw();
}

bool Particle::edge_detect(ofVec3f l){
  if(l.x < 0 || l.x > ofGetWidth()){
    return true;
  }else if(l.y < 0 || l.y > ofGetHeight()){
    return true;
  }else if(l.z < -500 || l.z > 500){
    return true;
  }else{
    return false;
  }
}