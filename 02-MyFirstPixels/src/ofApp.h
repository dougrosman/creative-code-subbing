#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void draw();
    
    ofPixels myPixels;
    
    
    ofTexture myTexture;
    
    
    // Textures are used for displaying an image on the screen.
    // ofImage automatically handles showing things on the screen.
    
    //ofImage => ofPixels + ofTexture
    //ofImage myImage;
		
};
