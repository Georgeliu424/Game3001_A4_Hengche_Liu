#pragma once
#ifndef __PATH_NODE__
#define __PATH_NODE__

#include "Sprite.h"
#include "../SDL/SDL2/include/SDL_rect.h"
#include "../SDL/SDL2/include/glm/vec2.hpp"

class PathNode: 
{
public:
	PathNode(int x, int y, int w, int h);
	~PathNode();

	void Render();
	void Update();
	glm::vec2 GetPos();
	float GetWidth();
	float GetHeight();
	void setLOS(bool LOS);
	bool getLOS() const;


private:
	SDL_Rect m_rDst;
	bool m_bLOS;

};

#endif
