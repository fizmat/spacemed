//
// Created by cytek on 2/17/22.
//

#include "TextureManager.hpp"
#include "SDL_image.h"
#include <filesystem>

SDL_Texture *TextureManager::LoadTexture(const std::string &filename) {
  auto texture = IMG_LoadTexture(m_renderer, filename.c_str());
  auto[kv_pair, success] = m_tex_map.insert_or_assign(filename, texture);

  if (success) {
	return kv_pair->second;
  }

  return {};
}

TextureManager::~TextureManager() {
  for (auto[_, value] : m_tex_map) {
	SDL_DestroyTexture(value);
  }
}

SDL_Texture *TextureManager::GetTexture(const std::string &key) {
  return m_tex_map[key];
}

void TextureManager::LoadFromDirectory(const std::string &folder) {
  using std::filesystem::recursive_directory_iterator;
  for (const auto &file : recursive_directory_iterator(folder))
	this->LoadTexture(file.path());
}
