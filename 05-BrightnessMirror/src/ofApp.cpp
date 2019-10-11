#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    grabber.setup(640, 480);
    
    grabberPix.allocate(grabber.getWidth(), grabber.getHeight(), OF_PIXELS_RGB);
    texture.allocate(grabber.getWidth(), grabber.getHeight(), GL_RGB);
    
}

//--------------------------------------------------------------
void ofApp::update()
{
    grabber.update();
    
    // do you have a new fresh frame
    if (grabber.isFrameNew()) //yes?
    {
        //get the pixels from the camera
        grabberPix = grabber.getPixels();
        for (int x = 0; x < grabberPix.getWidth(); x++)
        {
            for (int y = 0; y < grabberPix.getHeight(); y++)
            {
                // and now we can do something!
                
              
            }
        }
        
    }
    
    texture.loadData(grabberPix);
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(0);
    // texture.draw(0, 0);
    squareSize = ofClamp(ofMap(ofGetMouseX(), 0, ofGetWidth(), 1, 40), 1, 40);
    for (int x = 0; x < grabberPix.getWidth(); x+=squareSize)
    {
        for (int y = 0; y < grabberPix.getHeight(); y+=squareSize)
        {
            ofColor currColor = grabberPix.getColor(x, y);
            float brightness = currColor.getBrightness();
            ofSetColor(currColor);
            ofPushMatrix();
                ofTranslate(x, y);
                ofDrawRectangle(0, 0, brightness, brightness);
            ofPopMatrix();
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
