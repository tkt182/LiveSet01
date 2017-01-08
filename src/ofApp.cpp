#include "ofApp.h"
#include "Scenes.h"
#include "Context.h"


void ofApp::switchScene(int &temp){
    if(temp == 0) SM.changeScene<Scene0>();
    if(temp == 1) SM.changeScene<Scene1>();
    
}


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0);

    
    init_context();
    $Context(KeyboardControl)->setup();
    
    SM.addScene<Scene0>();
    SM.addScene<Scene1>();
    
    SM.changeScene("Scene0");
    
    finalFbo.allocate(ofGetWidth(), ofGetHeight());
    
}

//--------------------------------------------------------------
void ofApp::update(){
    SM.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    finalFbo.begin();
    ofClear(0, 0, 0, 255);
    SM.draw();
    finalFbo.end();
    
    finalFbo.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == '1') SM.changeScene<Scene0>();
    if (key == '2') SM.changeScene<Scene1>();
    
    $Context(KeyboardControl)->setPressedKey(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    $Context(KeyboardControl)->setPressedKey(0);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
