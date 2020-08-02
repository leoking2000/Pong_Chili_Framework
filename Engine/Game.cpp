/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
	resetBall();
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}


void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_UP))   { paddle.translate(0,  7);   }
	if (wnd.kbd.KeyIsPressed(VK_DOWN)) { paddle.translate(0, -7);   }

	// for ai vs ai
	//AI_move(paddle);
	// the ai is Too good
	AI_move(AIpaddle);

	if(wnd.kbd.KeyIsPressed(VK_SPACE) && ball_active == false) 
	{ 
		ball_active = true;
		ball.setVelocity( 5, -5);
	}

	if (ball_active) 
	{ 
		ball.update();
		if ((ball.isIntersecting(paddle) || ball.isIntersecting(AIpaddle)))
		{
			if (CollisionBuffer == false)
			{
				ball.setVelocity(-ball.getVelocityX(), ball.getVelocityY());
				CollisionBuffer = true;
			}
		}
		else
		{
			CollisionBuffer = false;
		}

		if (ball.getX() - ball.getWidth() <= -(gfx.ScreenWidth / 2) + 5  || 
			ball.getX() + ball.getWidth() >=  (gfx.ScreenWidth / 2) - 5)
		{ 
			resetBall();
		}

	}
}

void Game::resetBall()
{
	ball_active = false;
	ball.setPosition(0, 0);
	ball.setVelocity(0, 0);
}

void Game::AI_move(Box& p)
{
	if (ball.getY() > p.getY() + p.getWidth() / 2) {
		p.translate(0, 5);
	}
	if (ball.getY() < p.getY() - p.getWidth() / 2) {
		p.translate(0, -5);
	}

}

void Game::ComposeFrame()
{
	//ball.draw(gfx, 255, 255, 255);
	gfx.DrawCircle(ball.getX(), ball.getY(), 5, Colors::White);
	paddle.draw(gfx, 255, 255, 255);
	AIpaddle.draw(gfx, 255, 255, 255);
}
