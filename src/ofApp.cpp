#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetEscapeQuitsApp(false);
    ofSetVerticalSync(true);
    ofEnableAntiAliasing();

    // FONT
    ofTrueTypeFont::setGlobalDpi(72);
    verdana14.load("verdana.ttf", 14);
    verdana14.setLineHeight(18.0f);
    verdana14.setLetterSpacing(1.037);
    verdana24.load("verdana.ttf", 24);
    verdana24.setLineHeight(18.0f);
    verdana24.setLetterSpacing(1.037);
    actualSelection = "";

    // -------------------------------------------------- LOAD MEDIA

    // FIESTA
    dirFiesta.listDir("prensa/fiesta/");
    dirFiesta.sort();
    if( dirFiesta.size() ){
        imagesFiesta.assign(dirFiesta.size(), ofImage());
        noticiasFiesta.assign(dirFiesta.size(), new noticiaObject());
    }
    for(int i = 0; i < (int)dirFiesta.size(); i++){
        imagesFiesta[i].load(dirFiesta.getPath(i));
        noticiasFiesta[i] = new noticiaObject();
        noticiasFiesta[i]->init(dirFiesta.getPath(i));

        float posX = ofMap(noticiasFiesta[i]->year,1998,2002,120,PRIMARY_SCREEN_W-120,true);
        float posY = ofMap(noticiasFiesta[i]->md,101,1231,60,PRIMARY_SCREEN_H/9 * 7 -60,true);

        noticiasFiesta[i]->setup(posX,posY+30*(i+1),dirFiesta.getPath(i));
        noticiasFiesta[i]->set(noticiasFiesta[i]->posX,noticiasFiesta[i]->posY-20,100, 40);
        //printf("%s\n",dirFiesta.getPath(i).c_str());
    }

    // HUELGA
    dirHuelga.listDir("prensa/huelga/");
    dirHuelga.sort();
    if( dirHuelga.size() ){
        imagesHuelga.assign(dirHuelga.size(), ofImage());
        noticiasHuelga.assign(dirHuelga.size(), new noticiaObject());
    }
    for(int i = 0; i < (int)dirHuelga.size(); i++){
        imagesHuelga[i].load(dirHuelga.getPath(i));
        noticiasHuelga[i] = new noticiaObject();
        noticiasHuelga[i]->init(dirHuelga.getPath(i));

        float posX = ofMap(noticiasHuelga[i]->year,1998,2002,120,PRIMARY_SCREEN_W-120,true);
        float posY = ofMap(noticiasHuelga[i]->md,300,500,60,PRIMARY_SCREEN_H/9 * 7 -60,true);

        noticiasHuelga[i]->setup(posX,posY+ 40*(i+1) ,dirHuelga.getPath(i));
        noticiasHuelga[i]->set(noticiasHuelga[i]->posX,noticiasHuelga[i]->posY-20,100, 40);

        //printf("%s\n",dirHuelga.getPath(i).c_str());
    }

    // MANIFESTACION
    dirManifestacion.listDir("prensa/manifestacion/");
    dirManifestacion.sort();
    if( dirManifestacion.size() ){
        imagesManifestacion.assign(dirManifestacion.size(), ofImage());
        noticiasManifestacion.assign(dirManifestacion.size(), new noticiaObject());
    }
    for(int i = 0; i < (int)dirManifestacion.size(); i++){
        imagesManifestacion[i].load(dirManifestacion.getPath(i));
        noticiasManifestacion[i] = new noticiaObject();
        noticiasManifestacion[i]->init(dirManifestacion.getPath(i));

        float posX = ofMap(noticiasManifestacion[i]->year,1998,2002,120,PRIMARY_SCREEN_W-120,true);
        float posY = ofMap(noticiasManifestacion[i]->md,101,1231,60,PRIMARY_SCREEN_H/9 * 7 -60,true);

        noticiasManifestacion[i]->setup(posX,posY+30*(i+1),dirManifestacion.getPath(i));
        noticiasManifestacion[i]->set(noticiasManifestacion[i]->posX,noticiasManifestacion[i]->posY-20,100, 40);

        //printf("%s\n",dirManifestacion.getPath(i).c_str());
    }

    // PLENO
    dirPleno.listDir("prensa/pleno/");
    dirPleno.sort();
    if( dirPleno.size() ){
        imagesPleno.assign(dirPleno.size(), ofImage());
        noticiasPleno.assign(dirPleno.size(), new noticiaObject());
    }
    for(int i = 0; i < (int)dirPleno.size(); i++){
        imagesPleno[i].load(dirPleno.getPath(i));
        noticiasPleno[i] = new noticiaObject();
        noticiasPleno[i]->init(dirPleno.getPath(i));

        float posX = ofMap(noticiasPleno[i]->year,1998,2002,120,PRIMARY_SCREEN_W-120,true);
        float posY = ofMap(noticiasPleno[i]->md,101,1231,60,PRIMARY_SCREEN_H/9 * 7 -60,true);

        noticiasPleno[i]->setup(posX,posY+30*(i+1),dirPleno.getPath(i));
        noticiasPleno[i]->set(noticiasPleno[i]->posX,noticiasPleno[i]->posY-20,100, 40);

        //printf("%s\n",dirPleno.getPath(i).c_str());
    }

    // PORTESOBERTES
    dirPortesObertes.listDir("prensa/portes_obertes/");
    dirPortesObertes.sort();
    if( dirPortesObertes.size() ){
        imagesPortesObertes.assign(dirPortesObertes.size(), ofImage());
        noticiasPortesObertes.assign(dirPortesObertes.size(), new noticiaObject());
    }
    for(int i = 0; i < (int)dirPortesObertes.size(); i++){
        imagesPortesObertes[i].load(dirPortesObertes.getPath(i));
        noticiasPortesObertes[i] = new noticiaObject();
        noticiasPortesObertes[i]->init(dirPortesObertes.getPath(i));

        float posX = ofMap(noticiasPortesObertes[i]->year,1998,2002,120,PRIMARY_SCREEN_W-120,true);
        float posY = ofMap(noticiasPortesObertes[i]->md,501,1300,60,PRIMARY_SCREEN_H/9 * 7 -60,true);

        noticiasPortesObertes[i]->setup(posX,posY+20*(i+1),dirPortesObertes.getPath(i));
        noticiasPortesObertes[i]->set(noticiasPortesObertes[i]->posX,noticiasPortesObertes[i]->posY-20,100, 40);

        //printf("%s\n",dirPortesObertes.getPath(i).c_str());
    }

    // LOADING VIDEOS
    initVideos();

    actualVideo = 0;;
    isPlayingVideo = false;
    isNoticiaOpen = false;
    actualNoticia = 0;

    // -------------------------------------------------- LOAD GUI
    // INIT BUTTONS
    float delta = (PRIMARY_SCREEN_W-120-110)/5;
    float alignDelta = delta/5;
    float finalDelta = delta + alignDelta;
    float uiDivideH = PRIMARY_SCREEN_H/9 * 7.2;

    butManifestacion.setup(30+(finalDelta*0),uiDivideH,"images/manifaFrame.png","images/marco_on.png");
    butPortes.setup(30+(finalDelta*1),uiDivideH,"images/portesFrame.png","images/marco_on.png");
    butHuelga.setup(30+(finalDelta*2),uiDivideH,"images/huelgaFrame.png","images/marco_on.png");
    butPleno.setup(30+(finalDelta*3),uiDivideH,"images/plenoFrame.png","images/marco_on.png");
    butFiesta.setup(30+(finalDelta*4),uiDivideH,"images/fiestaFrame.png","images/marco_on.png");

    close.setup(0,0,"images/cerrar.jpg","images/cerrar.jpg");

    butManifestacion.set(30+(finalDelta*0),uiDivideH, 220, 220);
    butPortes.set(30+(finalDelta*1),uiDivideH, 220, 220);
    butHuelga.set(30+(finalDelta*2),uiDivideH, 220, 220);
    butPleno.set(30+(finalDelta*3),uiDivideH, 220, 220);
    butFiesta.set(30+(finalDelta*4),uiDivideH, 220, 220);

    close.set(0,0,close.normal.getWidth(), close.normal.getHeight());

    creditsTimeout = ofGetElapsedTimeMillis();
    waitForCredits = 1000*60*5; // 5 min.

    start = true;
}

