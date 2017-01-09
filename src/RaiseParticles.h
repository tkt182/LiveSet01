//
//  RaiseParticles.h
//  LiveSet01
//
//  Created by 高田 信一郎 on 2017/01/06.
//
//

#ifndef RaiseParticles_h
#define RaiseParticles_h

#include "ofMain.h"
#include "ofxEasing.h"

class RaiseParticles {
public:
    RaiseParticles();
    ~RaiseParticles();
    
    void update();
    void draw();
    void setCurrentTime();
    
    int numParticles;
    int maxParticles;
    int swidth, sheight, sdepth;
    
    deque<ofVec3f> positions;
    deque<float> movePosition;
    float initTime;
    float endPosition;
    
    GLfloat defaultDistance[3];
    ofVboMesh billboards;
    
};


#endif /* RaiseParticles_h */
