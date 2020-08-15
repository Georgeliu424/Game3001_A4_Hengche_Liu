#pragma once
#ifndef _TEXTUREMANAGER_H_
#define _TEXTUREMANAGER_H_

#include <map>
#include <string>


#include "../SDL/SDL2/include/SDL_render.h"

class TextureManager
{
public: // Public methods.
	static void Init();
	static SDL_Texture* IMG_LoadTexture(SDL_Renderer* get_renderer, const char* path);
	static void RegisterTexture(const char* path, const std::string key);
	static SDL_Texture* GetTexture(const std::string key);
	static void Quit();

private: // Private properties.
	static std::map<std::string, SDL_Texture*> s_textures;

private: // Private methods.
	TextureManager();
};

typedef TextureManager TEMA;

#endif