#pragma once

#include "ofMain.h"
#include "Particle.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
    ofMesh mesh;
  
  private:
    vector<Particle> particles;
    ofLight light;
    ofEasyCam cam;
    int width, height, num_particles;
};