//--------------------------------------------------------------
void ofApp::update(){
    if(start){
        start = false;
    }

    if(isPlayingVideo){
        if(actualVideo == 1 && videoFiesta.isPlaying()){
            videoFiesta.update();
        }else if(actualVideo == 2 && videoManifestacion.isPlaying()){
            videoManifestacion.update();
        }else if(actualVideo == 3 && videoPleno.isPlaying()){
            videoPleno.update();
        }else if(actualVideo == 4 && videoPortes.isPlaying()){
            videoPortes.update();
        }else if(actualVideo == 5 && videoHuelga.isPlaying()){
            videoHuelga.update();
        }else if(actualVideo == 6 && videoCreditos.isPlaying()){
            videoCreditos.update();
        }
    }

    // reset to credits if 5 min without activity
    if(ofGetElapsedTimeMillis() - creditsTimeout > waitForCredits){
        creditsTimeout = ofGetElapsedTimeMillis();
        closeVideos();
        butFiesta.isSelected = false;
        butManifestacion.isSelected = false;
        butPleno.isSelected = false;
        butPortes.isSelected = false;
        butHuelga.isSelected = false;
        isNoticiaOpen = false;
        actualNoticia = 0;
        launchVideo(6);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);

    drawBackground();
    drawButtons();
    if(butFiesta.isSelected || butManifestacion.isSelected || butPleno.isSelected || butPortes.isSelected || butHuelga.isSelected){
       drawPrensa();
    }

    drawVideos();

}

