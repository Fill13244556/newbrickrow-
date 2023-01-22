#pragma once
#include "SFML/Graphics.hpp"
#include "bat.h"
#include "ball .h"
#include "settings .h"
#include "brick.h"
#include "brickRow.h"



void checkEvents(sf::RenderWindow& window, Ball& ball) {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
		if (ball.shape.getPosition().y >= (WINDOW_HEIGHT - 2 * BALL_RADIUS))
		{

		}
	}
	
}

void updateGame(Bat& bat, Ball& ball, Brick& brick, BrickRow& brickrow) {
	batControl(bat);
	batReboundEdges(bat);
	moveBall(ball);
	ballControl(ball, bat);
}



void drawGame(sf::RenderWindow& window, Bat& bat, Ball& ball, Brick& brick, BrickRow& brickrow) {
	window.clear();
	batDraw(window, bat);
	ballDraw(window, ball);
	brickDraw(window, brick); 
	brickRowDraw(window, brickrow);
	window.display();
}
