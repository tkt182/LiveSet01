#include "RaiseParticles.h"

RaiseParticles::RaiseParticles(){
    
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
            -sheight,
            ofRandom(-sdepth, sdepth)
        );
    
        positions.push_back(pos);
        billboards.addVertex(ofVec3f(positions[i].x, positions[i].y, positions[i].z));

        numParticles++;
    }
    
    // Easing
    //now      = -10000.f;
    initTime = 0.f;
    //initTime = ofGetElapsedTimef();
    initTime = 10000.f;
    endPosition = sheight;
    isMove = false;
    finishMove = false;
    

}

RaiseParticles::~RaiseParticles(){
    
}

void RaiseParticles::update(){
    
    float duration = 2.f;
    float endTime = initTime + duration;
    float now = ofGetElapsedTimef();
    float tmpY = sheight;
    
    for(int i = 0; i < positions.size(); i++){
        ofVec3f pos = positions[i];
        positions[i].y = ofxeasing::map_clamp(now, initTime, endTime, -sheight, endPosition, &ofxeasing::linear::easeIn);
        //positions[i].y = ofxeasing::map_clamp(now, initTime, endTime, 0, endPosition, &ofxeasing::linear::easeIn);

        if(positions[i].y < tmpY){
            tmpY = positions[i].y;
        }
        
        billboards.getVertices()[i].set(pos);
    }
    
    if(tmpY < sheight && initTime < 10000){
        isMove = true;
    }else{
        isMove = false;
    }
    
    if(tmpY >= sheight){
        finishMove = true;
    }
    

}

void RaiseParticles::draw(){
    billboards.draw();
}

void RaiseParticles::setCurrentTime(){
    //now      = ofGetElapsedTimef();
    initTime = ofGetElapsedTimef();
}

bool RaiseParticles::getMoveStatus(){
    return isMove;
}

bool RaiseParticles::getFinishMove(){
    cout << "finishMove : " << finishMove << endl;
    return finishMove;
}
