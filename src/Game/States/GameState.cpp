#include "GameState.h"

GameState::GameState() {
    this->restaurant = new Restaurant();
}

void GameState::tick() {
	restaurant->tick();
	if(restaurant->money >= 100){
		setNextState("Win");
		setFinished(true);
	}
	if(restaurant->entityManager->clientLeft == 10){
		setNextState("Lose");
		setFinished(true);
	}
}
void GameState::render() {
	restaurant->render();
}

void GameState::keyPressed(int key){
	restaurant->keyPressed(key);
}

void GameState::mousePressed(int x, int y, int button){
}

void GameState::keyReleased(int key){
}

void GameState::reset(){
	setFinished(false);
	setNextState("");
}