// Copyright © 2019 趙珈葦. All Rights Reserved.
// 系級: 機械109
// 學號: E14056431

#ifndef HW01_02
#define HW01_02

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

namespace MyGeometry
{
	struct Point
	{
		float x;
		float y;
		double Length();
		string CoutPoint();
		double DistanceToLine(double, double, double);
	};

	Point* LoadPoint(const char*, unsigned int&);
	Point MinDistance(Point*, unsigned int, double, double, double);
	void SortbyLength(Point*, unsigned int);
	void Report(const char*, const char*, const char*, unsigned int, Point, Point);
	void SwapPoint(Point&, Point&);
}

#endif // !HW01_02