//--------------------------------------------------------------
void ofApp::drawBackground(){
    ofSetColor(160,160,160);

    float uiDivideH = PRIMARY_SCREEN_H/9 * 7.2;
    ofSetLineWidth(1.5);
    ofDrawLine(30,60,30,uiDivideH);
    ofDrawLine(30,uiDivideH,PRIMARY_SCREEN_W-30,uiDivideH);

    ofSetColor(80,80,80);
    ofSetLineWidth(1.2);
    float crossSpace = (PRIMARY_SCREEN_W-80)/30;
    int verticalCross = (int)((uiDivideH-60)/crossSpace);
    int crossDim = 8;
    for(int x=0;x<30;x++){
        for(int y=0;y<verticalCross;y++){
            ofDrawLine(60+(x*crossSpace),80+(y*crossSpace),60+(x*crossSpace),80+(y*crossSpace)+crossDim); // V
            ofDrawLine(60+(x*crossSpace)-(crossDim/2),80+(y*crossSpace)+(crossDim/2),60+(x*crossSpace)+(crossDim/2),80+(y*crossSpace)+(crossDim/2)); // H
        }
    }


    ofSetLineWidth(1);

    ofSetColor(100,100,100);
    verdana14.drawString("PRENSA", PRIMARY_SCREEN_W-110, 60);
    verdana14.drawString("VIDEOS", PRIMARY_SCREEN_W-110, uiDivideH - 10);

    ofSetColor(160,160,160);
    verdana24.drawString(actualSelection, 40, 60);

}

