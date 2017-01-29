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
    particleNum = circleResolution*circleResolution;
    
    for(int i=0; i<circleResolution; i++){
        
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
            
            //velocity.push_back(
            //    ofVec3f(ofRandom(10.), ofRandom(10.), ofRandom(10.))
            //);
            
        }
    }
    
    
    for(int j=0; j<particleNum; j++){
            
        //float angle2=TWO_PI/circleResolution*j;
        float x=ofRandom(-radius, radius);
        float y=ofRandom(-radius, radius);
        float z=ofRandom(-radius, radius);
            
        particlePoints.push_back(ofVec3f(x,y,z));
            
        //velocity.push_back(
        //    ofVec3f(ofRandom(10.), ofRandom(10.), ofRandom(10.))
        //);
        tPData particleData;
        particleData.numConnections = 0;
        particleData.velocity = ofRandom((-10.f, 10.f));
        
        particlesData.push_back(particleData);
        
    }
    
    renderedGeom.setMode(OF_PRIMITIVE_POINTS);
    renderedLineGeom.setMode(OF_PRIMITIVE_LINES);
}

LineParticles::~LineParticles(){
}

void LineParticles::update(){

    float morphingSpeed = 0.05;
    float minDistance   = 20.0;
    int vertexIndex     = 0;

    linePoints.clear();
    
    for(int i = 0; i < particleNum; i++){
        
        tPData particleData = particlesData[i];
        ofVec3f currentPos  = particlePoints[i];
        
        particlePoints[i].x = currentPos.x*(1. - morphingSpeed)+spherePoints[i].x*morphingSpeed;
        particlePoints[i].y = currentPos.y*(1. - morphingSpeed)+spherePoints[i].y*morphingSpeed;
        particlePoints[i].z = currentPos.z*(1. - morphingSpeed)+spherePoints[i].z*morphingSpeed;
       
        for(int j = i + 1; j < particleNum; j++){
            
            if(particleData.numConnections >= 3) continue;
            
            float dx = particlePoints[i].x - particlePoints[j].x;
            float dy = particlePoints[i].y - particlePoints[j].y;
            float dz = particlePoints[i].z - particlePoints[j].z;
            
            float dist = sqrt(dx*dx + dy*dy + dz*dz);
            
            if(dist < minDistance){
                particleData.numConnections++;
                linePoints.push_back(particlePoints[i]);
                linePoints.push_back(particlePoints[j]);
            }
            
        }
        
    }

    
    /*
    vector<ofVec3f>::iterator itrL;
    for(itrL = sphereLinePoints.begin(); itrL != sphereLinePoints.end(); itrL++){
        sphereLineGeom.addVertex(*(itrL));
    }
    */
    
}


void LineParticles::draw(){
    
    renderedGeom.clear();
    renderedLineGeom.clear();
    
    vector<ofVec3f>::iterator itr;
    for(itr = particlePoints.begin(); itr != particlePoints.end(); itr++){
        renderedGeom.addVertex(*(itr));
    }
    
    vector<ofVec3f>::iterator itrL;
    for(itrL = linePoints.begin(); itrL != linePoints.end(); itrL++){
        renderedLineGeom.addVertex(*(itrL));
    }
    
    renderedGeom.draw();
    renderedLineGeom.draw();
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


void LineParticles::resetParticlePosition(){
    
    vector<ofVec3f>::iterator itr;
    
    for(itr = particlePoints.begin(); itr != particlePoints.end(); itr++){
        itr->x = ofRandom(-radius, radius);
        itr->y = ofRandom(-radius, radius);
        itr->z = ofRandom(-radius, radius);
    
    }
    
}







