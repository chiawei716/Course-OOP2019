// Copyright © 2019 趙珈葦. All Rights Reserved.
// 系級: 機械109
// 學號: E14056431

#ifndef HW02_H
#define HW02_H

#include <iostream>
#include <iomanip>

class Point
{
private:	//#1
	float x;
	float y;

public:
	Point();				//#2 <Constructor> Default (0, 0)
	Point(float, float);	//#3 <Constructor> Custom x & y
	~Point();	//#4

	void Set_data(float, float);	//#5 Set data
	float operator[](int)const;		//#6 Operator[]
	friend std::istream& operator>>(std::istream&, Point&);			//#7 Operator>>
	friend std::ostream& operator<<(std::ostream&, const Point&);	//#8 Operator<<
};

class QuadtreeNode
{
private:
	const Point* data;			//#9
	QuadtreeNode* nextNode[4];	//#10
	const Point separate_point;	//#11
	const float size;			//#12

public:
	//#13 To ban the default constructor, overload it and not declare one with no parameter

	QuadtreeNode(const Point&, const Point&, const float);	//#14 <Constructor> with three parameter
	QuadtreeNode(const QuadtreeNode&);						//#15 <Constructor> tree copy
	~QuadtreeNode();	//#16 Delete the whole tree

	void InsertPoint(const Point&);				//#17 Insert a point to the right position
	Point findClosestPoint(const Point&)const;	//#18 Find the closest point by tree

	/* Tools */
	Point nextSeparatePt(int);		// Get position of next separate point
	int getQuadrant(const Point&)const;	// Get which quadrant a point belongs to
	bool ifLeaf();				// Check if a node has no child
	bool ifData()const;

	/* Get functions */
	Point getSeparatePt()const;
	float getSize()const;
	Point getData()const;
	QuadtreeNode* getNode(int)const;
};

#endif // !HW02_H
