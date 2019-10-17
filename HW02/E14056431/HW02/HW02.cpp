// Copyright © 2019 趙珈葦. All Rights Reserved.
// 系級: 機械109
// 學號: E14056431

#include "HW02.h"

Point::Point() 
{
	x = 0;
	y = 0;
}

Point::Point(float x, float y)
{
	this->x = x;
	this->y = y;
}

Point::~Point()
{
}

void Point::Set_data(float x, float y)
{
	this->x = x;
	this->y = y;
}

float Point::operator[](int index)const
{
	if (index == 0) return x;
	else if (index == 1) return y;
	return -1;
}

std::istream& operator>>(std::istream& in, Point& pt)
{
	float x, y;
	in >> x >> y;
	pt.Set_data(x, y);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Point& pt)
{
	out << std::fixed << std::setprecision(3) << "("  << pt[0] << ", " << pt[1] << ")";
	return out;
}


/*class QuadtreeNode*/
QuadtreeNode::QuadtreeNode(const Point& data, const Point& separate_point, const float size)
	: separate_point(separate_point), size(size)
{
	for (int i = 0; i < 4; i++)
		this->nextNode[i] = nullptr;
	this->data = new Point(data);
}

QuadtreeNode::QuadtreeNode(const QuadtreeNode& tree) : separate_point(tree.getSeparatePt()), size(tree.getSize())
{
	if (tree.ifData())
		this->data = new Point(tree.getData());
	else
		this->data = nullptr;

	for (int i = 0; i < 4; i++)
		if (tree.getNode(i))
			this->nextNode[i] = new QuadtreeNode(*tree.nextNode[i]);
		else
			this->nextNode[i] = nullptr;
}

QuadtreeNode::~QuadtreeNode()
{
	if(this->data != nullptr)
		delete this->data;
	for (int i = 0; i < 4; i++)
		if (this->nextNode[i] != nullptr)
			delete this->nextNode[i];
}

void QuadtreeNode::InsertPoint(const Point& pt)
{
	// If the node is the end of a branch, copy itself downward
	if (ifLeaf(this)) {
		this->nextNode[getQuadrant(*(this->data), this->separate_point)] = new QuadtreeNode(
			*(this->data),
			nextSeparatePt(this->separate_point, this->size, getQuadrant(*(this->data), this->separate_point)),
			(this->size) / 2
		);
		delete this->data;
		this->data = nullptr;
	}

	// Decide where to insert the next point
	int nextQuad = getQuadrant(pt, this->separate_point);

	// If next node is already built, pass it down
	if (this->nextNode[nextQuad] != nullptr)
		this->nextNode[nextQuad]->InsertPoint(pt);
	// if not, insert directly
	else {
		this->nextNode[nextQuad] = new QuadtreeNode(
			pt,
			nextSeparatePt(this->separate_point, this->size, nextQuad),
			this->size / 2
		);
		return;
	}
	return;
}

// Get position of next separate point
Point QuadtreeNode::nextSeparatePt(const Point& pt, float size, int quadrant)
{
	Point result;
	switch (quadrant)
	{
	case 0:
		result.Set_data(pt[0] + size / 4.0f, pt[1] + size / 4.0f);
		break;
	case 1:
		result.Set_data(pt[0] - size / 4.0f, pt[1] + size / 4.0f);
		break;
	case 2:
		result.Set_data(pt[0] - size / 4.0f, pt[1] - size / 4.0f);
		break;
	case 3:
		result.Set_data(pt[0] + size / 4.0f, pt[1] - size / 4.0f);
		break;
	default:
		break;
	}
	return result;
}

// Get which quadrant a point belongs to
int QuadtreeNode::getQuadrant(const Point& pt, const Point& spt)const
{
	if (spt[0] >= pt[0]) 
	{
		if (spt[1] <= pt[1])
			return 1;
		else
			return 2;
	}
	else
	{
		if (spt[1] <= pt[1])
			return 0;
		else
			return 3;
	}
}

// Check if a node has no child
bool QuadtreeNode::ifLeaf(const QuadtreeNode* node)
{
	for (int i = 0; i < 4; i++)
		if (node->nextNode[i] != nullptr)
			return false;
	return true;
}

// Find the closest point by tree
Point QuadtreeNode::findClosestPoint(const Point& pt)const 
{

	// Decide which quadrant we need to look into
	int next = getQuadrant(pt, this->separate_point);
	
	// If there's no closer point, return current point
	if (this->nextNode[next] == nullptr)
		if(this->data != nullptr)
			return *(this->data);
		else
		{
			for (int i = 0; i < 3; i++)
			{
				next++;
				if (next > 3) next = 0;
				if (this->nextNode[next] != nullptr)
					return this->nextNode[next]->findClosestPoint(pt);
			}
		}

	// Or pass it down
	else
		return this->nextNode[next]->findClosestPoint(pt);
}

Point QuadtreeNode::getSeparatePt()const
{
	return this->separate_point;
}

float QuadtreeNode::getSize()const
{
	return this->size;
}

bool QuadtreeNode::ifData()const
{
	if (this->data == nullptr)
		return false;
	else
		return true;
}

Point QuadtreeNode::getData()const
{
	return *this->data;
}

QuadtreeNode* QuadtreeNode::getNode(int quad)const
{
	return this->nextNode[quad];
}