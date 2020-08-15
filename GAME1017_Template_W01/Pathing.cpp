#include "Pathing.h"
#include "EventManager.h"
#include "MathManager.h"

path_node::path_node(int x, int y)
{
	this->x = x;
	this->y = y;
}

path_node::~path_node()
{
	for (unsigned i = 0; i < m_connections.size(); i++)
	{
		delete m_connections[i];
		m_connections[i] = nullptr; // Wrangle your dangle.
	}
	m_connections.clear();
	m_connections.shrink_to_fit();
}

void path_node::Update()
{
	SDL_Rect temp = { x-16, y-16, 32, 32 }; // Made bounding box double the size of the node for easier dragging.
	if (SDL_PointInRect(&EVMA::GetMousePos(), &temp))
	{
		if (EVMA::MouseHeld(1))
		{
			x = EVMA::GetMousePos().x;
			y = EVMA::GetMousePos().y;
		}
	}
}

void path_node::AddConnection(PathConnection* c)
{
	m_connections.push_back(c);
}

std::vector<PathConnection*>& path_node::GetConnections()
{
	return m_connections;
}

PathConnection::PathConnection(path_node* f, path_node* t, double cost) : m_cost(cost), m_pFromNode(f), m_pToNode(t) {}
