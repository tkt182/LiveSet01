//
//  LineParticles.hpp
//  LiveSet01
//
//  Created by 高田 信一郎 on 2017/01/25.
//
//

#ifndef LineParticles_h
#define LineParticles_h

#include "ofMain.h"

class LineParticles {
    
public:
    LineParticles();
    ~LineParticles();
    
    void update();
    void draw();
    
    int circleResolution;
    int slides;
    int radius;
    
    
    vector<ofVec3f> spherePoints;
    ofVboMesh sphereGeom;
    
};


#endif /* LineParticles_h */
