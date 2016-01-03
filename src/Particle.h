//
//  Particle.h
//  perlin_images
//
//  Created by Dexter Shepherd on 1/2/16.
//
//

#ifndef __perlin_images__Particle__
#define __perlin_images__Particle__

#include <stdio.h>
#include "ofMain.h"

class Particle{
  public:
    Particle(ofVec3f l);
    void update();
    ofVec3f display();
  private:
    bool edge_detect(ofVec3f l);
    ofVec3f loc, delta;
    float angle, step_size, noise_scale, noise_max;
    ofColor col;
};

#endif /* defined(__perlin_images__Particle__) */
