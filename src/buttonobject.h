#pragma once

#include "ofMain.h"
#include "ofxMSAInteractiveObject.h"

#include "config.h"


class buttonObject : public ofxMSAInteractiveObject {
public:

    ofImage normal;
    ofImage over;
    ofImage selected;
    string img;

    int posX;
    int posY;

    bool isOver;
    bool isSelected;
    bool isPressed;

    void setup(int px, int py,string image, string image_selected) {
        enableMouseEvents();
        enableKeyEvents();

        isOver = false;
        isSelected = false;
        isPressed = false;

        posX = px;
        posY = py;

        img = image;
        normal.load(image);
        over.load(image_selected);
        selected.load(image_selected);
    }


    void exit() {

    }


    void update() {
        //		x = ofGetWidth()/2 + cos(ofGetElapsedTimef() * 0.2) * ofGetWidth()/4;
        //		y = ofGetHeight()/2 + sin(ofGetElapsedTimef() * 0.2) * ofGetHeight()/4;
    }


    void draw() {
        ofSetColor(255);
        if(img != "images/cerrar.jpg"){
            if(isSelected && !isOver){
                normal.draw(posX,posY,220,220);
                selected.draw(posX,posY-6,220,220);
            }else if(isOver && !isSelected){
                normal.draw(posX,posY,220,220);
                over.draw(posX,posY-6,220,220);
            }else if(!isOver && !isSelected){
                normal.draw(posX,posY,220,220);
            }else{
                normal.draw(posX,posY,220,220);
                over.draw(posX,posY-6,220,220);
            }
        }else{
            normal.draw(posX,posY);
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
        isPressed = true;
    }

    virtual void onRelease(int x, int y, int button) {
        isSelected = true;
        isPressed = false;
    }

    virtual void onReleaseOutside(int x, int y, int button) {
        isSelected = false;
        isPressed = false;
    }

    virtual void keyPressed(int key) {
        //printf("MyTestObject::keyPressed(key: %i)\n", key);
    }

    virtual void keyReleased(int key) {
        //printf("MyTestObject::keyReleased(key: %i)\n", key);
    }

};
