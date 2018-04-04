#include "marble.h"
#include <math.h>
#include "constants.h"
#include<iostream>
#include<allegro5\allegro.h>
#include<allegro5/allegro_primitives.h>
using namespace std;


void marble::initMarble(int x, int y) {

	xPos = x;
	yPos = y;
	lifted = false;


}

void marble::move(int x, int y) {
	xPos = x;
	yPos = y;
	cout << "moving";

}

bool marble::clicked(int x, int y) {
	cout << " checking " << x << " , " << y << " against marble's position " << xPos << " , " << yPos << endl;
	//distance formula
	if (sqrt( (xPos - x)*(xPos - x) + (yPos  - y)*(yPos  - y) ) < MARBLE_RADIUS ) {
		cout << "element clicked!" << endl;
		return true;

	}
	else
		return false;


}

void marble::draw() {
	al_draw_filled_circle(xPos, yPos, MARBLE_RADIUS, al_map_rgb(250, 250, 250));

}

void marble::liftUp() {
	lifted = true;
	cout << "lifted";

}

void marble::PutDown() {
	lifted = false;
	cout << "put down";

}

bool marble::isLifted() {

	return lifted;
}