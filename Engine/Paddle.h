#pragma once

#include "Rect.h"
#include "Keyboard.h"

class Paddle
{
private:
	Rect rect;

public:
	Paddle(const Vector2& p , int PaddleWidth, int PaddleHeight);

	void Draw(Graphics& gfx) const;

	void update(const Keyboard& kbd ,float deltaTime);

	// getter
	const Rect& GetRectagle() const;
	

};

