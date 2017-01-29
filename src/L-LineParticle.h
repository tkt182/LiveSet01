//
//  L-LineParticle.h
//  LiveSet01
//
//  Created by 高田 信一郎 on 2017/01/25.
//
//

#ifndef L_LineParticle_h
#define L_LineParticle_h


#include "ofXLayer.h"
#include "Context.h"
#include "LineParticles.h"

using namespace ofxLayer;
class LineParticle : public ofxLayer::Layer {
    
public:
    
    OFX_LAYER_DEFINE_LAYER_CLASS(LineParticle);
    
    LineParticles lineParticles;
    
    void setup(){
        $Context(RollCam)->setup();
        //LineParticles lineParticles;
        
    }
    
    void update(){
        setGLParam();
        keyEvent();
        $Context(RollCam)->update();
        lineParticles.update();
    }
    
    void draw(){
        ofBackground(0);
        $Context(RollCam)->begin();
        ofSetColor(255, 255, 255, 255);
        
        ofPushMatrix();
        {
            lineParticles.draw();
        }
        ofPopMatrix();
        $Context(RollCam)->end();
        
    }
    
private:
    
    void setGLParam(){
        static GLfloat distance[] = { 0.0, 0.0, 1.0 };
        glPointParameterfv(GL_POINT_DISTANCE_ATTENUATION, distance);
        glPointSize(5000.0);
    }
    
    void keyEvent(){
        int key = $Context(KeyboardControl)->getPressedKey();
        if (key == 'a') {
            lineParticles.resetParticlePosition();
        }
        
        if (key == 'z') {
            $Context(RollCam)->setRandomPos();
        }
        if (key == 'x') {
            $Context(RollCam)->setRandomScale();
        }
        if (key == 'c') {
            $Context(RollCam)->setDefaultScale();
        }
    }
    
};






#endif /* L_LineParticle_h */
