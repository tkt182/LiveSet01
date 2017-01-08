#include "RaiseParticles.h"

RaiseParticles::RaiseParticles(){
    
    glPointSize(2.0);
    billboards.setUsage(GL_DYNAMIC_DRAW);
    billboards.setMode(OF_PRIMITIVE_POINTS);
    
    maxParticles = 10000;
    numParticles = 0;
    
    swidth = ofGetWidth();
    sheight = ofGetHeight();
    sdepth = 480;
    
    for(int i = 0; i < 1000; i++){
        ofVec3f pos = ofVec3f(
            ofRandom(-swidth, swidth),
            //ofRandom(-sheight, sheight),
            ofRandom(-sheight, -sheight),
            ofRandom(-sdepth, sdepth)
        );
    
        positions.push_back(pos);
        billboards.addVertex(ofVec3f(positions[i].x, positions[i].y, positions[i].z));

        numParticles++;
    }

}

RaiseParticles::~RaiseParticles(){
    
}

void RaiseParticles::update(){

}

void RaiseParticles::draw(){
    billboards.draw();
}
