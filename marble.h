#pragma once
class marble {
private:
	int xPos;
	int yPos;
	bool lifted;
	bool black;

public:
	void initMarble(int x, int y);
	void move(int x, int y);
	bool clicked(int x, int y);
	void draw();
	void liftUp();
	void PutDown();
	bool isLifted();
	void snap();
	

};

 