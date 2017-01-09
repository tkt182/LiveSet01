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
        $Context(RollCam)->setup();
        cout << "LM0 setup" << endl;
        
    }
    
    void update(){
        setGLParam();
        keyEvent();
        $Context(RollCam)->update();
        particles.update();
    }
    
    void draw(){
        //cout << "Scene0: " << endl;
        ofBackground(0);
        $Context(RollCam)->begin();
        ofSetColor(255, 0, 255, 255);
        particles.draw();
        $Context(RollCam)->end();
    }

private:
    
    void setGLParam(){
        static GLfloat distance[] = { 0.0, 0.0, 1.0 };
        glPointParameterfv(GL_POINT_DISTANCE_ATTENUATION, distance);
        glPointSize(10000.0);
    }
    
    void keyEvent(){
        int key = $Context(KeyboardControl)->getPressedKey();
        if (key == 'a') {
            particles.setCurrentTime();
        }
        if (key == 'z') {
            $Context(RollCam)->setRandomPos();
        }
    }
    
};


#endif /* L_SimpleSphere_h */
