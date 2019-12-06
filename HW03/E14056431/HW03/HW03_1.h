// Copyright © 2019 趙珈葦. All Rights Reserved.
// 系級: 機械109
// 學號: E14056431

#pragma once
#ifndef HW03_1_H
#define HW03_1_H

#include <iomanip>
#include <math.h>

#define PI 3.1415926

// Point
class Point
{
private:
	double x;
	double y;
	double z;

public:
	Point();
	Point(double, double, double);
	~Point();

	void Set_data(double, double, double);
	double operator[](int)const;
	friend std::istream& operator >> (std::istream&, Point&);
	friend std::ostream& operator<<(std::ostream&, const Point&);
};

// IGeometry
class IGeometry
{
protected:
	Point* vertices;

public:
	IGeometry();
	IGeometry(const IGeometry&);
	~IGeometry();

	virtual double Area() = 0;
	virtual double Perimeter() = 0;
	virtual double Volume() = 0;
};

// Pyramid
class Pyramid : public IGeometry
{
public:
	Pyramid() = delete;
	Pyramid(Point, Point, Point, Point);
	Pyramid(const Pyramid&);
	~Pyramid();

	// Override funcitons
	double Area();
	double Perimeter();
	double Volume();

	// Unique functions
	Point Center();
	void operator=(const Pyramid&);

	// Get functions
	Point operator[](int)const;
};

// Cuboid
class Cuboid : public IGeometry
{
public:
	Cuboid() = delete;
	Cuboid(Point, Point, Point, Point, Point, Point, Point, Point);
	Cuboid(const Cuboid&);
	~Cuboid();

	// Override funcitons
	double Area();
	double Perimeter();
	double Volume();

	// Unique functions
	double* SideLength();
	double* SideArea();
	void operator=(const Cuboid&);

	// Get functions
	Point operator[](int)const;
};

// Cylinder
class Cylinder : public IGeometry
{
private:
	Point Top;
	Point Bottom;
	double r;

public:
	Cylinder() = delete;
	Cylinder(Point, Point, double);
	Cylinder(const Cylinder&);
	~Cylinder();

	// Override funcitons
	double Area();
	double Perimeter();
	double Volume();

	// Unique functions
	double Height();
	double BottomArea();
	double SideArea();
	void operator=(const Cylinder&);

	// Get functions
	Point getTopPoint() const;
	Point getBottomPoint() const;
	double getRadius() const;
};

#endif // !HW03_1_h
