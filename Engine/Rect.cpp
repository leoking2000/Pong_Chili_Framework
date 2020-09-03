#include "Rect.h"

Rect::Rect(Vector2 topLeft, int width, int height)
	:
	topLeft(topLeft),
	width(width),
	height(height)
{
}

void Rect::Draw(Graphics& gfx, Color c) const
{
	gfx.DrawRect(topLeft.x, topLeft.y, width, height, c);
}

bool Rect::isIntersecting(const Rect& other) const
{
	return topLeft.x < other.topLeft.x + other.width &&
		topLeft.x + width > other.topLeft.x &&
		topLeft.y < other.topLeft.y + other.height &&
		topLeft.y + height > other.topLeft.y;
}

void Rect::Translate(const Vector2& delta)
{
	topLeft += delta;
	ClampPositionToScreen();
}

Vector2 Rect::GetCenter() const
{
	return Vector2(topLeft.x + width/2, topLeft.y + height/2);
}

void Rect::ClampPositionToScreen()
{
	if (topLeft.x <= 0) { topLeft.x = 0.0f; }
	if (topLeft.x + width >= Graphics::ScreenWidth)   { topLeft.x = float(Graphics::ScreenWidth - width); }
	if (topLeft.y <= 0) { topLeft.y = 0.0f; }
	if (topLeft.y + height >= Graphics::ScreenHeight) { topLeft.y = float(Graphics::ScreenHeight - height); }
}
