#include "RaiseParticles.h"

RaiseParticles::RaiseParticles(){
    
    //static GLfloat distance[] = { 0.0, 0.0, 1.0 };
    //static GLfloat distance[] = { 1.0, 0.0, 0.0 };
    //glGetFloatv(GL_POINT_DISTANCE_ATTENUATION, defaultDistance);
    //glPointParameterfv(GL_POINT_DISTANCE_ATTENUATION, distance);
    //glPointSize(10000.0);
    
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
    
    // Easing
    initTime = 0.f;
    endPosition = sheight;
    

}

RaiseParticles::~RaiseParticles(){
    
}

void RaiseParticles::update(){
    
    float duration = 1.f;
    float endTime = initTime + duration;
    float now = ofGetElapsedTimef();
    
    for(int i = 0; i < positions.size(); i++){
        ofVec3f pos = positions[i];
        positions[i].y = ofxeasing::map_clamp(now, initTime, endTime, -sheight, endPosition, &ofxeasing::linear::easeIn);
        billboards.getVertices()[i].set(pos);
    }

}

void RaiseParticles::draw(){
    billboards.draw();
}

void RaiseParticles::setCurrentTime(){
    initTime = ofGetElapsedTimef();
}
