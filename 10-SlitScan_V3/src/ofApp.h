#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
    
    
    ofVideoGrabber grabber; // The camera we'll use.
    
    ofPixels pixels; // Collect slits from the camera and accumulate them side by side in pixels.
    
    float liveFeedWidth = 200; // set where the slit scan begins
		
};
