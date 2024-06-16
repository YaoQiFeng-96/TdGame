#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include "manager.h"

#include <iostream>

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"

class GameManager : public Manager<GameManager>
{
	friend class Manager<GameManager>;
public:
	int run(int argc, char** argv)
	{
		Uint64	last_counter = SDL_GetPerformanceCounter();
		const Uint64 conter_freq = SDL_GetPerformanceFrequency();

		while (!is_quit)
		{
			while (SDL_PollEvent(&event))
				on_input();

			Uint64 current_counter = SDL_GetPerformanceCounter();
			double delta = (double)(current_counter - last_counter) / conter_freq;
			last_counter = current_counter;
			if (delta * 1000 < 1000.0 / 60)
			{
				SDL_Delay((Uint32)(1000.0 / 60 - delta * 1000));
			}
			on_update(delta);

			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			SDL_RenderClear(renderer);

			on_render();

			SDL_RenderPresent(renderer);
		}
		return 0;
	}

protected:
	GameManager()
	{
		init_assert(!SDL_Init(SDL_INIT_EVERYTHING), "SDL2 init faild.");
		init_assert(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG), "SDL_image init faild.");
		init_assert(Mix_Init(MIX_INIT_MP3), "SDL_mixer init faild.");
		init_assert(!TTF_Init(), "SDL_ttf init faild.");

		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
		
		SDL_SetHint(SDL_HINT_IME_SHOW_UI, "1");

		window = SDL_CreateWindow(u8"´å×¯±£ÎÀÕ½", 
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			1280, 720, 
			SDL_WINDOW_SHOWN);
		init_assert(window, "window create faild.");

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
		init_assert(renderer, "renderer create faild.");
	}

	~GameManager()
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		
		TTF_Quit();
		Mix_Quit();
		IMG_Quit();
		SDL_Quit();
	}

private:
	SDL_Event event;
	bool is_quit = false;

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

private:
	void init_assert(bool flag, const char* err_msg)
	{
		if (flag) return;

		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "game init faild", err_msg, window);
		exit(-1);
	}

	void on_input()
	{

	}

	void on_update(double delta)
	{

	}

	void on_render()
	{

	}
};
#endif // !__GAME_MANAGER_H__

