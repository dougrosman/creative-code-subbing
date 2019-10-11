#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
    
    void setup();
    void draw();
    void keyPressed(int key);
    
    void reset();

    float r;
    float rotation;
    float x;  
};
