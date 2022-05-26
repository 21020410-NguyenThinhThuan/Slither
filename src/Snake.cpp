#include "Snake.h"
#include "Food.h" 
#include "renderer.h"

Point operator+ (const Point& station_1, const Point& station_2) 
{
	return Point{station_1.x + station_2.x, station_1.y + station_2.y };
}
void operator+= (Point& station_1, const Point& station_2) 
{
	station_1.x += station_2.x;
	station_1.y += station_2.y;
}
bool operator== (Point& station_1, Point& station_2)
{
	return (station_1.x==station_2.x && station_1.y==station_2.y);
}

void Snake::insertIMG(SDL_Renderer* renderer, Point snake, std::string imgLocate )
{
	SDL_Rect r{ 16 * snake.x, 16 * snake.y, 16, 16 };
	char* filename=imgDirectory(imgLocate);
	SDL_Texture* texture = loadTexture(renderer,filename);
	blit(renderer,texture,r);
	SDL_DestroyTexture(texture);
}

int Snake::checkBody(Point point, Point prepoint, Point nextpoint)
{
	if ( (point.x==(nextpoint.x-1) && point.y==nextpoint.y  &&  point.x==prepoint.x && point.y==(prepoint.y+1))
	  || (point.x==(prepoint.x-1) && point.y==prepoint.y  &&  point.x==nextpoint.x && point.y==(nextpoint.y+1)) ) return I;

	if ( (point.x==nextpoint.x && point.y==(nextpoint.y+1)  &&  point.x==(prepoint.x+1) && point.y==prepoint.y)
 	  || (point.x==prepoint.x && point.y==(prepoint.y+1)  &&  point.x==(nextpoint.x+1) && point.y==nextpoint.y) ) return II;

	if ( (point.x==nextpoint.x && point.y==(nextpoint.y-1)  &&  point.x==(prepoint.x+1) && point.y==prepoint.y)
 	  || (point.x==prepoint.x && point.y==(prepoint.y-1)  &&  point.x==(nextpoint.x+1) && point.y==nextpoint.y) ) return III;
	
	if ( (point.x==nextpoint.x && point.y==(nextpoint.y-1)  &&  point.x==(prepoint.x-1) && point.y==prepoint.y)
 	  || (point.x==prepoint.x && point.y==(prepoint.y-1)  &&  point.x==(nextpoint.x-1) && point.y==nextpoint.y) ) return IV;

	if (point.y==(prepoint.y+nextpoint.y)/2 && point.x==prepoint.x ) return vertical;

	if (point.x==(prepoint.x+nextpoint.x)/2) return horizontal;
}
int Snake::checkHead(Point prevDirection)
{
	#define head_up 1
	#define head_down 2
	#define head_left 3
	#define head_right 4
	Point up={0,-1},down={0,1},left={-1,0},right={1,0};

	if ( prevDirection == up ) return head_up;
	if ( prevDirection == down ) return head_down;
	if ( prevDirection == left ) return head_left;
	if ( prevDirection == right ) return head_right;
}
int Snake::checkTail(Point tail, Point afterTail)
{
	#define tail_up 1
	#define tail_down 2
	#define tail_left 3
	#define tail_right 4

	if ( tail.x==afterTail.x-1 && tail.y==afterTail.y) return tail_left;
	if ( tail.x==afterTail.x+1 && tail.y==afterTail.y) return tail_right;
	if ( tail.x==afterTail.x && tail.y==afterTail.y+1) return tail_down;
	if ( tail.x==afterTail.x && tail.y==afterTail.y-1) return tail_up;
}

void Snake::reset()
{
	head={WIDTH/16/2,HEIGHT/16/2};
	snake = { {WIDTH/16/2,HEIGHT/16/2} };
	nextDirection={0,0};
	prevDirection={0,0};
	SDL_Delay(300);
}

void Snake::check_eat_fruit(struct Fruit& fruit, Mix_Chunk* chunk)
{
	if ( snake[0].x==fruit.x && snake[0].y==fruit.y ) 
	{
		snake.push_back(sub_tails);
		fruit.move();
		score++;
		Mix_PlayChannel(-1, chunk, 0);
	}
}

