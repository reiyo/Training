// copied and modified from of_v0.10.1_msys2_release
#include "ofApp.h"
#include <stdio.h>

//--------------------------------------------------------------
void ofApp::setup(){
#ifdef TARGET_OPENGLES
    shaderBlurX.load("shadersES2/shaderBlurX");
    shaderBlurY.load("shadersES2/shaderBlurY");
#else
	if(ofIsGLProgrammableRenderer()){
		shaderBlurX.load("shadersGL3/shaderBlurX");
        shaderBlurY.load("shadersGL3/shaderBlurY");
	}else{
		shaderBlurX.load("shadersGL2/shaderBlurX");
        shaderBlurY.load("shadersGL2/shaderBlurY");
	}
#endif

    //image.load("img.jpg");
    
    fboBlurOnePass.allocate(image.getWidth(), image.getHeight());
    fboBlurTwoPass.allocate(image.getWidth(), image.getHeight());
    //outputImage.allocate(image.getWidth(), image.getHeight(), ofImageType::OF_IMAGE_COLOR_ALPHA);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    float blur = ofMap(mouseX, 0, ofGetWidth(), 0, 4, true);
    
    //----------------------------------------------------------
    fboBlurOnePass.begin();
    
    shaderBlurX.begin();
    shaderBlurX.setUniform1f("blurAmnt", blur);

    image.draw(0, 0);
    shaderBlurX.end();
    fboBlurOnePass.end();
    
    //----------------------------------------------------------
    fboBlurTwoPass.begin();
    
    shaderBlurY.begin();
    shaderBlurY.setUniform1f("blurAmnt", blur);
    
    fboBlurOnePass.draw(0, 0);
    shaderBlurY.end();
    fboBlurTwoPass.end();
    
    //----------------------------------------------------------
    ofSetColor(ofColor::white);
    fboBlurTwoPass.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //fboBlurOnePass.readToPixels(inputPixels); // added by me
    fboBlurTwoPass.readToPixels(inputPixels); // added by me

    outputImage.setFromPixels(inputPixels); // added by me
    outputImage.saveImage("screenshot.png"); // added by me
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
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
void ofApp::windowResized(int w, int h){
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
}
