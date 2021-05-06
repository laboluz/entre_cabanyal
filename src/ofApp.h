#pragma once

#include "ofMain.h"

#include "buttonobject.h"
#include "noticiaobject.h"

#include "config.h"

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

    // CUSTOM METHODS
    void drawBackground();
    void drawButtons();
    void drawVideos();
    void drawPrensa();

    void initVideos();
    void launchVideo(int vID);
    void closeVideos();


    // CUSTOM VARS
    ofDirectory             dirFiesta;
    ofDirectory             dirHuelga;
    ofDirectory             dirManifestacion;
    ofDirectory             dirPleno;
    ofDirectory             dirPortesObertes;

    vector<ofImage>         imagesFiesta;
    vector<ofImage>         imagesHuelga;
    vector<ofImage>         imagesManifestacion;
    vector<ofImage>         imagesPleno;
    vector<ofImage>         imagesPortesObertes;

    vector<noticiaObject*>  noticiasFiesta;
    vector<noticiaObject*>  noticiasHuelga;
    vector<noticiaObject*>  noticiasManifestacion;
    vector<noticiaObject*>  noticiasPleno;
    vector<noticiaObject*>  noticiasPortesObertes;

    buttonObject            butFiesta;
    buttonObject            butManifestacion;
    buttonObject            butPleno;
    buttonObject            butPortes;
    buttonObject            butHuelga;
    buttonObject            close;

    ofVideoPlayer           videoFiesta;
    ofVideoPlayer           videoHuelga;
    ofVideoPlayer           videoManifestacion;
    ofVideoPlayer           videoPleno;
    ofVideoPlayer           videoPortes;
    ofVideoPlayer           videoCreditos;

    ofTrueTypeFont          verdana14;
    ofTrueTypeFont          verdana24;
    string                  actualSelection;

    float                   vPosX, vPosY;
    float                   vWidth, vHeight;
    int                     actualVideo;
    bool                    isNoticiaOpen;
    int                     actualNoticia;
    bool                    isPlayingVideo;


    bool                    start;

    size_t                  creditsTimeout;
    size_t                  waitForCredits;

};
