#include "Ball.h"

void Ball::collideWith(const Rect& other)
{
	velocity.y = -velocity.y;
}

Ball::Ball(const Vector2& pos, int in_radius)
	:
	rect(pos - radius, in_radius * 2, in_radius * 2),
	radius(in_radius)
{
}

void Ball::Draw(Graphics& gfx) const
{
	const Vector2 center = rect.GetCenter();
	gfx.DrawCircle(center.x, center.y, radius, Colors::Green);
}

void Ball::update(float deltaTime, const std::vector<Rect>& rects)
{
	// check for collision with rects
	for (const Rect other : rects)
	{
		if (rect.isIntersecting(other))
		{
			if (collisionbuffer)
			{
				//collideWith(other)
				collisionbuffer = false;
				break;
			}
		}
		else
		{
			collisionbuffer = true;
		}
	}

	//Move
	rect.Translate(velocity);
}
