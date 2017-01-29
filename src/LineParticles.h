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
    void setLineGroup();
    void resetParticlePosition();
    
    
    int circleResolution;
    int slides;
    int radius;
    int particleNum;
    
    
    vector<ofVec3f> spherePoints;
    vector<ofVec3f> sphereLinePoints;
    vector<ofVec3f> velocity;
    vector<ofVec3f> particlePoints;
    vector<ofVec3f> linePoints;
    
    ofVboMesh renderedGeom;
    ofVboMesh renderedLineGeom;
    ofVboMesh sphereGeom;
    ofVboMesh sphereLineGeom;
    
    typedef struct{
        int numConnections;
        float velocity;
    } tPData;
    
    vector<tPData> particlesData;
    
    
};


#endif /* LineParticles_h */
