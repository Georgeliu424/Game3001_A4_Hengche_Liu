#pragma once
#ifndef _PATHING_H_
#define _PATHING_H_
#include <vector>

#include "../SDL/SDL2/include/SDL_rect.h"

class PathConnection; // Forward declaration required.

class path_node : public SDL_Point // Because why not?
{
public:
	path_node(int x, int y);
	~path_node();
	void Update();
	void AddConnection(PathConnection* c);
	std::vector<PathConnection*>& GetConnections();
	SDL_Point Pt() { return { x, y }; }
	double H() { return m_h; } // Getter.
	void SetH(double h) { m_h = h; } // Setter.
private:
	double m_h; // Heuristic cost for node.
	std::vector<PathConnection*> m_connections;
};

class PathConnection
{
public:
	PathConnection(path_node* f, path_node* t, double cost = 1.0);
	~PathConnection() {}
	double GetCost() { return m_cost; }
	void SetCost(double cost) { m_cost = cost; }
	path_node* GetFromNode() { return m_pFromNode; }
	path_node* GetToNode() { return m_pToNode; }
private:
	double m_cost;
	path_node *m_pFromNode, *m_pToNode;
};

struct NodeRecord
{ // Everything public by default.
	NodeRecord(path_node* n = nullptr) :m_node(n), m_connection(nullptr), m_fromRecord(nullptr), m_costSoFar(0.0), m_totalCost(0.0){	}
	path_node* m_node;
	PathConnection* m_connection;
	NodeRecord* m_fromRecord;
	double m_costSoFar;
	double m_totalCost;
};
#endif
