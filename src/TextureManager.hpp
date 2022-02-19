//
// Created by cytek on 2/17/22.
//

#ifndef SPACEMED_SRC_TEXTUREMANAGER_HPP_
#define SPACEMED_SRC_TEXTUREMANAGER_HPP_

#include <map>
#include <string>

#include "SDL.h"

class TextureManager {
public:
  explicit TextureManager(SDL_Renderer *renderer) : m_renderer{renderer} {}
  ~TextureManager();

  SDL_Texture *LoadTexture(const std::string &filename);
  SDL_Texture *GetTexture(const std::string &key);
  void LoadFromDirectory(const std::string &folder);

private:
  std::map<std::string, SDL_Texture *> m_tex_map;
  SDL_Renderer *m_renderer;
};

#endif // SPACEMED_SRC_TEXTUREMANAGER_HPP_
