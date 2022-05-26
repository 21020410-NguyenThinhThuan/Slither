#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#define WIDTH 800	
#define HEIGHT 600


void initSDL(SDL_Window*& window, SDL_Renderer*& renderer, Mix_Chunk*& chunk,  Mix_Chunk*& over);

void quitSDL(SDL_Window*& window, SDL_Renderer*& renderer);

char* imgDirectory(std::string s);

SDL_Texture* loadTexture(SDL_Renderer* renderer,char* filename);

void blit(SDL_Renderer* renderer ,SDL_Texture* texture, SDL_Rect dest);

void draw_Wall(SDL_Window* window, SDL_Renderer* renderer);

void draw_Background(SDL_Window* window, SDL_Renderer* renderer);

void Score(SDL_Renderer* renderer, std::string s);

void endGame(SDL_Renderer* renderer);

void restart(SDL_Renderer* renderer);

void draw_Background1(SDL_Window* window, SDL_Renderer* renderer);

void Score1(SDL_Renderer* renderer, std::string s);
