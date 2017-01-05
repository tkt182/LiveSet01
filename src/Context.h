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


void init_context(){
    ofxGlobalContext::Manager::defaultManager().createContext<KeyboardControl>();
}


#endif /* Context_h */
