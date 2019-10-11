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
    
    int xPosition = 0; // The current x position of the slits in our pixels.
    
    int ySteps = 1;
    
    const float liveFeedWidth = 200;
    
		
};
