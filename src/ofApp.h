#pragma once

#include "ofMain.h"
#include "Particle.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
    void mouseScrolled(int x, int y, float scrollX, float scrollY);
    ofMesh mesh;
    ofImage base;
  
  private:
    vector<Particle> particles;
    ofLight light;
    ofEasyCam cam;
    int width, height, num_particles;
};
