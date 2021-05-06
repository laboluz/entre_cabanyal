#pragma once

#include "ofMain.h"
#include "ofxMSAInteractiveObject.h"

#include "config.h"

class noticiaObject : public ofxMSAInteractiveObject {
public:

    ofImage normal;
    ofImage over;
    ofImage selected;

    string fecha;
    string graphicalDate;
    int year, month, day, md;

    int posX;
    int posY;

    bool isOver;
    bool isSelected;

    void init(string image){
        ofFile temp(image);
        fecha = temp.getFileName().substr(0,temp.getFileName().find("_"));
        graphicalDate = fecha.substr(0,2)+"/"+fecha.substr(2,2)+"/"+fecha.substr(4,2);

        day = ofToInt(fecha.substr(0,2));
        month = ofToInt(fecha.substr(2,2));
        year = ofToInt(fecha.substr(4,2));

        md = month*100 + day;

        if(year < 20){
            year += 2000;
        }else{
            year += 1900;
        }
    }

    void setup(int px, int py,string image) {
        enableMouseEvents();
        enableKeyEvents();

        isOver = false;
        isSelected = false;

        posX = px;
        posY = py;

        normal.load(image);
        over.load(image);
        selected.load(image);

        //printf("%i\n",md);
    }


    void exit() {

    }


    void update() {
        //		x = ofGetWidth()/2 + cos(ofGetElapsedTimef() * 0.2) * ofGetWidth()/4;
        //		y = ofGetHeight()/2 + sin(ofGetElapsedTimef() * 0.2) * ofGetHeight()/4;
    }


    void draw() {

        if(isSelected){
            ofSetColor(255);
            normal.draw(PRIMARY_SCREEN_W/2 - normal.getWidth()/2, 100);
        }else if(isOver){
            ofSetColor(255,255,255);
            ofDrawBitmapString(graphicalDate,posX,posY);
        }else{
            ofSetColor(255,255,0);
            ofDrawBitmapString(graphicalDate,posX,posY);
        }

    }

    virtual void onRollOver(int x, int y) {
        isOver = true;
    }

    virtual void onRollOut() {
        isOver = false;
    }

    virtual void onMouseMove(int x, int y){
        //printf("MyTestObject::onMouseMove(x: %i, y: %i)\n", x, y);
    }

    virtual void onDragOver(int x, int y, int button) {
        //printf("MyTestObject::onDragOver(x: %i, y: %i, button: %i)\n", x, y, button);
    }

    virtual void onDragOutside(int x, int y, int button) {
        //printf("MyTestObject::onDragOutside(x: %i, y: %i, button: %i)\n", x, y, button);
    }

    virtual void onPress(int x, int y, int button) {

    }

    virtual void onRelease(int x, int y, int button) {
        isSelected = true;
    }

    virtual void onReleaseOutside(int x, int y, int button) {
        isSelected = false;
    }

    virtual void keyPressed(int key) {
        //printf("MyTestObject::keyPressed(key: %i)\n", key);
    }

    virtual void keyReleased(int key) {
        //printf("MyTestObject::keyReleased(key: %i)\n", key);
    }

};
