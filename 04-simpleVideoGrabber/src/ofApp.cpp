#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    grabber.setup(1280, 720);
    grabberPix.allocate(grabber.getWidth(), grabber.getHeight(), OF_PIXELS_RGB);
    flippedPix.allocate(grabber.getWidth(), grabber.getHeight(), OF_PIXELS_RGB);
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
                
                
                // flips the pixels by entering them into a new
                // pixel object in reverse order.
                ofColor targetColor = grabberPix.getColor(grabberPix.getWidth()-x-1, y);
                
                flippedPix.setColor(x, y, targetColor);              
            }
        }
    }
    
    texture.loadData(flippedPix);
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(0);
    texture.draw(0, 0);
    
//    // flipped using translate
//    ofPushMatrix();
//        ofTranslate(grabber.getWidth(), grabber.getHeight());
//        ofScale(-1, 1);
//        texture.draw(0, 0);
//    ofPopMatrix();
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
