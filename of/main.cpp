// copied and modified from of_v0.10.1_msys2_release
#include "ofMain.h"
#include "ofApp.h"
#include <stdio.h>

//========================================================================
int main( ){

//	ofGLWindowSettings settings;
//	settings.setGLVersion(3,2);
//	ofCreateWindow(settings);

	ofSetupOpenGL(1024, 768, OF_WINDOW);

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:

        /// test
        ofApp* appObj = new ofApp();
        appObj->image.load("test.jpg");
        //ofLoadImage(appObj->inputPixels, "test.jpg");
        //int w = (appObj->inputPixels).getWidth();
        //int h = (appObj->inputPixels).getHeight();
        //printf("w = %d , h = %d\n", w, h);

        ofRunApp(appObj);



        //ofImage temp;
        //temp.setFromPixels(appObj->inputPixels);
        //ofSaveImage(appObj->inputPixels, "output.jpg", OF_IMAGE_QUALITY_BEST);

        //ofRunApp(new ofApp());

}
