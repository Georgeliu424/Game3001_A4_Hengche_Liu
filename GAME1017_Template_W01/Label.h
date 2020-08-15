#pragma once
#ifndef _LABEL_H_
#define _LABEL_H_


#include <string>
#include "FontManager.h"
#include "../SDL/SDL2/include/SDL_pixels.h"
#include "../SDL/SDL2/include/SDL_rect.h"
#include "../SDL/SDL2/include/SDL_render.h"

class Label
{
public: // Public methods.
	Label(std::string key, const float x, const float y, const char* str, const SDL_Color col = { 255,255,255,255 });
	~Label();
	void Render();
	void SetText(const char* c);
	void SetPos(const float x, const float y);
	void SetColor(const SDL_Color& col);
	void UseFont(std::string key);

private: // Private properties.
	TTF_Font* m_Font;
	SDL_Color m_TextColor;
	SDL_FRect m_rTextRect;
	SDL_Texture* m_pTexture;
	char m_String[256];

};

#endif