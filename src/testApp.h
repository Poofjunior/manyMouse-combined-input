#pragma once

#include "ofMain.h"
#include "ofxManyMouse.h"

class testApp : public ofBaseApp, public ofxManyMouse { 
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);
                
        void mouseMoved(int device, int axis, int value);
        void mouseScroll(int device, int axis, int value);
        void mousePressed(int device, int button);
        void mouseReleased(int device, int button);
        void mouseDisconnect(int device);
    
        ofVec2f extMouseOne;
        ofVec2f extMouseTwo;

        int pressIdOne;
        int pressIdTwo;
    
        float theta;
    
        ofVec2f oldPosL;
        ofVec2f oldPosR;
        
        ofVec2f curPosL;
        ofVec2f curPosR;
        
        ofVec2f initPosC;
        ofVec2f initPosL;
        ofVec2f initPosR;
};

