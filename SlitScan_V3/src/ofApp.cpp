#include "ofApp.h"

// set up our sketch
void ofApp::setup() {
    grabber.setDeviceID(1);     // select the USB webcam
    grabber.initGrabber(1280, 720); // set the grabber size
    pixels.allocate(1280, 720, OF_PIXELS_RGB); // allocate memory for our pixels
}

// called every frame
void ofApp::update() {
    
    // Update our camera.
    grabber.update();
    
    // If the camera has a new frame to offer us ...
    if (grabber.isFrameNew())
    {
        // Get a reference (denoted by &) to the camera's pixels. Getting a
        // reference means that we won't have to make a copy of all of the
        // frame's pixels (since we only need one column anyway). This means our
        // program requires less processing power.
        //
        // const prevents us from accidentally modifying the cameras's pixels.
        const ofPixels& cameraPixels = grabber.getPixels();
        
        // Choose a slit location. In this case we'll collect slits from a
        // further left position on the screen
        int slitPositionX = grabber.getWidth() - liveFeedWidth;
        
        // Cycle through each pixel in the selected column and place that pixel
        // at a position x = 0 and y = the same position as the original.
        for (int y = 0; y < grabber.getHeight(); y++)
        {
            // Get the pixel as a color at x / y from the grabber.
            ofColor pixelFromGrabber = cameraPixels.getColor(slitPositionX, y);
            
            // Set that pixel color to the 0 / y position in the output pixels.
            pixels.setColor(0, y, pixelFromGrabber);
        }
    }
    
    // Once the pixels from the slit have been grabbed, stretch them accross
    // the screen by setting each column to be the colors of the column before it.
    // That way, the pixels will appear to travel accross the screen
    
    // loop through each column, starting at the furthest right and going in reverse
    for(int x = pixels.getWidth()-1; x > 0; x--) {
        
        // loop through each pixel in the column and set the pixels to the values of the
        // preceding columns
        for(int y = 0; y < pixels.getHeight(); y++) {
            pixels.setColor(x, y, pixels.getColor(x-1, y));
        }
    }
}

// draw it to the screen!
void ofApp::draw(){
    
    // we want to display a portion of the live webcam feed, so we know where the
    // slit-scan process begins.
    ofPushMatrix();
        // the webcam is mirrored, so we have to flip it using scale/translate
        ofTranslate(grabber.getWidth(), 0);
        ofScale(-1, 1);
        grabber.draw(0, 0);
    ofPopMatrix();
    
    // Draw the pixels on the graphics card.
    // We must load our pixels into a texture to be displayed by the GPU.
    ofTexture texture;
    texture.loadData(pixels);
    
    // Draw the pixels on the graphics card. The starting point depends on the value
    // of the liveFeedWidth.
    texture.draw(liveFeedWidth, 0);
   
    
    ofDrawBitmapStringHighlight(ofToString(ofGetFrameRate()), 10, 10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    // adjusts the starting position of the slit-scan column.
    if(key == '=') {
        liveFeedWidth+=2;
    } else if (key == '-') {
        liveFeedWidth-=2;
    }

}