//--------------------------------------------------------------
void ofApp::drawButtons(){
    float delta = (PRIMARY_SCREEN_W-120-110)/5;
    float alignDelta = delta/5;
    float finalDelta = delta + alignDelta;
    float uiDivideH = PRIMARY_SCREEN_H/9 * 7.2;

    ofSetLineWidth(1);
    ofSetColor(255);

    if(butFiesta.isMousePressed()){
        butFiesta.isSelected = true;
        butManifestacion.isSelected = false;
        butPleno.isSelected = false;
        butPortes.isSelected = false;
        butHuelga.isSelected = false;
        isNoticiaOpen = false;
        actualNoticia = 0;
        launchVideo(1);
    }else if(butManifestacion.isMousePressed()){
        butFiesta.isSelected = false;
        butManifestacion.isSelected = true;
        butPleno.isSelected = false;
        butPortes.isSelected = false;
        butHuelga.isSelected = false;
        isNoticiaOpen = false;
        actualNoticia = 0;
        launchVideo(2);
    }else if(butPleno.isMousePressed()){
        butFiesta.isSelected = false;
        butManifestacion.isSelected = false;
        butPleno.isSelected = true;
        butPortes.isSelected = false;
        butHuelga.isSelected = false;
        isNoticiaOpen = false;
        actualNoticia = 0;
        launchVideo(3);
    }else if(butPortes.isMousePressed()){
        butFiesta.isSelected = false;
        butManifestacion.isSelected = false;
        butPleno.isSelected = false;
        butPortes.isSelected = true;
        butHuelga.isSelected = false;
        isNoticiaOpen = false;
        actualNoticia = 0;
        launchVideo(4);
    }else if(butHuelga.isMousePressed()){
        butFiesta.isSelected = false;
        butManifestacion.isSelected = false;
        butPleno.isSelected = false;
        butPortes.isSelected = false;
        butHuelga.isSelected = true;
        isNoticiaOpen = false;
        actualNoticia = 0;
        launchVideo(5);
    }

    // draw texts
    if(butFiesta.isSelected){
        ofSetColor(255,138,0);
    }else{
        ofSetColor(170,170,170);
    }
    verdana14.drawString("FIESTA", 130+(finalDelta*4),uiDivideH + 40);

    if(butManifestacion.isSelected){
        ofSetColor(255,138,0);
    }else{
        ofSetColor(170,170,170);
    }
    verdana14.drawString("MANIFESTACIÓN", 96+(finalDelta*0),uiDivideH + 40);

    if(butPortes.isSelected){
        ofSetColor(255,138,0);
    }else{
        ofSetColor(170,170,170);
    }
    verdana14.drawString("PORTES OBERTES", 94+(finalDelta*1),uiDivideH + 40);

    if(butHuelga.isSelected){
        ofSetColor(255,138,0);
    }else{
        ofSetColor(170,170,170);
    }
    verdana14.drawString("HUELGA DE HAMBRE", 84+(finalDelta*2),uiDivideH + 40);

    if(butPleno.isSelected){
        ofSetColor(255,138,0);
    }else{
        ofSetColor(170,170,170);
    }
    verdana14.drawString("PLENO", 136+(finalDelta*3),uiDivideH + 40);



    // draw buttons
    ofSetColor(255);
    butFiesta.draw();
    butManifestacion.draw();
    butPleno.draw();
    butPortes.draw();
    butHuelga.draw();

    ofSetLineWidth(1.4);
    ofSetColor(100,100,100);
    ofDrawLine(30,uiDivideH+45,PRIMARY_SCREEN_W-30,uiDivideH+45);
    ofDrawLine(30,uiDivideH+187,PRIMARY_SCREEN_W-30,uiDivideH+187);

    ofSetLineWidth(1);

}

//--------------------------------------------------------------
void ofApp::drawVideos(){
    ofSetColor(255);
    if(isPlayingVideo){
        if(actualVideo == 1){
            //ofDrawBitmapString("FIESTA",40,50);

            vWidth      = (videoFiesta.getWidth()*SECONDARY_SCREEN_H) / videoFiesta.getHeight();
            vHeight     = SECONDARY_SCREEN_H;
            vPosX       = PRIMARY_SCREEN_W + (SECONDARY_SCREEN_W-vWidth)/2.0f;
            vPosY       = 0;

            videoFiesta.draw(vPosX,vPosY,vWidth,vHeight);
        }else if(actualVideo == 2){
            //ofDrawBitmapString("HUELGA DE HAMBRE",40,50);

            vWidth      = (videoManifestacion.getWidth()*SECONDARY_SCREEN_H) / videoManifestacion.getHeight();
            vHeight     = SECONDARY_SCREEN_H;
            vPosX       = PRIMARY_SCREEN_W + (SECONDARY_SCREEN_W-vWidth)/2.0f;
            vPosY       = 0;

            videoManifestacion.draw(vPosX,vPosY,vWidth,vHeight);
        }else if(actualVideo == 3){
            //ofDrawBitmapString("MANIFESTACIÓN",40,50);

            vWidth      = (videoPleno.getWidth()*SECONDARY_SCREEN_H) / videoPleno.getHeight();
            vHeight     = SECONDARY_SCREEN_H;
            vPosX       = PRIMARY_SCREEN_W + (SECONDARY_SCREEN_W-vWidth)/2.0f;
            vPosY       = 0;

            videoPleno.draw(vPosX,vPosY,vWidth,vHeight);
        }else if(actualVideo == 4){
            //ofDrawBitmapString("PLENO",40,50);

            vWidth      = (videoPortes.getWidth()*SECONDARY_SCREEN_H) / videoPortes.getHeight();
            vHeight     = SECONDARY_SCREEN_H;
            vPosX       = PRIMARY_SCREEN_W + (SECONDARY_SCREEN_W-vWidth)/2.0f;
            vPosY       = 0;

            videoPortes.draw(vPosX,vPosY,vWidth,vHeight);
        }else if(actualVideo == 5){
            //ofDrawBitmapString("PORTES OBERTES",40,50);

            vWidth      = (videoHuelga.getWidth()*SECONDARY_SCREEN_H) / videoHuelga.getHeight();
            vHeight     = SECONDARY_SCREEN_H;
            vPosX       = PRIMARY_SCREEN_W + (SECONDARY_SCREEN_W-vWidth)/2.0f;
            vPosY       = 0;

            videoHuelga.draw(vPosX,vPosY,vWidth,vHeight);
        }else if(actualVideo == 6){
            //ofDrawBitmapString("",40,50);

            vWidth      = (videoCreditos.getWidth()*SECONDARY_SCREEN_H) / videoCreditos.getHeight();
            vHeight     = SECONDARY_SCREEN_H;
            vPosX       = PRIMARY_SCREEN_W + (SECONDARY_SCREEN_W-vWidth)/2.0f;
            vPosY       = 0;

            videoCreditos.draw(vPosX,vPosY,vWidth,vHeight);
        }
    }
}

