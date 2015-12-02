#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowPosition( 2881, 0 );
    ofSetWindowShape(1920,1080);
    ofToggleFullscreen();
    ofSetFrameRate(60);
    ofBackground(0);
    // FFTのサンプル数(2の累乗)を指定して初期化
    fft.setup(pow(2.0, 10.0));
    // GUI
    gui.setup();
    gui.add(saturation.setup("Saturation", 0, 0, 0));
    gui.add(alpha.setup("Alpha", 127, 0, 255));
    gui.add(radiusMax.setup("Radius Max", 0, 0, 200));
    gui.loadFromFile("settings.xml");
    
    pressed = false;
    fade = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    fft.update(); // FFT更新
    
    if (fade <= 255) {
        fade += 0.1;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    // float型の配列にFFT結果を格納
    vector<float> buffer;
    buffer = fft.getBins();
    
    // グラフに描画
    ofPushMatrix();
    
    ofTranslate(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    
    ofSetLineWidth(ofGetWidth() / float(buffer.size()) / 2.0);
    
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    ofSetCircleResolution(64);
    
    
    for (int i = 0; i < buffer.size(); i++) {
        // 色を設定
        float hue = ofMap(i, 0, buffer.size(), 0, 160);
        float br = ofMap(buffer[i], 0, 1, 0, 255);
        float radius = ofMap(buffer[i], 0, 1, 0, radiusMax/12);
        ofColor col;
        col.setHsb(0, 0, br, fade);
        ofSetColor(col);
        // 右
        float rx = ofMap(i, 0, buffer.size(), 1000, ofGetWidth() / 2.0);
        ofCircle(rx, 0, ofRandom(radius));
        // 左
        float lx = ofMap(i, 0, buffer.size(), 0, -ofGetWidth() / 2.0);
        ofCircle(lx, 0, ofRandom(radius));
    }
    ofPopMatrix();
    gui.draw();
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
    pressed = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    pressed = false;
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
