//
//  L-Attraction.h
//  SceneBase
//
//  Created by 高田 信一郎 on 2016/12/31.
//
//

#ifndef L_Attraction_h
#define L_Attraction_h

#include "ofxLayer.h"
#include "AttractionParticle.h"
#include "Context.h"

using namespace ofxLayer;
class Attraction : public ofxLayer::Layer {

public:
    
    OFX_LAYER_DEFINE_LAYER_CLASS(Attraction);
    
    vector<AttractionParticle> particles;
    ofVboMesh mesh;
    bool atraction;
    static const int NUM = 150000;
    
    ofVec3f center;
    int swidth, sheight, sdepth;
    
    float rotation;
    
    
    void setup(){

        $Context(RollCam)->setup();
        mesh.setMode(OF_PRIMITIVE_POINTS);
        //glPointSize(1.0);
        
        swidth = ofGetWidth();
        sheight = ofGetHeight();
        sdepth  = 480;
        
        for (int i = 0; i < NUM; i++) {
            AttractionParticle p;
            p.friction = 0.002;
            p.setup(ofVec3f(ofRandom(-swidth, swidth),
                            ofRandom(-sheight, sheight),
                            ofRandom(-sdepth, sdepth)),
                            ofVec3f(0, 0, 0));
            particles.push_back(p);
        }
        
        center.x = swidth / 2.0;
        center.y = sheight / 2.0;
        center.z = sdepth / 2.0;
        center.x = 0;
        center.y = 0;
        center.z = 0;
        
        rotation = 0.0;
        
    }
    
    void update(){
        
        setGLParam();
        keyEvent();
        $Context(RollCam)->update();
        
        for (int i = 0; i < particles.size(); i++){
            particles[i].resetForce();
            if (atraction) {
                particles[i].addAttractionForce(center.x, center.y, center.z, swidth, 0.1);
            }
            particles[i].update();
            particles[i].throughOfWalls();
        }
    }
    
    void draw(){
        mesh.clear();
        ofSetColor(255);
        
        ofPushMatrix();
        //ofRotateY(rotation);
        $Context(RollCam)->begin();
        for (int i = 0; i < particles.size(); i++) {
            mesh.addVertex(ofVec3f(particles[i].position.x, particles[i].position.y, particles[i].position.z));
        }
        mesh.draw();
        $Context(RollCam)->end();
        
        if (atraction) {
            ofSetColor(255, 0, 0);
        } else {
            ofSetColor(0, 255, 255);
        }
        
        //rotation += 0.5;
    }
    
private:
    
    void setGLParam(){
        static GLfloat distance[] = { 1.0, 0.0, 0.0 };
        glPointParameterfv(GL_POINT_DISTANCE_ATTENUATION, distance);
        glPointSize(1.0);
    }
    
    
    void keyEvent(){

        int key = $Context(KeyboardControl)->getPressedKey();
        if (key == 'a') {
            atraction = true;
        }
        if (key == 's') {
            atraction = false;
        }
        if (key == 'z') {
            $Context(RollCam)->setRandomPos();
        }
    }
};


#endif /* L_Attraction_h */
