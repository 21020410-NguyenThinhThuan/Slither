#pragma once
#include "renderer.h"
#include <vector>
#include<SDL_image.h>
#include<iostream>

	#define I 1
	#define II 2
	#define III 3
	#define IV 4
	#define vertical 5
	#define horizontal 6
struct Point 
{
	int x, y;
};

struct Snake
{
	std::vector<Point> snake ={ {1,1} };
	Point head={WIDTH/2/16,HEIGHT/2/16},sub_tails;
	Point prevDirection, nextDirection;
	bool dead;
	int score = 0;

	void insertIMG(SDL_Renderer* renderer, Point snake, std::string imgLocate );
	int checkBody(Point dot, Point preDot, Point nextDot);
	int checkHead(Point prevDirection);
	int checkTail(Point tail, Point afterTail);
	
    void update(struct Fruit& fruit, Mix_Chunk* chunk, SDL_Renderer* renderer, Mix_Chunk* over);
	void changeDirection(SDL_Event event);
	void reset();
	void check_eat_fruit(struct Fruit& fruit, Mix_Chunk* chunk);
	
	bool check_collision_wall( Mix_Chunk*& over);
	bool check_eatSelf( Mix_Chunk*& over);

	void draw(SDL_Window* window, SDL_Renderer* renderer);
};