bool Snake::check_collision_wall( Mix_Chunk*& over)
{
	if ( snake[0].x==0 || snake[0].x==WIDTH/16-1 || snake[0].y==0 || snake[0].y== HEIGHT/16-1) 
	{
		Mix_PlayChannel(-1, over, 0);
		reset();
		return true;
	}
	return false;
}

bool Snake::check_eatSelf( Mix_Chunk*& over)
{
	for (int i = 1; i < snake.size(); i++) 
	{
		if ( snake[i] == head ) 
		{
			Mix_PlayChannel(-1, over, 0);
			reset();
			return true;
		}
	}
	return false;
}

void Snake::update(struct Fruit& fruit, Mix_Chunk* chunk, SDL_Renderer* renderer, Mix_Chunk* over ) 
{
	dead = false;
	for (int i=0;i<snake.size();i++) while ( snake[i].x==fruit.x && snake[i].y==fruit.y ) fruit.move();

	prevDirection=nextDirection;
	head+=prevDirection;

	sub_tails=snake[snake.size()-1];
	for ( int i=snake.size()-1; i>0; i-- )
	{
		snake[i]=snake[i-1];
	}
	snake[0] = head;

	check_eat_fruit(fruit,chunk);
	if ( check_eatSelf(over) || check_collision_wall(over) ) 
	{
		fruit.move(); 
		dead = true;
		
		endGame(renderer);
		Score( renderer, "Your score: " + std::to_string( score ) );
		score=0;
	    restart( renderer);
	}

	SDL_Delay(70);
}

void Snake::changeDirection(SDL_Event event)
{
	switch (event.key.keysym.sym) 
	{
	case SDLK_UP: 
		if (prevDirection.y != 1) 
		{
			nextDirection = { 0, -1 }; 
		}
		break;
	case SDLK_DOWN:
		if (prevDirection.y != -1) 
		{
			nextDirection = { 0, 1 };
		}
		break;
	case SDLK_LEFT: 
		if (prevDirection.x != 1)
		{
			nextDirection = { -1, 0 }; 
		}
		break;
	case SDLK_RIGHT: 
		if (prevDirection.x != -1) 
		{
			nextDirection = { 1, 0 };
		}
		break;
	}
}

void Snake::draw(SDL_Window* window, SDL_Renderer* renderer) 
{	

	for (int i = 1; i < snake.size()-1; i++)  
	{
		switch ( checkBody( snake[i], snake[(i-1)], snake[(i+1)] ) )
		{
			case I: 
				insertIMG(renderer, snake[i], "./image/snake.bmp"); 
				break;

			case II: 
				insertIMG(renderer, snake[i], "./image/snake.bmp");
				break;

			case III: 
				insertIMG(renderer, snake[i], "./image/snake.bmp");
				break;

			case IV: 
				insertIMG(renderer, snake[i], "./image/snake.bmp"); 
				break;

			case vertical: 
				insertIMG(renderer, snake[i], "./image/snake.bmp");
				break;

			case horizontal: 
				insertIMG(renderer, snake[i], "./image/snake.bmp");
				break;
		}
	}	

	switch ( checkTail(snake[snake.size()-1], snake[snake.size()-2]) )
	{
		case tail_up: 
			insertIMG(renderer, snake[snake.size()-1], "./image/snake.bmp"); 
			break;

		case tail_down: 
			insertIMG(renderer, snake[snake.size()-1], "./image/snake.bmp");
			break;

		case tail_left:
			insertIMG(renderer, snake[snake.size()-1], "./image/snake.bmp");
			break;

		case tail_right: 
			insertIMG(renderer,snake[snake.size()-1], "./image/snake.bmp"); 
			break;
	}

	switch ( checkHead(prevDirection) )
	{
		case head_up: insertIMG(renderer, snake[0], "./image/head_up.bmp"); break;

		case head_down: insertIMG(renderer, snake[0], "./image/head_down.bmp"); break;

		case head_left: insertIMG(renderer, snake[0], "./image/head_left.bmp"); break;

		case head_right: insertIMG(renderer,snake[0], "./image/head_right.bmp"); break;
	}
	

}



