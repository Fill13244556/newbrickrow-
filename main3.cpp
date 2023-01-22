#include "SFML/Graphics.hpp"
#include "settings .h"
#include "functions.h"
#include "bat.h"
#include "ball .h"
#include "textobj.h"
#include <ctime>


using namespace sf;
int main()
{
	RenderWindow window(
		VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),WINDOW_TITLE);
	window.setFramerateLimit(FPS);
	Bat bat;
	batInit(bat);


	Ball ball;
	initBall(ball);
	

	Brick brick;
	brickInit(brick, Color::Yellow,Brick_Start_Pos);

	BrickRow brickrow;
	brickRowInit(brickrow, BRICK_SIZE, Brick_Start_Pos, stepX);


	//текст для счёта.
	TextObj scoreText; 
	initText(scoreText, ball.score); 
	
	
	
	while (window.isOpen()) {
		checkEvents(window, ball);
		updateGame(bat,ball,brick,brickrow);
		drawGame(window,bat,ball,brick,brickrow);
		TextDraw(window, scoreText);
		
	}

	return 0;
}