//--------------------------------------------------------------
void ofApp::drawPrensa(){
    if(actualVideo == 1){
        for(int i=0;i<noticiasFiesta.size();i++){
            if(noticiasFiesta[i]->isSelected){
                isNoticiaOpen = true;
                actualNoticia = i;
                break;
            }
        }
        if(isNoticiaOpen){
            noticiasFiesta[actualNoticia]->draw();
            close.setup(PRIMARY_SCREEN_W/2 + noticiasFiesta[actualNoticia]->normal.getWidth()/2 + 10,90,"images/cerrar.jpg","images/cerrar.jpg");
            close.set(PRIMARY_SCREEN_W/2 + noticiasFiesta[actualNoticia]->normal.getWidth()/2 + 10,90,close.normal.getWidth(), close.normal.getHeight());
            close.draw();
            if(close.isMousePressed()){
                for(int i=0;i<noticiasFiesta.size();i++){
                    noticiasFiesta[i]->isSelected = false;
                }
                isNoticiaOpen = false;
                actualNoticia = 0;
            }
        }else{
            for(int i=0;i<noticiasFiesta.size();i++){
                noticiasFiesta[i]->draw();
            }
        }
    }else if(actualVideo == 2){
        for(int i=0;i<noticiasManifestacion.size();i++){
            if(noticiasManifestacion[i]->isSelected){
                isNoticiaOpen = true;
                actualNoticia = i;
                break;
            }
        }
        if(isNoticiaOpen){
            noticiasManifestacion[actualNoticia]->draw();
            close.setup(PRIMARY_SCREEN_W/2 + noticiasManifestacion[actualNoticia]->normal.getWidth()/2 + 10,90,"images/cerrar.jpg","images/cerrar.jpg");
            close.set(PRIMARY_SCREEN_W/2 + noticiasManifestacion[actualNoticia]->normal.getWidth()/2 + 10,90,close.normal.getWidth(), close.normal.getHeight());
            close.draw();
            if(close.isMousePressed()){
                for(int i=0;i<noticiasManifestacion.size();i++){
                    noticiasManifestacion[i]->isSelected = false;
                }
                isNoticiaOpen = false;
                actualNoticia = 0;
            }
        }else{
            for(int i=0;i<noticiasManifestacion.size();i++){
                noticiasManifestacion[i]->draw();
            }
        }

    }else if(actualVideo == 3){
        //actualSelection = "Pleno";
        for(int i=0;i<noticiasPleno.size();i++){
            if(noticiasPleno[i]->isSelected){
                isNoticiaOpen = true;
                actualNoticia = i;
                break;
            }
        }
        if(isNoticiaOpen){
            noticiasPleno[actualNoticia]->draw();
            close.setup(PRIMARY_SCREEN_W/2 + noticiasPleno[actualNoticia]->normal.getWidth()/2 + 10,90,"images/cerrar.jpg","images/cerrar.jpg");
            close.set(PRIMARY_SCREEN_W/2 + noticiasPleno[actualNoticia]->normal.getWidth()/2 + 10,90,close.normal.getWidth(), close.normal.getHeight());
            close.draw();
            if(close.isMousePressed()){
                for(int i=0;i<noticiasPleno.size();i++){
                    noticiasPleno[i]->isSelected = false;
                }
                isNoticiaOpen = false;
                actualNoticia = 0;
            }
        }else{
            for(int i=0;i<noticiasPleno.size();i++){
                noticiasPleno[i]->draw();
            }
        }

    }else if(actualVideo == 4){
        //actualSelection = "Portes Obertes";
        for(int i=0;i<noticiasPortesObertes.size();i++){
            if(noticiasPortesObertes[i]->isSelected){
                isNoticiaOpen = true;
                actualNoticia = i;
                break;
            }
        }
        if(isNoticiaOpen){
            noticiasPortesObertes[actualNoticia]->draw();
            close.setup(PRIMARY_SCREEN_W/2 + noticiasPortesObertes[actualNoticia]->normal.getWidth()/2 + 10,90,"images/cerrar.jpg","images/cerrar.jpg");
            close.set(PRIMARY_SCREEN_W/2 + noticiasPortesObertes[actualNoticia]->normal.getWidth()/2 + 10,90,close.normal.getWidth(), close.normal.getHeight());
            close.draw();
            if(close.isMousePressed()){
                for(int i=0;i<noticiasPortesObertes.size();i++){
                    noticiasPortesObertes[i]->isSelected = false;
                }
                isNoticiaOpen = false;
                actualNoticia = 0;
            }
        }else{
            for(int i=0;i<noticiasPortesObertes.size();i++){
                noticiasPortesObertes[i]->draw();
            }
        }

    }else if(actualVideo == 5){
        for(int i=0;i<noticiasHuelga.size();i++){
            if(noticiasHuelga[i]->isSelected){
                isNoticiaOpen = true;
                actualNoticia = i;
                break;
            }
        }
        if(isNoticiaOpen){
            noticiasHuelga[actualNoticia]->draw();
            close.setup(PRIMARY_SCREEN_W/2 + noticiasHuelga[actualNoticia]->normal.getWidth()/2 + 10,90,"images/cerrar.jpg","images/cerrar.jpg");
            close.set(PRIMARY_SCREEN_W/2 + noticiasHuelga[actualNoticia]->normal.getWidth()/2 + 10,90,close.normal.getWidth(), close.normal.getHeight());
            close.draw();
            if(close.isMousePressed()){
                for(int i=0;i<noticiasHuelga.size();i++){
                    noticiasHuelga[i]->isSelected = false;
                }
                isNoticiaOpen = false;
                actualNoticia = 0;
            }
        }else{
            for(int i=0;i<noticiasHuelga.size();i++){
                noticiasHuelga[i]->draw();
            }
        }

    }else if(actualVideo == 6){
        //actualSelection = "";

    }
}

