/*
 * Xplode - game.cpp
 *
 * Copyright (C) 2016 Bytes Club
 *
 * AUTHORS
 *  Rudra Nil Basu <rudra.nil.basu.1996@gmail.com>
 */
#include<GL/gl.h>
#include<GL/glut.h>

#include "game.h"

int gridX, gridY;
int posX = 20, posY = 20;
short sDirection = RIGHT;

void initGrid(int rows, int columns)
{
	gridX = columns;
	gridY = rows;
}

void unit(int x, int y)
{
	if(x == 0 || x == gridX -1 || y == 0 || y == gridY -1) {
		glColor3f(1.0, 0.0, 0.0);
		glLineWidth(4.0);
	} else {
		glColor3f(1.0,1.0,1.0);
		glLineWidth(1.0);
	}
	glBegin(GL_LINES);
		glVertex2d(x,y);glVertex2d(x+1,y);
		glVertex2d(x+1,y);glVertex2d(x+1,y+1);
		glVertex2d(x+1,y+1);glVertex2d(x,y+1);
		glVertex2d(x,y+1);glVertex2d(x,y);
	glEnd();
}

void drawGrid()
{
	for(int x = 0;x < gridX;x++) {
		for(int y = 0;y < gridX;y++) {
			unit(x,y);
		}
	}
}

void drawSnake()
{
	if(sDirection == UP) {
		posY++;
	} else if(sDirection == DOWN) {
		posY--;
	} else if(sDirection == LEFT) {
		posX--;
	} else if(sDirection == RIGHT) {
		posX++;
	}
	glRectd(posX, posY, posX+1, posY+1);
}
