//
//  Particle.cpp
//  perlin_images
//
//  Created by Dexter Shepherd on 1/2/16.
//
//

#include "Particle.h"
Particle::Particle(ofVec3f l, ofImage* img){
  loc = l;
  angle = 0;
  len = 100;
  step_size = ofRandom(0.001, 2.00);
  noise_scale = 0.01;
  noise_max = 4;
  image = img;
  shape.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
  col = image->getColor(ofMap(loc.x, 0, ofGetWidth(), 0, img->getWidth()), ofMap(loc.y, 0, ofGetHeight(), 0, image->getHeight()));
}

void Particle::update(){
  if(edge_detect(loc)){
    loc.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), ofRandom(-500, 500));
    shape.clear();
  }
  angle = ofNoise(loc.x * noise_scale, loc.y * noise_scale, loc.z * noise_scale) * noise_max;
  delta.set(cos(angle) * step_size, sin(angle)*step_size, ofRandom(-1.000, 1.000));
  loc += delta;
  
  shape.addVertex(loc);
  shape.addColor(col);
  
  for(int i = shape.getNumVertices()-1; i >= 0; i--){
    ofColor update = image->getColor(shape.getVertex(i).x, shape.getVertex(i).y);
    update.a = ofMap(i, shape.getNumColors(), 0, 255, 0);
    shape.setColor(i, update);
  }
  if (shape.getNumVertices() > len) {
    shape.removeVertex(0);
    shape.removeColor(0);
  }
}

ofVec3f Particle::display(){
  shape.draw();
}

bool Particle::edge_detect(ofVec3f l){
  if(l.x < 0 || l.x > image->getWidth()){
    return true;
  }else if(l.y < 0 || l.y > image->getHeight()){
    return true;
  }else if(l.z < -500 || l.z > 500){
    return true;
  }else{
    return false;
  }
}