//--------------------------------------------------------------
void ofApp::initVideos(){
    videoFiesta.load("videos/fiesta.mov");
    videoHuelga.load("videos/huelga.mov");
    videoManifestacion.load("videos/manifiesta.mov");
    videoPleno.load("videos/pleno.mov");
    videoPortes.load("videos/portes.mov");

    videoCreditos.load("videos/nombres.mov");
    videoCreditos.setLoopState(OF_LOOP_NONE);
}

//--------------------------------------------------------------
void ofApp::launchVideo(int vID){
    isPlayingVideo = true;
    actualVideo = vID;

    // RESET VIDEOS
    videoFiesta.stop();
    videoHuelga.stop();
    videoManifestacion.stop();
    videoPleno.stop();
    videoPortes.stop();
    videoCreditos.stop();
    videoFiesta.firstFrame();
    videoHuelga.firstFrame();
    videoManifestacion.firstFrame();
    videoPleno.firstFrame();
    videoPortes.firstFrame();
    videoCreditos.firstFrame();

    if(actualVideo == 1){
        actualSelection = "Fiesta";
        videoFiesta.play();
    }else if(actualVideo == 2){
        actualSelection = "Manifestación";
        videoManifestacion.play();
    }else if(actualVideo == 3){
        actualSelection = "Pleno";
        videoPleno.play();
    }else if(actualVideo == 4){
        actualSelection = "Portes Obertes";
        videoPortes.play();
    }else if(actualVideo == 5){
        actualSelection = "Huelga de hambre";
        videoHuelga.play();
    }else if(actualVideo == 6){
        actualSelection = "";
        videoCreditos.play();
    }
}

//--------------------------------------------------------------
void ofApp::closeVideos(){
    isPlayingVideo = false;
    actualVideo = 0;
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
