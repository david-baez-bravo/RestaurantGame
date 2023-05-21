#include "MenuState.h"

MenuState::MenuState() {
	string text = "Start";
	int font = 30;
	fonts.load("TechnoRaceItalic-eZRWe.otf", font);
    ofRectangle bounds = fonts.getStringBoundingBox(text, 0, 0);
    int x = (ofGetWidth() - bounds.width) / 2;
	startButton = new Button(x, ofGetHeight()/2, bounds.width, bounds.height, text, font);


	string titleText = "Dinner Dash";
	font = 72;
	fonts.load("TechnoRaceItalic-eZRWe.otf", font);
    bounds = fonts.getStringBoundingBox(titleText, 0, 0);
    x = (ofGetWidth() - bounds.width) / 2;
    title = new Button(x, 200,  bounds.width, bounds.height, titleText, font);
}

void MenuState::tick() {
	startButton->tick();
	if(startButton->wasPressed()){
		setNextState("Game");
		setFinished(true);
	}
}

void drawCenteredString(const string& text, int y, ofTrueTypeFont fonts) {
	ofRectangle bounds = fonts.getStringBoundingBox(text, 0, 0);
    int x = (ofGetWidth() - bounds.width) / 2;
    fonts.drawString(text, x, y);
}

void MenuState::render() {
	ofSetBackgroundColor(255, 40, 35);
	startButton->render();
	title->render();
	fonts.load("TechnoRaceItalic-eZRWe.otf", 15);
	int y = ofGetHeight() / 2 + 125;
	drawCenteredString("Press 'e' to pickup ingredients", y, fonts);
	y += 25;
	drawCenteredString("Press 's' to serve clients", y, fonts);
	y += 25;
	drawCenteredString("Press 'u' to remove the last added ingredient", y, fonts);
	y += 25;
	drawCenteredString("Press right arrow key to move right", y, fonts);
	y += 25;
	drawCenteredString("Press left arrow key to move left", y, fonts);
	y += 25;
	drawCenteredString("Serve clients before they leave", y, fonts);
	y += 25;
	ofSetColor(ofColor::blue);
	drawCenteredString("Be wary of Inspectors", y, fonts);
	ofSetColor(ofColor::white);
}

void MenuState::keyPressed(int key){
	
}

void MenuState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void MenuState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}