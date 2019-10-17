// Copyright © 2019 趙珈葦. All Rights Reserved.
// 系級: 機械109
// 學號: E14056431

#ifndef HW02_H
#define HW02_H

#include <iostream>
#include <iomanip>

class Point
{
private:
	float x;
	float y;

public:
	Point();
	Point(float, float);
	~Point();

	void Set_data(float, float);
	float operator[](int)const;
	friend std::istream& operator>>(std::istream&, Point&);
	friend std::ostream& operator<<(std::ostream&, const Point&);
};

class QuadtreeNode
{
private:
	const Point* data;
	QuadtreeNode* nextNode[4];
	const Point separate_point;
	const float size;

public:
	QuadtreeNode(const Point&, const Point&, const float);
	QuadtreeNode(const QuadtreeNode&);
	~QuadtreeNode();

	void InsertPoint(const Point&);
	Point findClosestPoint(const Point&)const;

	Point nextSeparatePt(const Point&, float, int);
	int getQuadrant(const Point&, const Point&)const;
	bool ifLeaf(const QuadtreeNode* node);

	Point getSeparatePt()const;
	float getSize()const;
	bool ifData()const;
	Point getData()const;
	QuadtreeNode* getNode(int)const;
};

#endif // !HW02_H
