#include "ofApp.h"

void ofApp::setup()
{
    // 256 x 256, 3 channels
    myPixels.allocate(256, 256, 3);
    myTexture.allocate(myPixels.getWidth(), myPixels.getHeight(), GL_RGB);
    
    
    for (int x = 0; x < myPixels.getWidth(); x++)
    {
        for (int y = 0; y < myPixels.getHeight(); y++)
        {
            myPixels.setColor(x, y, ofColor::fromHsb(x, 255, 255));
        }
    }
    
    
}

void ofApp::draw()
{
    myTexture.loadData(myPixels);
    
    
    myTexture.draw(0, 0);
    
}

