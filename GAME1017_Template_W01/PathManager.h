#pragma once
#ifndef _PATHMANAGER_H_
#define _PATHMANAGER_H_
#include "Pathing.h"
#include <vector>

class PathManager
{
public:
	static void GetShortestPath(path_node* start, path_node* goal);
	static NodeRecord* GetSmallestNode();
	static std::vector<NodeRecord*>& OpenList();
	static std::vector<NodeRecord*>& ClosedList();
	static bool ContainsNode(std::vector<NodeRecord*>& list, path_node* n);
	static NodeRecord* GetNodeRecord(std::vector<NodeRecord*>& list, path_node* n);
	static double HEuclid(const path_node* start, const path_node* goal);
	static double HManhat(const path_node* start, const path_node* goal);
	static void DrawPath();
private:
	PathManager() {}
private:
	static std::vector<NodeRecord*> s_open;
	static std::vector<NodeRecord*> s_closed;
	static std::vector<PathConnection*> s_path;
};

typedef PathManager PAMA;

#endif
