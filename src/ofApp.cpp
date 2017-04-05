#include "ofApp.h"
vector <curve> curves;

curve::curve(){
}
float rX = 0;
float rY = 0;
float rZ = 0;
float a = ofRandom(0,0.3);

void curve::setup(){
    t= ofPoint(0,0,0);
    p0 = ofPoint(-10,10);
    p1 = ofPoint(-20,20);
    p2 = ofPoint(-50,400);
    p3 = ofPoint(-400,50);
    sTime = ofGetElapsedTimef();
//    fallSpeed = ofRandom(-3,1);
    color.set(ofRandom(255), ofRandom(255), ofRandom(255));
}
void curve::update(){
    float time = sTime * a;
    
    rX = ofSignedNoise(time * 0.2)* 200.0;
    rY = ofSignedNoise(time * 0.4)* 200.0;
    rZ = ofSignedNoise(time * 0.6)* 200.0;

    dScale  =1-ofNoise(time * 0.2);
    dScale1 =1-ofNoise(time * 0.4);
    dScale2 =1-ofNoise(time * 0.6);
    
//    for (int i = 0; i < 4; i++) {
//        if(i%2 == 0) {
//        p[i].x += ofSignedNoise(time * 0.2);
//                p[i].y += fallSpeed ;
//        }else {
//            
//            p[i].x += ofSignedNoise(time * 0.2)* ofRandom(0,3);
//            
//            p[i].y += fallSpeed;
//            
//        }
//    }


    
    float x = ofMap(ofSignedNoise(time * 0.2), -1, 1, 0, ofGetWidth());
    float y = ofMap(ofSignedNoise(time * 0.4), -1, 1, 0, ofGetHeight());
    float z = ofMap(ofSignedNoise(time * 0.6), -1, 1, -800, 800);

    t += ofPoint(x, y, z);
    
  
}

void curve::draw() {
    ofPushMatrix();
    ofTranslate(t.x,t.y,t.z);
    ofScale(dScale + 1, dScale1 + 1, dScale2 + 1);
    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
    ofSetColor(color);
    ofDrawLine(p0,p1);
   
    ofPopMatrix();
}
void curve::draw1() {
    ofPushMatrix();
    ofTranslate(t.x,t.y,t.z);
    ofScale(1, 1, 1);
    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
    ofSetColor(color);
    ofDrawLine(p2,p3);
    ofPopMatrix();
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
    

    
    float x = ofMap(ofSignedNoise(time * 0.2) , -20, 20, 0, ofGetWidth());
    float y = ofMap(ofSignedNoise(time * 0.2) , -20, 20, 0, ofGetHeight());
    float z = ofMap(ofSignedNoise(time * 0.2) , -20, 20, -800, 800);
    
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


    curve myCurve;
  circle myCircle;
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0, 0, 0);
    for(int i =0; i < 5; i++){
        myCurve.setup();
        curves.push_back(myCurve);
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i =0; i < 5; i++) {
        curves[i].update();
        
        if(curves[i].t.x<0||curves[i].t.x>ofGetWidth()||curves[i].t.y<0||curves[i].t.y>ofGetHeight()){
            curves.erase(curves.begin()+i);
           curve myCurve;
            myCurve.setup();
            myCurve.t= ofPoint(ofRandom(ofGetWindowWidth()), ofRandom(ofGetHeight()),0);
            curves.push_back(myCurve);
            
        }
        
    }

    
    myCircle.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < 5; i++) {
        curves[i].draw();
    
    }
//    for (int i = 0; i < 3; i++) {
//        curves[i].draw1();
//    }

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
