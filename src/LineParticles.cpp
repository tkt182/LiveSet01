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
            
            velocity.push_back(
                ofVec3f(ofRandom(10.), ofRandom(10.), ofRandom(10.))
            );
            
        }
    }
    
    sphereGeom.setMode(OF_PRIMITIVE_POINTS);
    sphereLineGeom.setMode(OF_PRIMITIVE_LINES);
}

LineParticles::~LineParticles(){
}

void LineParticles::update(){
    
    vector<ofVec3f>::iterator itr;
    for(itr = spherePoints.begin(); itr != spherePoints.end(); itr++){
        sphereGeom.addVertex(*(itr));
    }
    
    vector<ofVec3f>::iterator itrL;
    for(itrL = sphereLinePoints.begin(); itrL != sphereLinePoints.end(); itrL++){
        sphereLineGeom.addVertex(*(itrL));
    }
    
    
}


void LineParticles::draw(){
    sphereGeom.draw();
    sphereLineGeom.draw();
}


void LineParticles::setLineGroup(){

    sphereLinePoints.clear();
    sphereLineGeom.clear();
    
    int maxLineParticlepNum = spherePoints.size();
    int lineParticleNum     = ofRandom(10, maxLineParticlepNum);
    
    for(int i = 0; i < lineParticleNum; i++){
        int target = ofRandom(0, spherePoints.size());
        sphereLinePoints.push_back(spherePoints[target]);
    }

}



