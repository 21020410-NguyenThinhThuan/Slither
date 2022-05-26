#include "renderer.h"
#include "Food.h"
#include "Snake.h"

	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL; 
	SDL_Event event;
	Mix_Chunk* chunk = NULL;
	Mix_Chunk* over = NULL;

int main(int argc, char* args[]) 
{
	srand(std::time(NULL));
	initSDL(window,renderer,chunk,over);
	bool running = true;
	Snake game = {};
	Fruit fruit = {};
	fruit.move();
	while (running) 
	{
		while (SDL_PollEvent(&event)) 
		{
			switch (event.type)
			{
			case SDL_QUIT: 
			    running = false;
				break;
			case SDL_KEYDOWN:
				game.changeDirection(event);
				break;
			}
		}

		draw_Background(window,renderer);
		draw_Wall(window,renderer);
		game.update(fruit,chunk,renderer,over);
		game.draw(window,renderer);
		fruit.draw(window,renderer);

		SDL_RenderPresent(renderer);

		if (game.dead == true) 
		{
			draw_Background1(window,renderer);
			SDL_Delay(3000);
		}
	}
	quitSDL(window,renderer);
	return 0;
}

