#pragma once

#include "Graphics.h"
#include "Vector2.h"

class Rect
{
private:
	Vector2 topLeft;
	int width;
	int height;
	
	void ClampPositionToScreen();
public:
	Rect(Vector2 topLeft, int width, int height);

	void Draw(Graphics& gfx, Color c) const;
	bool isIntersecting(const Rect& Paddle) const;

	void Translate(const Vector2& delta);

	// getters
	Vector2 GetCenter();

};

