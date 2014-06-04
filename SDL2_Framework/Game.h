#pragma once

#include <SDL.h>
#include <iostream>
#include <string>

//Main game class
class Game
{
public:
	Game();
	//Create window
	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
	//Clear and draw using renderer
	void render();
	//Do physics here
	void update(){}
	//Handle user inputs
	void handleEvents();
	//Clean the program here
	void clean();
	//Check if program is running
	bool running(){
		return m_bRunning;
	}
	~Game();
private:
	bool m_bRunning;
	//Declare a window and renderer
	SDL_Window* m_pWindow = 0;
	SDL_Renderer* m_pRenderer = 0;
};

