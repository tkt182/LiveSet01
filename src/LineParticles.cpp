//
//  LineParticles.cpp
//  LiveSet01
//
//  Created by 高田 信一郎 on 2017/01/25.
//
//

#include "LineParticles.h"


LineParticles::LineParticles(){

    // Sphere
    circleResolution = 20;
    slides = 20;
    radius = 100;
    
    for(int i=0; i<20; i++){
        
        float angle1 = TWO_PI/slides*i;
        float bx = sin(angle1);
        float by = 1.;
        float bz = cos(angle1);
        
        
        for(int j=0; j<circleResolution; j++){
        
            float angle2=TWO_PI/circleResolution*j;
            float x=cos(angle2)*radius*bx;
            float y=sin(angle2)*radius*by;
            float z=cos(angle2)*radius*bz;
        
            spherePoints.push_back(ofVec3f(x,y,z));
        }
    }
    
    sphereGeom.setMode(OF_PRIMITIVE_POINTS);
}

LineParticles::~LineParticles(){
}

void LineParticles::update(){
    
    vector<ofVec3f>::iterator itr;
    for(itr = spherePoints.begin(); itr != spherePoints.end(); itr++){
        sphereGeom.addVertex(*(itr));
    }
}

void LineParticles::draw(){
    sphereGeom.draw();
}