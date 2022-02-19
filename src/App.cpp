//
// Created by cytek on 2/17/22.
//

#include "App.hpp"
#include "SDL_image.h"
#include <filesystem>

App::App()
	: m_background{}, m_renderer{}, m_window{}, m_texture_manager{} {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
	SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
  }

  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

  m_window = SDL_CreateWindow(
	  "SDL2 Test",
	  SDL_WINDOWPOS_CENTERED,
	  SDL_WINDOWPOS_CENTERED,
	  640, 360,
	  0);

  if (m_window == nullptr) {
	SDL_Log("Failed to initialize window: %s", SDL_GetError());
  }

  m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_SOFTWARE);

  if (m_renderer == nullptr) {
	SDL_Log("Failed to initialize renderer: %s", SDL_GetError());
  }

  // Initialize SDL Image
  if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) == 0) {
	SDL_Log("Failed to initialize SDL Image: %s", SDL_GetError());
  }

  // Load first image
  m_texture_manager = new TextureManager(m_renderer);
  m_texture_manager->LoadFromDirectory("gfx");
  m_background = m_texture_manager->GetTexture("gfx/background.png");
}

void App::Draw() {
  SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(m_renderer);

  auto dest_rect = SDL_Rect{
	  .w = 640,
	  .h = 360,
  };
  SDL_RenderCopy(m_renderer, m_background, nullptr, &dest_rect);

  SDL_RenderPresent(m_renderer);
}

App::~App() {
  SDL_DestroyRenderer(m_renderer);
  SDL_DestroyWindow(m_window);
  SDL_Quit();
}
void App::Process() {
  bool quit{false};
  while (!quit) {
	SDL_Event event{};

	while (SDL_PollEvent(&event)) {
	  switch (event.type) {
	  case SDL_QUIT:quit = true;
	  default:continue;
	  }
	}

	this->Draw();
  }
}
