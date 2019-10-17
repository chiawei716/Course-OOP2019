// Copyright © 2019 趙珈葦. All Rights Reserved.
// 系級: 機械109
// 學號: E14056431

#include "HW02.h"

/*class Point*/

// <Constructor> Default (0, 0)
Point::Point() 
{
	x = 0;
	y = 0;
}

// <Constructor> Custom x & y
Point::Point(float x, float y)
{
	this->x = x;
	this->y = y;
}

Point::~Point()
{
}

// Set data
void Point::Set_data(float x, float y)
{
	this->x = x;
	this->y = y;
}

// Operator[]
float Point::operator[](int index)const
{
	if (index == 0) return x;
	else if (index == 1) return y;
	return -1;
}

// Operator>>
std::istream& operator>>(std::istream& in, Point& pt)
{
	float x, y;
	in >> x >> y;
	pt.Set_data(x, y);
	return in;
}

// Operator<<
std::ostream& operator<<(std::ostream& out, const Point& pt)
{
	out << std::fixed << std::setprecision(3) << "("  << pt[0] << ", " << pt[1] << ")";
	return out;
}



/*class QuadtreeNode*/

// <Constructor> with three parameter
QuadtreeNode::QuadtreeNode(const Point& data, const Point& separate_point, const float size)
	: separate_point(separate_point), size(size)
{
	for (int i = 0; i < 4; i++)
		this->nextNode[i] = nullptr;
	this->data = new Point(data);
}

// <Constructor> tree copy
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

// Delete the whole tree
QuadtreeNode::~QuadtreeNode()
{
	if(this->data != nullptr)
		delete this->data;
	for (int i = 0; i < 4; i++)
		if (this->nextNode[i] != nullptr)
			delete this->nextNode[i];
}

// Insert a point to the right position
void QuadtreeNode::InsertPoint(const Point& pt)
{
	// If the node is the end of a branch, copy itself downward
	if (this->ifLeaf()) {
		this->nextNode[this->getQuadrant(*(this->data))] = new QuadtreeNode(
			*(this->data),
			this->nextSeparatePt(this->getQuadrant(*(this->data))),
			(this->size) / 2
		);
		delete this->data;
		this->data = nullptr;
	}

	// Decide where to insert the next point
	int nextQuad = this->getQuadrant(pt);

	// If next node is already built, pass it down
	if (this->nextNode[nextQuad] != nullptr)
		this->nextNode[nextQuad]->InsertPoint(pt);
	// if not, insert directly
	else {
		this->nextNode[nextQuad] = new QuadtreeNode(
			pt,
			nextSeparatePt(nextQuad),
			this->size / 2
		);
		return;
	}
	return;
}

// Find the closest point by tree
Point QuadtreeNode::findClosestPoint(const Point& pt)const
{
	// Decide which quadrant we need to look into
	int next = getQuadrant(pt);

	// If there's no closer point, return current point
	if (this->nextNode[next] == nullptr)
		if (this->data != nullptr)
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

// Get position of next separate point
Point QuadtreeNode::nextSeparatePt(int quadrant)
{
	Point result;
	switch (quadrant)
	{
	case 0:
		result.Set_data(
			this->separate_point[0] + this->size / 4.0f, 
			this->separate_point[1] + this->size / 4.0f
		);
		break;
	case 1:
		result.Set_data(
			this->separate_point[0] - this->size / 4.0f, 
			this->separate_point[1] + this->size / 4.0f
		);
		break;
	case 2:
		result.Set_data(
			this->separate_point[0] - this->size / 4.0f, 
			this->separate_point[1] - this->size / 4.0f
		);
		break;
	case 3:
		result.Set_data(
			this->separate_point[0] + this->size / 4.0f, 
			this->separate_point[1] - this->size / 4.0f
		);
		break;
	default:
		break;
	}
	return result;
}

// Get which quadrant a point belongs to
int QuadtreeNode::getQuadrant(const Point& pt)const
{
	if (this->separate_point[0] >= pt[0]) 
	{
		if (this->separate_point[1] <= pt[1])
			return 1;
		else
			return 2;
	}
	else
	{
		if (this->separate_point[1] <= pt[1])
			return 0;
		else
			return 3;
	}
}

// Check if a node has no child
bool QuadtreeNode::ifLeaf()
{
	for (int i = 0; i < 4; i++)
		if (this->nextNode[i] != nullptr)
			return false;
	return true;
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