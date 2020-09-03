#pragma once

#include "Rect.h"
#include <vector>

class Ball
{
private:
	Rect rect;
	int radius;
	Vector2 velocity{ 0.0f, 0.0f };

	bool collisionbuffer = true;

	void collideWith(const Rect& other);
public:
	Ball(const Vector2& pos, int radius);

	void Draw(Graphics& gfx) const;
	void update(float deltaTime, const std::vector<Rect>& rects);

};

