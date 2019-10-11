#include "ofApp.h"

void ofApp::setup()
{
    myImage.load("bottle.jpg");
    myPixels.allocate(myImage.getWidth(), myImage.getHeight(), OF_PIXELS_RGB);
    myTexture.allocate(myPixels.getWidth(), myPixels.getHeight(), GL_RGB);
    
    myPixels = myImage.getPixels();
    
//    for(int y = 0; y < myImage.getHeight(); y++) {
//        for(int x = 0; x < myImage.getWidth(); x++) {
//            
//            ofColor currColor = myPixels.getColor(x, y);
//            float brightness = currColor.getBrightness();
//            
//            std::cout << brightness << std::endl;
//            
//            if(brightness > 220) {
//                myPixels.setColor(x, y, 0);
//            } else {
//                myPixels.setColor(x, y, currColor);
//            }
//            
//        }
//    }
    

    
}

void ofApp::draw()
{
    myTexture.loadData(myPixels);
    
    
    myTexture.draw(0, 0);
    
}

