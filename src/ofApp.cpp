#include "ofApp.h"
vector <curve> curves;
ofFbo fbo;
float x,y,z;

curve::curve(){
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);
    
    p0 = ofPoint(ofRandom(10,ofGetWidth()),ofRandom(10,ofGetWidth()));
    p1 = ofPoint(ofRandom(10,ofGetHeight()),ofRandom(10,ofGetHeight()));
    sTime = ofGetElapsedTimef();
    t = ofPoint(ofGetWidth()/2,ofGetHeight()/2,0);
    
    sTime = ofGetElapsedTimef();
    
    
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();
    
    color.set(ofRandom(255), ofRandom(255), ofRandom(255));
}
float rX = 0;
float rY = 0;
float rZ = 0;
float a = ofRandom(0,5);

void curve::setup(){


}
void curve::update(){
    float time = sTime * a + ofGetElapsedTimef();
    rX = ofSignedNoise(time * 0.1) * 360.0;
    rY = ofSignedNoise(time * 0.15) * 360.0;
    rZ = ofSignedNoise(time * 0.2) * 360.0;
    
    dScale =(1-ofNoise(time * 0.2));
    dScale1 =(1-ofNoise(time * 0.5));
    dScale2 =(1-ofNoise(time * 0.3));
    
    x = ofSignedNoise(time * 0.2) *ofRandom(5,10);
    y = ofSignedNoise(time * 0.4) * ofRandom(5,10);
    z = ofSignedNoise(time * 0.6) *ofRandom(5,10);
    

    t += ofPoint(x,y,z);

//    if (x < 0|| x > ofGetWidth() ) {
//        x = 30;
//        color.set(255);
//        
//    }
//    
//    if (y < 0|| y> ofGetHeight() ) {
//        y = 80;
//        color.set(ofRandom(120), ofRandom(252), ofRandom(100,255));
//        
//    }

    
//    float x = ofMap(ofSignedNoise(time * 0.2), -20, 20, 0, ofGetWidth());
//    float y = ofMap(ofSignedNoise(time * 0.4), -20, 20, 0, ofGetHeight());
//    float z = ofMap(ofSignedNoise(time * 0.6), -20, 20, -800, 800);
    
//    float x = ofSignedNoise(time * 0.2)*ofRandom(5,10);
//    float y = ofSignedNoise(time * 0.4)*ofRandom(5,10);
//    float z  = ofSignedNoise(time * 0.6)*ofRandom(5,10);


    
  
}
void curve::update2(){
    float time = sTime * a + ofGetElapsedTimef();
    rX = ofSignedNoise(time * 0.3) * 180.0;
    rY = ofSignedNoise(time * 0.4) * 180.0;
    rZ = ofSignedNoise(time * 0.1) * 180.0;
    
    dScale =(1-ofNoise(time * 0.2));
    dScale1 =(1-ofNoise(time * 0.2));
    dScale2 =(1-ofNoise(time * 0.2));
    
    x = ofSignedNoise(time * 0.2) *ofRandom(1,5);
    y = ofSignedNoise(time * 0.4) * ofRandom(1,5);
    z = ofSignedNoise(time * 0.6) *ofRandom(1,5);
    
    
    t += ofPoint(x,y,z);
    
    //    if (x < 0|| x > ofGetWidth() ) {
    //        x = 30;
    //        color.set(255);
    //
    //    }
    //
    //    if (y < 0|| y> ofGetHeight() ) {
    //        y = 80;
    //        color.set(ofRandom(120), ofRandom(252), ofRandom(100,255));
    //
    //    }
    
    
    //    float x = ofMap(ofSignedNoise(time * 0.2), -20, 20, 0, ofGetWidth());
    //    float y = ofMap(ofSignedNoise(time * 0.4), -20, 20, 0, ofGetHeight());
    //    float z = ofMap(ofSignedNoise(time * 0.6), -20, 20, -800, 800);
    
    //    float x = ofSignedNoise(time * 0.2)*ofRandom(5,10);
    //    float y = ofSignedNoise(time * 0.4)*ofRandom(5,10);
    //    float z  = ofSignedNoise(time * 0.6)*ofRandom(5,10);
    
    
    
    
}

