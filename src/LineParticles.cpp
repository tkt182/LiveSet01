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
    circleResolution = 30;
    slides = 30;
    radius = 100;
    particleNum = circleResolution*circleResolution;
    morphTargetId = SPHERE;
    
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
            
        }
    }
    
    // Box
    // 0 : front
    // 1 : top
    // 2 : right
    // 3 : left
    // 4 : bottom
    // 5 : back
    for(int i = 0; i < 6; i++){
        float x, y, z;
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 15; k++){
                // front
                if(i == 0){
                    z = radius / 2.;
                    x = k / 15.0 * radius - radius / 2.;
                    y = j / 10. * radius - radius / 2.;
                }
                if(i == 1){
                    y = radius / 2.;
                    x = k / 15.0 * radius - radius / 2.;
                    z = j / 10.0 * radius - radius / 2.;
                }
                if(i == 2){
                    x = radius / 2.;
                    z = k / 15.0 * radius - radius / 2.;
                    y = j / 10.0 * radius - radius / 2.;
                }
                if(i == 3){
                    x = -radius / 2.;
                    z = k / 15.0 * radius - radius / 2.;
                    y = j / 10.0 * radius - radius / 2.;
                }
                if(i == 4){
                    y = -radius / 2.;
                    x = k / 15.0 * radius - radius / 2.;
                    z = j / 10.0 * radius - radius / 2.;
                }
                if(i == 5){
                    z = -radius / 2.;
                    x = k / 15.0 * radius - radius / 2.;
                    y = j / 10. * radius - radius / 2.;
                }
            
                boxPoints.push_back(ofVec3f(x,y,z));
            }
            
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
    //boxGeom.setMode(OF_PRIMITIVE_POINTS);

    morphTarget = spherePoints;
}

LineParticles::~LineParticles(){
}

void LineParticles::update(){

    float morphingSpeed = 0.01;
    float minDistance   = 15.0;
    int vertexIndex     = 0;

    linePoints.clear();
    linePointColors.clear();
    
    for(int i = 0; i < particleNum; i++){
        
        tPData particleData = particlesData[i];
        ofVec3f currentPos  = particlePoints[i];
        
        //particlePoints[i].x = currentPos.x*(1. - morphingSpeed)+spherePoints[i].x*morphingSpeed;
        //particlePoints[i].y = currentPos.y*(1. - morphingSpeed)+spherePoints[i].y*morphingSpeed;
        //particlePoints[i].z = currentPos.z*(1. - morphingSpeed)+spherePoints[i].z*morphingSpeed;
        //particlePoints[i].x = currentPos.x*(1. - morphingSpeed)+boxPoints[i].x*morphingSpeed;
        //particlePoints[i].y = currentPos.y*(1. - morphingSpeed)+boxPoints[i].y*morphingSpeed;
        //particlePoints[i].z = currentPos.z*(1. - morphingSpeed)+boxPoints[i].z*morphingSpeed;
        particlePoints[i].x = currentPos.x*(1. - morphingSpeed)+morphTarget[i].x*morphingSpeed;
        particlePoints[i].y = currentPos.y*(1. - morphingSpeed)+morphTarget[i].y*morphingSpeed;
        particlePoints[i].z = currentPos.z*(1. - morphingSpeed)+morphTarget[i].z*morphingSpeed;
        
       
        for(int j = i + 1; j < particleNum; j++){
            
            if(particleData.numConnections >= 3) continue;
            
            float dx = particlePoints[i].x - particlePoints[j].x;
            float dy = particlePoints[i].y - particlePoints[j].y;
            float dz = particlePoints[i].z - particlePoints[j].z;
            
            float dist = sqrt(dx*dx + dy*dy + dz*dz);
            
            float alpha = 1.0;
            
            if(dist < minDistance){
                particleData.numConnections++;
                linePoints.push_back(particlePoints[i]);
                linePoints.push_back(particlePoints[j]);
            
                alpha = 1.0 - dist / minDistance;
                
                ofFloatColor color = ofFloatColor(1.0, 1.0, 1.0, alpha);
                linePointColors.push_back(color);
                linePointColors.push_back(color);
                
            }
            
        }
        
    }
    
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
    
    vector<ofFloatColor>::iterator itrC;
    for(itrC = linePointColors.begin(); itrC != linePointColors.end(); itrC++){
        renderedLineGeom.addColor(*(itrC));
    }
    
    vector<ofVec3f>::iterator itrB;
    for(itrB = boxPoints.begin(); itrB != boxPoints.end(); itrB++){
        boxGeom.addVertex(*(itrB));
    }
    
    renderedGeom.draw();
    renderedLineGeom.draw();
    //boxGeom.draw();
}


void LineParticles::resetParticlePosition(){
    
    vector<ofVec3f>::iterator itr;
    
    for(itr = particlePoints.begin(); itr != particlePoints.end(); itr++){
        itr->x = ofRandom(-radius, radius);
        itr->y = ofRandom(-radius, radius);
        itr->z = ofRandom(-radius, radius);
    
    }
    
}


void LineParticles::changeMorphTarget(){

    if(morphTargetId == SPHERE){
        morphTarget   = boxPoints;
        morphTargetId = BOX;
    }else if(morphTargetId == BOX){
        morphTarget   = spherePoints;
        morphTargetId = SPHERE;
    }

}




