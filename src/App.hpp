//
// Created by cytek on 2/17/22.
//

#ifndef SPACEMED_APP_HPP
#define SPACEMED_APP_HPP

#include "SDL.h"
#include "TextureManager.hpp"

class App
{
public:
  App();
  ~App();

  App(App &app) = delete;  // disable copying
  App(App &&app) = delete; // disable moving

  void Process();

private:
  void Draw();

  SDL_Window *m_window;
  SDL_Renderer *m_renderer;
  TextureManager *m_texture_manager;
  SDL_Texture *m_background;
};

#endif // SPACEMED_APP_HPP