void curve::draw() {
    fbo.begin();
    ofPushStyle();
    ofSetColor(0,0,0,1);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    ofPopStyle();
    
    ofPushMatrix();
    ofTranslate(t.x,t.y,t.z);
    ofScale(1,1,1);
    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
    
    ofSetColor(color);
    ofDrawLine(p0,p1);
    ofPopMatrix();
    
    fbo.end();

    fbo.draw(0,0);
}

void curve::draw2(){
    fbo.begin();
    ofPushStyle();
    ofSetColor(0,0,0,10);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    ofPopStyle();
    
    ofPushMatrix();
    ofTranslate(t.x,t.y,t.z);
    ofScale(dScale, dScale1, dScale2);
    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
    
    ofSetColor(color);
    ofDrawCircle(p0,ofRandom(10,40));
    ofPopMatrix();
    
    fbo.end();
    
    fbo.draw(0,0);


}

//

circle::circle(){
    
    p0 = ofPoint(100, -10);
    sTime = ofGetElapsedTimef();
    t = ofPoint(0, 0, 0);
}

void circle::update(){
    float time = ofGetElapsedTimef()/2;
    
    rX = ofSignedNoise(time * 0.3) * 180.0;
    rY = ofSignedNoise(time * 0.3) * 180.0;
    rZ = ofSignedNoise(time * 0.3) * 180.0;
    

    
    float x = ofMap(ofSignedNoise(time * 0.2) , -1, 1, 0, ofGetWidth());
    float y = ofMap(ofSignedNoise(time * 0.2) , -1, 1, 0, ofGetHeight());
    float z = ofMap(ofSignedNoise(time * 0.2) , -1, 1, -800, 800);
    

    
    t = ofPoint(x, y, z);
    
}

void circle::draw() {

    
    ofPushMatrix();
    ofTranslate(t.x,t.y,t.z);
    
    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
    
    ofPushStyle();
    ofSetColor(80, 200, 120);
    ofDrawCircle(p0, 40);
    ofPopStyle();
    ofPopMatrix();
}




  circle myCircle;

void ofApp::add(ofPoint l){
   for(int i =0; i < 5; i++){
    curve myCurve;
    myCurve.t = l;
    curves.push_back(myCurve);
        }
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0, 0, 0);
//    for(int i =0; i < 5; i++){
//        curve myCurve;
//        myCurve.setup();
//        curves.push_back(myCurve);
//    }
//
    add(ofPoint(x, y));

}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i =0; i < 5; i++) {
        curves[i].update();
        
        if(curves[i].t.x <0 || curves[i].t.x >ofGetWidth()||curves[i].t.y<0 ||curves[i].t.y>ofGetHeight())
        {
           curves.erase(curves.begin()+i);
           curve myCurve;
           myCurve.setup();
           myCurve.t= ofPoint(ofRandom(ofGetWindowWidth()), ofRandom(ofGetHeight()),0);
           curves.push_back(myCurve);
            color.set(ofRandom(100,200), ofRandom(80,200), ofRandom(100,200));
            
        }
        


        
    }
    for (int i =0; i < 2; i++) {
        curves[i].update2();
        
        if(curves[i].t.x <0 || curves[i].t.x >ofGetWidth()||curves[i].t.y<0 ||curves[i].t.y>ofGetHeight())
        {
            curves.erase(curves.begin()+i);
            curve myCurve;
            myCurve.setup();
            myCurve.t= ofPoint(ofRandom(ofGetWindowWidth()), ofRandom(ofGetHeight()),0);
            curves.push_back(myCurve);
            color.set(ofRandom(100,200), ofRandom(80,200), ofRandom(100,200));
            
        }
        
        
        
        
    }

    
    myCircle.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0; i < 5; i++) {
        curves[i].draw();
    
    }
    
    for (int i = 0; i < 3; i++) {
        curves[i].draw2();
        
    }


    myCircle.draw();
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
