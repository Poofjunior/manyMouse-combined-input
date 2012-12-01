#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofVec2f center(ofGetWidth()/2, ofGetHeight()/2);
    initPosC.set(center);
    
    initPosL.set(center.x - 500, center.y);
    initPosR.set(center.x + 500, center.y);
    
    extMouseOne.set(initPosL);
    extMouseTwo.set(initPosR);
    
    pressIdOne = -1;
    pressIdTwo = -1;
    
    curPosL.set(initPosL);
    curPosR.set(initPosR);
    
    oldPosL.set(curPosL);
    oldPosR.set(curPosR);
}

//--------------------------------------------------------------
void testApp::update(){
    
    // calculating new position
    
    ofVec2f u = (curPosL-curPosR);
    ofVec2f v = (initPosL-initPosR);
    
    float uNor = sqrt(u.x * u.x + u.y * u.y);
    float vNor = sqrt(v.x * v.x + v.y * v.y);
    
    theta = acos(u.dot(v) / ( uNor * vNor ) );
    
    // otherwise after 90 degrees it gets turned around ;-)
    if (curPosL.y > curPosR.y) {
        theta = theta*-1;
    }
    
    // this matrix will turn things around our centerpoint
    float Matrix_2D[2][2];
    
    Matrix_2D[0][0] = cosf(theta);
    
    Matrix_2D[0][1] = -sinf(theta);
    
    Matrix_2D[1][0] = sinf(theta);
    
    Matrix_2D[1][1] = cosf(theta);
    
    ofVec2f lStep;
    lStep.x = (Matrix_2D[0][0] * (extMouseOne.x-oldPosL.x)) + (Matrix_2D[0][1] * (extMouseOne.y-oldPosL.y));
    lStep.y = (Matrix_2D[1][0] * (extMouseOne.x-oldPosL.x)) + (Matrix_2D[1][1] * (extMouseOne.y-oldPosL.y));
    
    ofVec2f rStep;
    rStep.x = (Matrix_2D[0][0] * (extMouseTwo.x-oldPosR.x)) + (Matrix_2D[0][1] * (extMouseTwo.y-oldPosR.y));
    rStep.y = (Matrix_2D[1][0] * (extMouseTwo.x-oldPosR.x)) + (Matrix_2D[1][1] * (extMouseTwo.y-oldPosR.y));
    
    // adding the change to our position vectors
    curPosL += lStep;
    curPosR += rStep;
    
    // setting the mouseinput we get for comparison during the next update
    oldPosL = extMouseOne;
    oldPosR = extMouseTwo;
}

//--------------------------------------------------------------
void testApp::draw(){
    ofFill();
    
    // draws circles for both mouses based on mouse position
    ofSetColor(255, 255, 255,10);
    ofCircle(extMouseOne.x, extMouseOne.y, 2);
    ofCircle(extMouseTwo.x, extMouseTwo.y, 2);
    
    
    // draws circles for both mouses based on Nick's caluclation
    ofSetColor(0, 250, 0);
    ofCircle(curPosL.x/15, curPosL.y/15, 20);
    
    ofSetColor(0, 0, 250);
    ofCircle(curPosR.x/15, curPosR.y/15, 20);
    
    ofSetColor(0,0,0);
    ofDrawBitmapString("theta: " + ofToString(ofRadToDeg(theta)), 20,20);
    ofDrawBitmapString("mouseOne x: " + ofToString(extMouseOne.x), 20,50);
    ofDrawBitmapString("mouseTwo x: " + ofToString(extMouseTwo.x), 20,80);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key) {
        case 'f':
            ofToggleFullscreen();
            break;
            
        default:
            break;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

// ofxManyMouse =========

//--------------------------------------------------------------
void testApp::mouseMoved(int device, int axis, int value){
    
    if(device == pressIdOne && axis == 0) {
        extMouseOne.x += value;
     }
    if(device == pressIdOne && axis == 1) {
        extMouseOne.y += value;
    }
    
    if(device == pressIdTwo && axis == 0) {
        extMouseTwo.x += value;
    }
    
    if(device == pressIdTwo && axis == 1) {
        extMouseTwo.y += value;
    }
    
}

//--------------------------------------------------------------
void testApp::mouseScroll(int device, int axis, int value){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int device, int button){
    printf("%s %i\n", getDeviceName(device).c_str(), device );
    
    if (pressIdOne == -1 && pressIdTwo != -1) {
        pressIdOne = device;
    }
    
    if (pressIdTwo == -1) {
        pressIdTwo = device;
    }
}

//--------------------------------------------------------------
void testApp::mouseReleased(int device, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseDisconnect(int device){
    
}

