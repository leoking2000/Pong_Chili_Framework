#include "Box.h"
#include "Graphics.h"


Box::Box(float xPos, float yPos, int boxWidth, int boxHeight)
{
	x = xPos;
	y = yPos;
	width = boxWidth;
	height = boxHeight;
}

Box::Box(float x, float y, float vX, float vY, int boxWidth, int boxHeight)
{
	Box(x, y, boxWidth, boxHeight);
	speedX = vX;
	speedY = vY;
}

bool Box::isIntersecting(const Box& box) const
{
	return x + width  >= box.x - box.width &&
		   x - width  <= box.x + box.width &&
		   y - height <= box.y + box.height &&
		   y + height >= box.y - box.height;

}

void Box::update(float deltaTime)
{
	x += speedX * deltaTime; 
	y += speedY * deltaTime;

	// right wall
	if (x + width >= Graphics::ScreenWidth / 2) {
		speedX = -speedX;
	}
	// left wall
	if (x - width <= -Graphics::ScreenWidth / 2) {
		speedX = -speedX;
	}
	// top wall
	if (y + height >= Graphics::ScreenHeight / 2) {
		speedY = -speedY;
	}
	if (y - height <= -Graphics::ScreenHeight / 2) {
		speedY = -speedY;
	}

	ClampPositionToScreen();
}

void Box::translate(float dx, float dy)
{
	x += dx; y += dy;

	ClampPositionToScreen();
}

void Box::ClampPositionToScreen()
{
	if (x + width >= Graphics::ScreenWidth / 2)    { x = float( (Graphics::ScreenWidth / 2)   - (width  + 1) );  }
	if (x - width <= -Graphics::ScreenWidth / 2)   { x = float( (-Graphics::ScreenWidth / 2)  + (width  + 1) );  }
	if (y + height >= Graphics::ScreenHeight / 2)  { y = float( (Graphics::ScreenHeight / 2)  - (height + 1) );  }
	if (y - height <= -Graphics::ScreenHeight / 2) { y = float( (-Graphics::ScreenHeight / 2) + (height + 1) );  }
}

void Box::setPosition(float xpos, float ypos)
{
	x = xpos; y = ypos;
	ClampPositionToScreen();
}

void Box::setVelocity(float xvel, float yvel)
{
	speedX = xvel; speedY = yvel;
}


void Box::draw(Graphics& gfx, int r, int g, int b) const
{
	int posX =  int(x) + (gfx.ScreenWidth / 2);
	int posY = -int(y) + (gfx.ScreenHeight / 2);

	for (int i = posX - width; i <= posX + width; i++) {
		for (int j = posY - height; j <= posY + height; j++) {
			gfx.PutPixel(i, j, r, g, b);
			gfx.PutPixel(i, j, r, g, b);
		}
	}

}
