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
	//cout << "moving";

}

//checks if you've clicked somewhere in the piece's area
bool marble::clicked(int x, int y) {
	//cout << " checking " << x << " , " << y << " against marble's position " << xPos << " , " << yPos << endl;
	//distance formula
	if (sqrt( (xPos - x)*(xPos - x) + (yPos  - y)*(yPos  - y) ) < MARBLE_RADIUS ) {
		//cout << "element clicked!" << endl;
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
	//cout << "lifted";

}

void marble::PutDown() {
	lifted = false;
	//cout << "put down";

}

//tells curser if a piece is lifted or not
bool marble::isLifted() {

	return lifted;
}

//the snap function snaps the piece to the nearest intersection of lines
void marble::snap() {
	int rowWidth = SCREEN_W / NUM_ROWS;
	if (xPos % rowWidth < rowWidth/2)
		xPos -= xPos % rowWidth;
	else
		xPos += rowWidth-(xPos % rowWidth);

	if (yPos % rowWidth < rowWidth / 2)
		yPos -= yPos % rowWidth;
	else
		yPos += rowWidth - (yPos % rowWidth);
}