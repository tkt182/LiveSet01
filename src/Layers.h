//
//  Layers.h
//  SceneBase
//
//  Created by 高田 信一郎 on 2016/12/25.
//
//

#pragma once

#ifndef Layers_h
#define Layers_h



//#include "Layer0.h"
#include "L-SimpleSphere.h"
#include "L-Attraction.h"

ofxLayer::Manager LM0;
ofxLayer::Manager LM1;


void init_layers(){
    LM0.createLayer<SimpleSphere>(1);
}

void init_layers1(){
    LM1.createLayer<Attraction>(1);
}


#endif /* Layers_h */
