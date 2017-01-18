//
//  L-ParticleSystem.h
//  LiveSet01
//
//  Created by 高田 信一郎 on 2017/01/17.
//
//

#ifndef L_ParticleSystem_h
#define L_ParticleSystem_h

#include "ofxLayer.h"
#include "ParticleSystem.h"
#include "Context.h"

using namespace ofxLayer;
class ParticleSimulation : public ofxLayer::Layer {

public:

    OFX_LAYER_DEFINE_LAYER_CLASS(ParticleSimulation);
    
    ParticleSystem particles;
    
    void setup(){
        particles.setup();
    }
    
    void update(){
    }
    
    void draw(){
        ofBackground(0);
        
        $Context(RollCam)->begin();
        ofPushMatrix();
        {
            particles.draw();
        }
        $Context(RollCam)->end();
        
    }
    

};


#endif /* L_ParticleSystem_h */
