// Copyright © 2019 趙珈葦. All Rights Reserved.
// 系級: 機械109
// 學號: E14056431

#include "HW01_02.h"

// Get distance to origin
double MyGeometry::Point::Length()
{
	return sqrt(this->x * this->x + this->y * this->y);
}

// Get position - (a, b)
string MyGeometry::Point::CoutPoint()
{
	char temp[30];
	sprintf_s(temp, "(%.2f, %.2f)", this->x, this->y);
	return temp;
}

// <Custom> Get distance to a linear equation
double MyGeometry::Point::DistanceToLine(double a, double b, double c) 
{
	return abs(a * x + b * y + c) / sqrt(a * a + b * b);
}

// Load points from a file, and store into an array
MyGeometry::Point* MyGeometry::LoadPoint(const char* filename, unsigned int& nPoint)
{
	Point *pts = new Point[20];
	nPoint = 0;

	ifstream inFile(filename, ios::in);
	while (inFile >> pts[nPoint].x >> pts[nPoint].y)
		nPoint++;
	inFile.close();
	return pts;
}

// Get the nearest point to a linear equation
MyGeometry::Point MyGeometry::MinDistance(Point* pts, unsigned int nPoint, double a, double b, double c)
{
	int tempPt = 0;
	double tempDistance = pts[0].DistanceToLine(a, b, c);
	for (int i = 1; i < nPoint; i++) {
		double temp = pts[i].DistanceToLine(a, b, c);
		if (temp < tempDistance)
		{
			tempPt = i;
			tempDistance = temp;
		}
	}
	return pts[tempPt];
}

// Sort by distance to origin
void MyGeometry::SortbyLength(Point* pts, unsigned int nPoint)
{
	// Bubble sort
	for (int i = nPoint - 2; i >= 0; i--)
		for (int j = i; j < nPoint - 1; j++)
			if (pts[j].Length() < pts[j + 1].Length())
				SwapPoint(pts[j], pts[j + 1]);
}

// <Custom> Swap two points in an array
void MyGeometry::SwapPoint(Point& pt1, Point& pt2)
{
	Point temp = pt1;
	pt1 = pt2;
	pt2 = temp;
}

// Write report to file
void MyGeometry::Report(const char* filename, const char* ID, const char* name, unsigned int nPoint, Point nearLine, Point nearOrigin)
{
	ofstream outFile(filename, ios::out);
	outFile << "物件導向程式設計第一次作業\n";
	outFile << ID << " " << name << "\n";
	outFile << "點數目： " << nPoint << "\n";
	outFile << "最接近x+y=1的點： " << nearLine.CoutPoint() << "\n";
	outFile << "與原點距離最近的點： " << nearOrigin.CoutPoint() << " 、距離為： " << nearOrigin.Length();
}