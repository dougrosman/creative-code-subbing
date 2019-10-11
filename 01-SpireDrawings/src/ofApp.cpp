#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    r = 0;
    rotation = .25;
    x = 0;
    
    ofBackground(255);
    ofSetColor(255, 255, 255);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofSetBackgroundAuto(false);
    
}

//--------------------------------------------------------------


void ofApp::draw(){
    
    float size = ofMap(ofGetMouseY(), 30, ofGetHeight()-30, 0, 900);
    float xRate = ofMap(ofGetMouseX(), 10, ofGetWidth()-10, .5, 10);
    
    ofPushMatrix();
        ofPushStyle();
            ofSetColor(0);
            ofNoFill();
            ofSetRectMode(OF_RECTMODE_CENTER);
    
            ofTranslate(x, ofGetHeight()/2);
            ofRotateDeg(r);
    
            ofDrawRectangle(0, 0, size, size);
        ofPopStyle();
    ofPopMatrix();
    
    x+=xRate;
    r+=rotation;
    
    if(x > ofGetWidth() + size)
    {
        reset();
    }
    
}

void ofApp::reset(){
    
    x = 0;
    r = 0;
    ofSetColor(255, 255, 255);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
}


void ofApp::keyPressed(int key){
 
    if(key == 'q')
    {
        rotation-=.25;
    }
    else if(key == 'w')
    {
        rotation+=.25;
    }
    
    if (key == 'r')
    {
        reset();
    }
}
