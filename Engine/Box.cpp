#include "Box.h"
#include "Graphics.h"


Box::Box(const Vector2& p, int boxWidth, int boxHeight)
	:
	pos(p)
{
	width = boxWidth;
	height = boxHeight;
}

Box::Box(const Vector2& p, const Vector2& v, int boxWidth, int boxHeight)
	:
	vel(v)
{
	Box(p, boxWidth, boxHeight);
}

bool Box::isIntersecting(const Box& box) const
{
	return pos.x + width  >= box.pos.x - box.width &&
		   pos.x - width  <= box.pos.x + box.width &&
		   pos.y - height <= box.pos.y + box.height &&
		   pos.y + height >= box.pos.y - box.height;

}

void Box::update(float deltaTime)
{
	pos += vel * deltaTime;

	// right wall
	if (pos.x + width >= Graphics::ScreenWidth / 2) {
		vel.x = -vel.x;
	}
	// left wall
	if (pos.x - width <= -Graphics::ScreenWidth / 2) {
		vel.x = -vel.x;
	}
	// top wall
	if (pos.y + height >= Graphics::ScreenHeight / 2) {
		vel.y = -vel.y;
	}
	//bottom
	if (pos.y - height <= -Graphics::ScreenHeight / 2) {
		vel.y = -vel.y;
	}

	ClampPositionToScreen();
}

void Box::translate(const Vector2& delta)
{
	pos += delta;

	ClampPositionToScreen();
}

void Box::ClampPositionToScreen()
{
	if (pos.x + width >= Graphics::ScreenWidth / 2)    { pos.x = float( (Graphics::ScreenWidth / 2)   - (width  + 1) );  }
	if (pos.x - width <= -Graphics::ScreenWidth / 2)   { pos.x = float( (-Graphics::ScreenWidth / 2)  + (width  + 1) );  }
	if (pos.y + height >= Graphics::ScreenHeight / 2)  { pos.y = float( (Graphics::ScreenHeight / 2)  - (height + 1) );  }
	if (pos.y - height <= -Graphics::ScreenHeight / 2) { pos.y = float( (-Graphics::ScreenHeight / 2) + (height + 1) );  }
}

void Box::setPosition(const Vector2& newPos)
{
	pos = newPos;
	ClampPositionToScreen();
}

void Box::setVelocity(const Vector2& newVel)
{
	vel = newVel;
}


void Box::draw(Graphics& gfx, int r, int g, int b) const
{
	int posX =  int(pos.x) + (gfx.ScreenWidth / 2);
	int posY = -int(pos.y) + (gfx.ScreenHeight / 2);

	for (int i = posX - width; i <= posX + width; i++) {
		for (int j = posY - height; j <= posY + height; j++) {
			gfx.PutPixel(i, j, r, g, b);
			gfx.PutPixel(i, j, r, g, b);
		}
	}

}
