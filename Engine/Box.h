#pragma once

#include "Graphics.h"
#include "Vector2.h"

class Box
{
private:
	Vector2 pos{ 0.0f, 0.0f };
	int   width;
	int   height;
	Vector2 vel{ 0.0f, 0.0f };

	void ClampPositionToScreen();
public:
	Box(const Vector2& p , int boxWidth, int boxHeight);
	Box(const Vector2& p, const Vector2& v, int boxWidth, int boxHeight);

	bool isIntersecting(const Box& box) const;
	void draw(Graphics& gfx, int r, int g, int b) const;

	void update(float deltaTime);
	void translate(const Vector2& delta);
	void setPosition(const Vector2& newPos);
	void setVelocity(const Vector2& newVel);

	// getter
	float getX() const { return pos.x; }
	float getY() const { return pos.y; }

	int getWidth() const { return width; }
	int getHeigth() const { return height; }

	float getVelocityX() const { return vel.x; }
	float getVelocityY() const { return vel.y; }
	

};

