#include "Paddle.h"


Paddle::Paddle(const Vector2& p, int PaddleWidth, int PaddleHeight)
	:
	rect(p, PaddleWidth, PaddleHeight)
{
}

void Paddle::update(const Keyboard& kbd, float deltaTime)
{
	if (kbd.KeyIsPressed(VK_UP))
	{
		rect.Translate(Vector2(0.0f, - 400.0f) * deltaTime);
	}
	else if (kbd.KeyIsPressed(VK_DOWN))
	{
		rect.Translate(Vector2(0.0f, 400.0f) * deltaTime);
	}
}

const Rect& Paddle::GetRectagle() const
{
	return rect;
}

void Paddle::Draw(Graphics& gfx) const
{
	rect.Draw(gfx, Colors::White);
}
