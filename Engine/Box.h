#pragma once

#include "Graphics.h"

class Box
{
private:
	float x;
	float y;
	int   width;
	int   height;
	float speedX = 0.0f;
	float speedY = 0.0f;

	void ClampPositionToScreen();
public:
	Box(float x, float y, int boxWidth, int boxHeight);
	Box(float x, float y, float vX, float vY, int boxWidth, int boxHeight);

	bool isIntersecting(const Box& box) const;
	void draw(Graphics& gfx, int r, int g, int b) const;

	void update(float deltaTime);
	void translate(float dx, float dy);
	void setPosition(float xpos, float ypos);
	void setVelocity(float xvel, float yvel);

	// getter
	float getX() const { return x; }
	float getY() const { return y; }

	int getWidth() const { return width; }
	int getHeigth() const { return height; }

	float getVelocityX() const { return speedX; }
	float getVelocityY() const { return speedY; }
	

};

