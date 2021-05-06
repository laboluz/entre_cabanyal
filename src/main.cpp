#include "ofMain.h"
#include "ofApp.h"

#include "ofAppGLFWWindow.h"

#include "config.h"

//========================================================================
int main( ){

    ofGLFWWindowSettings settings;
    settings.setGLVersion(2,1);
    settings.stencilBits = 0;
    settings.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    settings.setPosition(ofVec2f(0,0));
    settings.resizable = false;
    settings.decorated = false;
    settings.windowMode = OF_WINDOW;

    // Entre cabanyal main window ( double screen )
    shared_ptr<ofAppGLFWWindow> ECWindow = dynamic_pointer_cast<ofAppGLFWWindow>(ofCreateWindow(settings));
    shared_ptr<ofApp> ecApp(new ofApp);

    ofRunApp(ECWindow, ecApp);
    ofRunMainLoop();

    // done
    return EXIT_SUCCESS;

}
