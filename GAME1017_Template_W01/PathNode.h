#pragma once
#ifndef __PATH_NODE__
#define __PATH_NODE__

#include "Sprite.h"

class PathNode
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
	bool getLOS() const;;


	void setLOS(bool LOS);
	bool getLOS() const;

private:
	SDL_Rect m_rDst;
	bool m_bLOS;



#endif
