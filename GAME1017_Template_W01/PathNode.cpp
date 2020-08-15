#include "PathNode.h"

#include "CollisionManager.h"

PathNode::PathNode(int x, int y, int w, int h) : m_bLOS(false)
{
	m_rDst.x = x;
	m_rDst.y = y;
	m_rDst.w = w;
	m_rDst.h = h;
}
PathNode::~PathNode()
= default;

void PathNode::draw()
{
}

void PathNode::update()
{

}

void PathNode::clean()
{
}

void PathNode::setLOS(const bool LOS)
{
	m_bLOS = LOS;
}

bool PathNode::getLOS() const
{
	return m_bLOS;
}