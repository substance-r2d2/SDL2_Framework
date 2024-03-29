
#include "Game.h"

Game* g_game = 0;

int main(int argc, char* args[])
{
  g_game = new Game();

  g_game->init("Ver 1.2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

  while (g_game->running())
  {
	g_game->handleEvents();
	g_game->update();
	g_game->render();
  }

  g_game->clean();

  return 0;
}

