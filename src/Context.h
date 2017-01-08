//
//  Context.h
//  SceneBase
//
//  Created by 高田 信一郎 on 2016/12/18.
//
//

#ifndef Context_h
#define Context_h

#include "ofxGlobalContext.h"
#include "ofxRollingCam.h"

class KeyboardControl : public ofxGlobalContext::Context {

public:
    int pressedKey;
    
    void setup(){
        pressedKey = 0;
    }
    
    void setPressedKey(int key){
        pressedKey = key;
    }
    
    int getPressedKey(){
        return pressedKey;
    }

};

class RollCam : public ofxGlobalContext::Context {

public:
    ofxRollingCam rollCam;
    
    void setup(){
        rollCam.setup();
        rollCam.setCamSpeed(0.1);
    }
    
    void update(){
        rollCam.update();
    }
    
    void begin(){
        rollCam.begin();
    }
    
    void end(){
        rollCam.end();
    }
    
    void setRandomPos(){
        rollCam.setRandomPos(270);
    }
};


void init_context(){
    ofxGlobalContext::Manager::defaultManager().createContext<KeyboardControl>();
    ofxGlobalContext::Manager::defaultManager().createContext<RollCam>();
}


#endif /* Context_h */
