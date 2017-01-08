//
//  L-SimpleSphere.h
//  SceneBase
//
//  Created by 高田 信一郎 on 2016/12/29.
//
//

#ifndef L_SimpleSphere_h
#define L_SimpleSphere_h

#include "ofxLayer.h"
#include "RaiseParticles.h"
#include "Context.h"

using namespace ofxLayer;
class SimpleSphere : public ofxLayer::Layer {
    
public:
    
    OFX_LAYER_DEFINE_LAYER_CLASS(SimpleSphere);
    
    RaiseParticles particles;
    
    void setup(){
        cout << "LM0 setup" << endl;
        
    }
    
    void update(){
        cout << "LM0 update" << endl;
        particles.update();
    }
    
    void draw(){
        //cout << "Scene0: " << endl;
        ofBackground(0);
        ofSetColor(255, 0, 255, 255);
        particles.draw();
    }
    
};


#endif /* L_SimpleSphere_h */
