#pragma once
#include <SDL.h>
#include <cstdlib>
#include <ctime>
struct Fruit
{
	int x,y;
	void move();
	void draw(SDL_Window* window,SDL_Renderer* renderer);
};
