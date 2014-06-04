#include "Game.h"


Game::Game()
{
}


Game::~Game()
{
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
	std::cout << "SDL init done! \n";
	//Use paramters of the function 'init' to create window
	m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

	if (m_pWindow != 0)
	{
	  std::cout << "Window created! \n";
	  //Create renderer
	  m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

	  if (m_pRenderer != 0)
	  {
		//Set renderer colour to white
		std::cout << "Renderer created! \n";
		SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
	  }
	  else
	  {
		std::cout << "Render creation failed! \n";
		return false;
	  }
	}
	else
	{
	  std::cout << "Window creation failed! \n";
	  return false;
	}
  }
  else
  {
	std::cout << "SDL inti failed! \n";
	return false;
  }

  std::cout << "Init Done! \n";

  //If everything done properly set running as true and return true
  m_bRunning = true;
  return true;
}


void Game::render()
{
  //Clear Renderer
  SDL_RenderClear(m_pRenderer);

  //Draw Renderer
  SDL_RenderPresent(m_pRenderer);

}

void Game::clean()
{
  //Destroy window and other stuff
  std::cout << "Cleaning the game! \n";
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  //Quit SDL subsystems
  SDL_Quit();
}

void Game::handleEvents()
{
  //Check if event has occured
  SDL_Event event;
  if (SDL_PollEvent(&event))
  {
	//Handle event accordingly
	switch (event.type)
	{
	case SDL_QUIT:
	  m_bRunning = false;
	  break;

	default:
	  break;

	}
  }
}