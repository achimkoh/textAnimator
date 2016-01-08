#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    ofEnableAntiAliasing();

    // setup font
    fontsize = 320;
    font.load("mono.ttf", fontsize, true, false, true, 0.1);
    font.setLetterSpacing(1.03);
    
    // default settings
    counter = 0;
    prevTime = 0;
    interval = 500;
    backgroundWhite = true;
    scale = 0.5;
    
    // load text file into buffer and parse into lines (vector of strings)
    // text from http://bloom0101.org/?parution=to-our-friends
    buffer = ofBufferFromFile("letsdisappear.txt");
    for(auto line: buffer.getLines()){
        words.push_back(line);
    }
    buffer.clear();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // minimum interval (how fast this thing can go)
//    if (interval < 50) {
//        interval = 50;
//    }

    // increment the line counter, if elapsed time from previously registered time is greater than set interval
    if (ofGetElapsedTimeMillis() >= interval) {
        if (prevTime <= ofGetElapsedTimeMillis() - interval) {
            prevTime = ofGetElapsedTimeMillis();
            counter++;

            // if line is blank, skip it
            while (words[counter] == "") {
                counter++;
            }
            
            // reset counter when end is reached
            if (counter >= words.size()) counter = 0;
            
            // add some random to interval
            float weight = ofRandom(0,1);
            interval = 500 - (250 * weight);
            cout << interval << endl;

        }
    }

    // set font size so that each string fits to screen width in one line
    float w = font.stringWidth(words[counter]);
    scale = ofGetWidth()*0.97 / w;
    
    // if line is longer than x, split it into a new vector of strings and display each string

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // toggle color
    if (backgroundWhite) {
        ofSetBackgroundColor(255);
        ofSetColor(0);
    } else {
        ofSetBackgroundColor(0);
        ofSetColor(255);
    }
    
    // see method definition
    drawCross();

    // go to center of screen; draw strings
    // code modified from https://forum.openframeworks.cc/t/oftruetypefont-dynamic-sizing/14977/2 and https://forum.openframeworks.cc/t/oftruetypefont-issue/14928/2
    ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofScale(scale, scale, 1);
    
        string text = words[counter];
        float fontWidth = font.stringWidth(text);
        float fontHeight = font.stringHeight(text);
        font.drawStringAsShapes(text, -fontWidth/2, fontHeight/4);

        // draw counter
        string c = "line " + ofToString(counter);
        float counterWidth = font.stringWidth(c);
        ofSetColor(127);
        font.drawStringAsShapes(c, -counterWidth/2, -ofGetHeight());

    ofPopMatrix();
}

// draw a horizontal and a vertical line across the center of screen
void ofApp::drawCross() {
    ofDrawLine(0,ofGetHeight()/2,ofGetWidth(),ofGetHeight()/2);
    ofDrawLine(ofGetWidth()/2,0,ofGetWidth()/2,ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    // some controls
    if (key == 'b') backgroundWhite = !backgroundWhite;
//    if (key == OF_KEY_UP) {
//        interval += 10;
//        cout << interval << endl;
//    }
//    if (key == OF_KEY_DOWN) {
//        interval -= 10;
//        cout << interval << endl;
//    }
//    if (key == OF_KEY_RIGHT) scale *= 1.1;
//    if (key == OF_KEY_LEFT) scale *= 0.9;

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
