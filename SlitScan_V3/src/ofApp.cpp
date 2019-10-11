#include "ofApp.h"

// set up our sketch
void ofApp::setup() {
    //ofSetWindowShape(1280, 720); // set the window size
    grabber.setDeviceID(1);
    grabber.initGrabber(1920, 1080); // set the grabber size
    pixels.allocate(1920, 1080, OF_PIXELS_RGB); // allocate memory for our pixels
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
        
        // Choose a slit location. In this case we'll collect slits from the
        // column in the middle of the camera feed.
        int slitPositionX = grabber.getWidth() - liveFeedWidth;
        
        // Cycle through each pixel in the selected column and place that pixel
        // at a position x = xPosition and y = to the same position as the
        // oritinal.
        for (int y = 0; y < grabber.getHeight(); y++)
        {
            // Get the pixel as a color at x / y from the grabber.
            ofColor pixelFromGrabber = cameraPixels.getColor(slitPositionX, y);
            
            // Set that pixel color to the x / y position in the output pixels.
            for(int i = 0; i < ySteps; i++) {
                pixels.setColor(i, y, pixelFromGrabber);
//                pixels.setColor(1, y, pixelFromGrabber);
//                pixels.setColor(2, y, pixelFromGrabber);
//                pixels.setColor(3, y, pixelFromGrabber);
            }
            
        }
        
//        if(ofGetFrameNum() > 0) {
//            for(int x = pixels.getWidth()-1; x > 0; x--) {
//                for(int y = 0; y < pixels.getHeight(); y++) {
//                    //pixels.setColor(x+1, y, pixels.getColor(x-2, y));
//                    pixels.setColor(x, y, pixels.getColor(x-1, y));
//                }
//            }
//        }
    }
    if(ofGetFrameNum() > 0) {
        for(int x = pixels.getWidth()-1; x > 0; x--) {
            for(int y = 0; y < pixels.getHeight(); y++) {
                //pixels.setColor(x+1, y, pixels.getColor(x-2, y));
                pixels.setColor(x, y, pixels.getColor(x-ySteps, y));
            }
        }
    }
}


void ofApp::draw(){
    
    ofPushMatrix();
    
        ofTranslate(grabber.getWidth(), 0);
        ofScale(-1, 1);
        grabber.draw(0, 0);
    ofPopMatrix();
    // We must load our pixels into a texture to be displayed by the GPU.
    
    
    // Draw the pixels on the graphics card.
    
    // We must load our pixels into a texture to be displayed by the GPU.
    ofTexture texture;
    texture.loadData(pixels);
    
    // Draw the pixels on the graphics card.
    ofPushMatrix();
        //ofTranslate(-xPosition, 0);
        texture.draw(liveFeedWidth, 0);
    ofPopMatrix();
    
    
        
    ofDrawBitmapStringHighlight(ofToString(ofGetFrameRate()), 10, 10);
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

