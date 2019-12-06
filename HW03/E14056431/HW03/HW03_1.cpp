// Copyright © 2019 趙珈葦. All Rights Reserved.
// 系級: 機械109
// 學號: E14056431

#include "HW03_1.h"
#include <iostream>
/* Class Point */

// <Constructor> Default (0, 0, 0)
Point::Point()
{
	x = 0;
	y = 0;
	z = 0;
}

// <Constructor> Custom x & y & z
Point::Point(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Point::~Point()
{
}

// Set data
void Point::Set_data(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

// Operator[]
double Point::operator[](int index)const
{
	if (index == 0) return x;
	else if (index == 1) return y;
	else if (index == 2) return z;
	return -1;
}

// Operator>>
std::istream& operator >> (std::istream& in, Point& pt)
{
	double x, y, z;
	in >> x >> y >> z;
	pt.Set_data(x, y, z);
	return in;
}

// Operator<<
std::ostream& operator<<(std::ostream& out, const Point& pt)
{
	out << std::fixed << std::setprecision(3) << "(" << pt[0] << ", " << pt[1] << ", " << pt[2] << ")";
	return out;
}


/* Class IGeometry */

// <Constructor> nothing
IGeometry::IGeometry() { this->vertices = nullptr; }

// <Constructor> Copy none
IGeometry::IGeometry(const IGeometry& igeometry) {  }

// Destructor
IGeometry::~IGeometry()
{
	std::cout << "IGeometry destructed.\n\n";
	if(this->vertices != nullptr)
		delete[] this->vertices;
	this->vertices = nullptr;
}


/* Class Pyramid */

// <Constructor> four parameters
Pyramid::Pyramid(Point p1, Point p2, Point p3, Point p4)
{
	this->vertices = new Point[4];
	this->vertices[0] = p1;
	this->vertices[1] = p2;
	this->vertices[2] = p3;
	this->vertices[3] = p4;
}

// <Constructor> copy
Pyramid::Pyramid(const Pyramid& pyramid)
{
	this->vertices = new Point[4];
	for (int i = 0; i < 4; ++i)
		this->vertices[i] = pyramid[i];
}

// Destructor
Pyramid::~Pyramid()
{
	std::cout << "Pyramid destructed.\n";
	if (this->vertices != nullptr)
		delete[] this->vertices;
	this->vertices = nullptr;
}

// <Operator> assingment = 
void Pyramid::operator=(const Pyramid& pyramid)
{
	for (int i = 0; i < 4; i++)
		this->vertices[i] = pyramid[i];
}

// <Operator> assingment []
Point Pyramid::operator[](int index) const
{
	return this->vertices[index];
}

// Get center
Point Pyramid::Center()
{
	double vec[3] = { 0, 0, 0 };
	for (int i = 1; i < 4; i++) {
		vec[0] += (this->vertices[i][0] - this->vertices[0][0]) / 4;
		vec[1] += (this->vertices[i][1] - this->vertices[0][1]) / 4;
		vec[2] += (this->vertices[i][2] - this->vertices[0][2]) / 4;
	}
	return Point(vec[0], vec[1], vec[2]);
}

// Get area
double Pyramid::Area()
{
	double len[3];
	double result = 0;
	for (int i = 1; i < 4; ++i)
	{
		for (int j = 0; j < 3; ++j)
			len[j] = sqrt(pow(this->vertices[(j % 3 + i) % 4][0] - this->vertices[((j + 1) % 3 + i) % 4][0], 2) + pow(this->vertices[(j % 3 + i) % 4][1] - this->vertices[((j + 1) % 3 + i) % 4][1], 2) + pow(this->vertices[(j % 3 + i) % 4][2] - this->vertices[((j + 1) % 3 + i) % 4][2], 2));
		double s = (len[0] + len[1] + len[2]) / 2;
		result += sqrt(s*(s - len[0])*(s - len[1])*(s - len[2]));
	}
	return result;
}

// Get perimeter
double Pyramid::Perimeter()
{
	double result = 0;
	for (int i = 1; i < 4; i++)
		result += sqrt(pow(this->vertices[i][0] - this->vertices[0][0], 2) + pow(this->vertices[i][1] - this->vertices[0][1], 2) + pow(this->vertices[i][2] - this->vertices[0][2], 2));
	for (int i = 0; i < 3; i++)
		result += sqrt(pow(this->vertices[i % 3 + 1][0] - this->vertices[(i + 1) % 3 + 1][0], 2) + pow(this->vertices[i % 3 + 1][1] - this->vertices[(i + 1) % 3 + 1][1], 2) + pow(this->vertices[i % 3 + 1][2] - this->vertices[(i + 1) % 3 + 1][2], 2));
	return result;
}

// Get volume
double Pyramid::Volume()
{
	double sideLength[6];
	sideLength[3] = sqrt(pow(this->vertices[0][0] - this->vertices[1][0], 2) + pow(this->vertices[0][1] - this->vertices[1][1], 2) + pow(this->vertices[0][2] - this->vertices[1][2], 2));
	sideLength[4] = sqrt(pow(this->vertices[0][0] - this->vertices[2][0], 2) + pow(this->vertices[0][1] - this->vertices[2][1], 2) + pow(this->vertices[0][2] - this->vertices[2][2], 2));
	sideLength[5] = sqrt(pow(this->vertices[0][0] - this->vertices[3][0], 2) + pow(this->vertices[0][1] - this->vertices[3][1], 2) + pow(this->vertices[0][2] - this->vertices[3][2], 2));
	sideLength[2] = sqrt(pow(this->vertices[1][0] - this->vertices[2][0], 2) + pow(this->vertices[1][1] - this->vertices[2][1], 2) + pow(this->vertices[1][2] - this->vertices[2][2], 2));
	sideLength[1] = sqrt(pow(this->vertices[1][0] - this->vertices[3][0], 2) + pow(this->vertices[1][1] - this->vertices[3][1], 2) + pow(this->vertices[1][2] - this->vertices[3][2], 2));
	sideLength[0] = sqrt(pow(this->vertices[2][0] - this->vertices[3][0], 2) + pow(this->vertices[2][1] - this->vertices[3][1], 2) + pow(this->vertices[2][2] - this->vertices[3][2], 2));

	double params[6];
	params[0] = (sideLength[5]- sideLength[0]+ sideLength[4]) * (sideLength[5] + sideLength[0] + sideLength[4]);
	params[1] = (sideLength[0] - sideLength[4] + sideLength[5]) * (sideLength[4] - sideLength[5] + sideLength[0]);
	params[2] = (sideLength[3] - sideLength[1] + sideLength[5]) * (sideLength[1] + sideLength[3] + sideLength[5]);
	params[3] = (sideLength[1] - sideLength[5] + sideLength[3]) * (sideLength[5] - sideLength[3] + sideLength[1]);
	params[4] = (sideLength[4] - sideLength[2] + sideLength[3]) * (sideLength[2] + sideLength[3] + sideLength[4]);
	params[5] = (sideLength[2] - sideLength[3] + sideLength[4]) * (sideLength[3] - sideLength[4] + sideLength[2]);

	double a = sqrt(params[1] * params[2] * params[4]);
	double b = sqrt(params[0] * params[3] * params[4]); 
	double c = sqrt(params[0] * params[2] * params[5]); 
	double d = sqrt(params[1] * params[3] * params[5]);

	double result = 1;
	result *= (-a + b + c + d);
	result *= (a - b + c + d);
	result *= (a + b - c + d);
	result *= (a + b + c - d);
	result = sqrt(result);
	result /= 192 * sideLength[3] * sideLength[4] * sideLength[5];
	
	return result;
}

/* Class Cuboid */

// <Constructor> eight parameters
Cuboid::Cuboid(Point p1, Point p2, Point p3, Point p4, Point p5, Point p6, Point p7, Point p8)
{
	this->vertices = new Point[8];
	this->vertices[0] = p1;
	this->vertices[1] = p2;
	this->vertices[2] = p3;
	this->vertices[3] = p4;
	this->vertices[4] = p5;
	this->vertices[5] = p6;
	this->vertices[6] = p7;
	this->vertices[7] = p8;
}

// <Constructor> copy
Cuboid::Cuboid(const Cuboid& cuboid)
{
	this->vertices = new Point[8];
	for (int i = 0; i < 8; ++i)
		this->vertices[i] = cuboid[i];
}

// Destructor
Cuboid::~Cuboid()
{
	std::cout << "Cuboid destructed.\n";
	if (this->vertices != nullptr)
		 delete[] this->vertices;
	this->vertices = nullptr;
}

// <Operator> assingment = 
void Cuboid::operator=(const Cuboid& cuboid)
{
	for (int i = 0; i < 8; i++)
		this->vertices[i] = cuboid[i];
}

// <Operator> assingment []
Point Cuboid::operator[](int index) const
{
	return this->vertices[index];
}

// Get side length
double* Cuboid::SideLength()
{
	double *result = new double[3];
	int progress = 0;

	// choose any point, find three vectors started from it, and orthogonal with two other vectors
	int count;
	for (int i = 1; i < 7; i++)
	{
		count = 0;
		for (int j = 1; j < 7; j++)
		{
			if (progress == 3) break;
			if (i != j)
			{
				double sum = 0;
				sum += (this->vertices[i][0] - this->vertices[0][0]) * (this->vertices[j][0] - this->vertices[0][0]);
				sum += (this->vertices[i][1] - this->vertices[0][1]) * (this->vertices[j][0] - this->vertices[0][1]);
				sum += (this->vertices[i][2] - this->vertices[0][2]) * (this->vertices[j][0] - this->vertices[0][2]);
				if (sum > -0.0001 && sum < 0.0001)
					count++;
				if (count == 2) {
					result[progress] = sqrt(pow(this->vertices[i][0] - this->vertices[0][0], 2) + pow(this->vertices[i][1] - this->vertices[0][1], 2) + pow(this->vertices[i][2] - this->vertices[0][2], 2));
					progress++;
					break;
				}
			}
		}
	}
	return result;
}

// Get side area
double* Cuboid::SideArea()
{
	double *result = new double[3];
	double *len = this->SideLength();
	result[0] = len[0] * len[1];
	result[1] = len[1] * len[2];
	result[2] = len[2] * len[0];
	delete len;
	
	return result;
}

// Get area
double Cuboid::Area()
{
	double* sideArea = this->SideArea();
	double result = 2 * (sideArea[0] + sideArea[1] + sideArea[2]);
	delete sideArea;
	return result;
}

// Get perimeter
double Cuboid::Perimeter()
{
	double* sideLength = this->SideLength();
	double result = 4 * (sideLength[0] + sideLength[1] + sideLength[2]);
	delete sideLength;
	return result;
}

// Get Volume
double Cuboid::Volume()
{
	double* sideLength = this->SideLength();
	double result = sideLength[0] * sideLength[1] * sideLength[2];
	delete sideLength;
	return result;
}



/* Class Cylinder */

// <Constructor> three parameters
Cylinder::Cylinder(Point top, Point bottom, double r)
{
	this->vertices = nullptr;
	this->Top = top;
	this->Bottom = bottom;
	this->r = r;
}

// <Constructor> copy
Cylinder::Cylinder(const Cylinder& cylinder)
{
	this->vertices = nullptr;
	this->Top = cylinder.getTopPoint();
	this->Bottom = cylinder.getBottomPoint();
	this->r = cylinder.getRadius();
}

// Destructor
Cylinder::~Cylinder() 
{ 
	std::cout << "Cylinder destructed.\n";
}

// <Operator> assingment = 
void Cylinder::operator=(const Cylinder& cylinder)
{
	this->vertices = nullptr;
	this->Top = cylinder.getTopPoint();
	this->Bottom = cylinder.getBottomPoint();
	this->r = cylinder.getRadius();
}

// Get functions
Point Cylinder::getTopPoint() const { return this->Top; }
Point Cylinder::getBottomPoint() const { return this->Bottom; }
double Cylinder::getRadius() const { return this->r; }

// Get height
double Cylinder::Height()
{
	return sqrt(pow(this->Top[0] - this->Bottom[0], 2) + pow(this->Top[1] - this->Bottom[1], 2) + pow(this->Top[2] - this->Bottom[2], 2));
}

// Get bottom area
double Cylinder::BottomArea()
{
	return this->r * this->r * PI;
}

// Get side area
double Cylinder::SideArea()
{
	return 2 * r * PI * this->Height();
}

// Get area
double Cylinder::Area()
{
	return this->BottomArea() * 2 + this->SideArea();
}

// Get perimeter
double Cylinder::Perimeter()
{
	return 2 * 2 * r * PI;
}

// Get Volume
double Cylinder::Volume()
{
	return this->BottomArea() * this->Height();
}

