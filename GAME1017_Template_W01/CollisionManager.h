#pragma once
#ifndef _COLLISIONMANAGER_H_
#define _COLLISIONMANAGER_H_

#include <iostream>
#include "MathManager.h"
#include "Sprite.h"
#include "Tile.h"
#include "PathNode.h"

class CollisionManager
{
public:
	static bool AABBCheck(const SDL_FRect& object1, const SDL_FRect& object2);
	static bool CircleCircleCheck(const SDL_FPoint object1, const SDL_FPoint object2, const double r1, const double r2 = 0.0);
	static bool CircleAABBCheck(const SDL_FPoint object1, const double r, const SDL_FRect& object2);
	static bool LinePointCheck(const SDL_FPoint object1_start, const SDL_FPoint object1_end, const SDL_FPoint object2);
	static bool lineLineCheck(const glm::vec2 line1_start, const glm::vec2 line1_end, const glm::vec2 line2_start, const glm::vec2 line2_end);
	static bool lineRectCheck(const glm::vec2 line1_start, const glm::vec2 line1_end, const glm::vec2 rec_start, const float rect_width, const float rect_height);
	static bool LOSCheck(Sprite* from, Sprite* to, SDL_FRect* rect);
	static bool LOSCheckN(path_node* from, Sprite* to, SDL_FRect* rect);
	static bool PlayerCollision(const SDL_Rect player, const int dX, const int dY);
private:
	CollisionManager() {}
};

typedef CollisionManager COMA;

#endif