#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    void add (ofPoint);
    ofColor color;
 
};

class curve{
    
public:
    curve();
    void setup();
    void update();
    void update2();
    void draw();
    void draw2();

    ofPoint p0,p1,p2,p3,t;
    
private:
    float sTime;
    float fallSpeed,dScale,dScale1,dScale2;
    float rX;
    float rY;
    float rZ;
    ofColor color;
    
};


class circle{
    
public:
    circle();
    void update();
    void draw();

    ofPoint p0,p1,t;
    
private:
    float sTime;
    float sWeight;
    float fallSpeed;
    float fallWiggle;
    float dScale;
    float rX;
    float rY;
    float rZ;
    
};
