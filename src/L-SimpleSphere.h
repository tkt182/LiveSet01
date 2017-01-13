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
    
    //RaiseParticles particles;
    deque<RaiseParticles> parts;
    bool pressFlag = false;
    
    
    void setup(){
        $Context(RollCam)->setup();
        RaiseParticles *particle = new RaiseParticles();
        parts.push_back(*particle);
    }
    
    void update(){
        int i = 0;
        setGLParam();
        keyEvent();
        $Context(RollCam)->update();
        //particles.update();
        deque<RaiseParticles>::iterator itr = parts.begin();
        for(itr; itr != parts.end(); itr++){
            cout << "ID : " << i << endl;
            itr->update();
            i++;
        }
        //parts.end()->update();
        
    }
    
    void draw(){
        //cout << "Scene0: " << endl;
        ofBackground(0);
        $Context(RollCam)->begin();
        ofSetColor(255, 0, 255, 255);
        //particles.draw();
        deque<RaiseParticles>::iterator itr = parts.begin();
        for(itr; itr != parts.end(); itr++){
            itr->draw();
        }
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
            
            deque<RaiseParticles>::iterator itr = parts.begin();
            if(parts.size() == 1){
                if(itr->getFinishMove()){
                    RaiseParticles *particle = new RaiseParticles();
                    parts.push_back(*particle);
                    itr++;
                    itr->setCurrentTime();
                }else{
                    itr->setCurrentTime();
                }
            }else if(parts.size() == 2){
                //parts.pop_front();
                //itr = parts.begin();
                itr = parts.begin();
                itr++;

                if(itr->getFinishMove()){
                    parts.pop_front();
                    itr = parts.begin();
                    RaiseParticles *particle = new RaiseParticles();
                    parts.push_back(*particle);
                    itr++;
                    itr->setCurrentTime();
                }
            }
            
        }
        if (key == 'z') {
            $Context(RollCam)->setRandomPos();
        }
    }
    
};


#endif /* L_SimpleSphere_h */
