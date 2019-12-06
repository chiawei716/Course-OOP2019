// Copyright © 2019 趙珈葦. All Rights Reserved.
// 系級: 機械109
// 學號: E14056431

#include "HW03_1.h"
#include <time.h>
#include <iostream>
using namespace std;

int main()
{
	srand(time(NULL));
	IGeometry** arr = new IGeometry*[3];

	/* Pyramid */
	// generate data by random
	double pyramid_pt[4][3];
	for (int j = 0; j < 4; ++j)
		for (int i = 0; i < 3; ++i)
			pyramid_pt[j][i] = (double)(rand() % 100);

	// generate one by constructors
	arr[0] = new Pyramid(
		Point(pyramid_pt[0][0], pyramid_pt[0][1], pyramid_pt[0][2]),
		Point(pyramid_pt[1][0], pyramid_pt[1][1], pyramid_pt[1][2]),
		Point(pyramid_pt[2][0], pyramid_pt[2][1], pyramid_pt[2][2]),
		Point(pyramid_pt[3][0], pyramid_pt[3][1], pyramid_pt[3][2])
	);

	// generate one by copy constructors
	Pyramid *pyramid_constructor = new Pyramid(*((Pyramid*)arr[0]));

	// generate one by constructors, then change by assignment operator
	Pyramid pyramid_assignment(
		Point(0, 0, 0),
		Point(0, 0, 0),
		Point(0, 0, 0),
		Point(0, 0, 0)
	);
	pyramid_assignment = *(Pyramid*)arr[0];

	// Test
	cout << "/* Pyramid */\n";

	// Constructor
	cout << "// constructor\n";
	cout << "Vertices:\n";
	for (int i = 0; i < 4; ++i) cout << (*(Pyramid*)arr[0])[i] << " ";
	cout << endl;
	cout << "Center: " << ((Pyramid*)arr[0])->Center() << endl;
	cout << "Area:        " << std::fixed << std::setprecision(3) << arr[0]->Area() << endl;
	cout << "Perimeter:   " << std::fixed << std::setprecision(3) << arr[0]->Perimeter() << endl;
	cout << "Volume:      " << std::fixed << std::setprecision(3) << arr[0]->Volume() << endl << endl;

	// Copy Constructor
	cout << "// copy constructor\n";
	cout << "Vertices:\n";
	for (int i = 0; i < 4; ++i) cout << (*pyramid_constructor)[i] << " ";
	cout << endl;
	cout << "Center: " << pyramid_constructor->Center() << endl;
	cout << "Area:        " << std::fixed << std::setprecision(3) << pyramid_constructor->Area() << endl;
	cout << "Perimeter:   " << std::fixed << std::setprecision(3) << pyramid_constructor->Perimeter() << endl;
	cout << "Volume:      " << std::fixed << std::setprecision(3) << pyramid_constructor->Volume() << endl << endl;

	// Assignment Operator
	cout << "// asignment operator\n";
	cout << "Vertices:\n";
	for (int i = 0; i < 4; ++i) cout << pyramid_assignment[i] << " ";
	cout << endl;
	cout << "Center: " << pyramid_assignment.Center() << endl;
	cout << "Area:        " << std::fixed << std::setprecision(3) << pyramid_assignment.Area() << endl;
	cout << "Perimeter:   " << std::fixed << std::setprecision(3) << pyramid_assignment.Perimeter() << endl;
	cout << "Volume:      " << std::fixed << std::setprecision(3) << pyramid_assignment.Volume() << endl << endl;
	delete pyramid_constructor;


	/* Cuboid */

	// generate data by random
	double *temp;
	double sideLength[3];
	for (int i = 0; i < 3; i++)
		sideLength[i] = (double)(rand() % 100);

	// generate one by constructors
	arr[1] = new Cuboid(
		Point(0, 0, 0),
		Point(sideLength[0], 0, 0),
		Point(0, sideLength[1], 0),
		Point(0, 0, sideLength[2]),
		Point(sideLength[0], 0, sideLength[2]),
		Point(sideLength[0], sideLength[1], 0),
		Point(0, sideLength[1], sideLength[2]),
		Point(sideLength[0], sideLength[1], sideLength[2])
	);

	// generate one by copy constructors
	Cuboid *cuboid_constructor = new Cuboid(*((Cuboid*)arr[1]));

	// generate one by constructors, then change by assignment operator
	Cuboid cuboid_assignment(
		Point(0, 0, 0),
		Point(0, 0, 0),
		Point(0, 0, 0),
		Point(0, 0, 0),
		Point(0, 0, 0),
		Point(0, 0, 0),
		Point(0, 0, 0),
		Point(0, 0, 0)
	);
	cuboid_assignment = *(Cuboid*)arr[1];
	
	// Test
	cout << "/* Cuboid */\n";

	// Constructor
	cout << "// constructor\n";
	cout << "Vertices:\n";
	for (int i = 0; i < 8; ++i) 
	{
		cout << (*(Cuboid*)arr[1])[i] << " ";
		if (i % 4 == 3) cout << "\n";
	}
	temp = ((Cuboid*)arr[1])->SideLength();
	cout << "Side Lendth: ";
	for (int i = 0; i < 3; ++i) cout << temp[i] << " ";
	cout << endl;
	delete[] temp;

	temp = ((Cuboid*)arr[1])->SideArea();
	cout << "Side Area:   ";
	for (int i = 0; i < 3; ++i) cout << temp[i] << " ";
	cout << endl;
	delete[] temp;

	cout << "Area:        " << std::fixed << std::setprecision(3) << arr[1]->Area() << endl;
	cout << "Perimeter:   " << std::fixed << std::setprecision(3) << arr[1]->Perimeter() << endl;
	cout << "Volume:      " << std::fixed << std::setprecision(3) << arr[1]->Volume() << endl << endl;

	// Copy Constructor
	cout << "// copy constructor\n";
	cout << "Vertices:\n";
	for (int i = 0; i < 8; ++i)
	{
		cout << (*cuboid_constructor)[i] << " ";
		if (i % 4 == 3) cout << "\n";
	}
	temp = cuboid_constructor->SideLength();
	cout << "Side Lendth: ";
	for (int i = 0; i < 3; ++i) cout << temp[i] << " ";
	cout << endl;
	delete[] temp;

	temp = cuboid_constructor->SideArea();
	cout << "Side Area:   ";
	for (int i = 0; i < 3; ++i) cout << temp[i] << " ";
	cout << endl;
	delete[] temp;

	cout << "Area:        " << std::fixed << std::setprecision(3) << cuboid_constructor->Area() << endl;
	cout << "Perimeter:   " << std::fixed << std::setprecision(3) << cuboid_constructor->Perimeter() << endl;
	cout << "Volume:      " << std::fixed << std::setprecision(3) << cuboid_constructor->Volume() << endl << endl;

	// Assignment Operator
	cout << "// asignment operator\n";
	cout << "Vertices:\n";
	for (int i = 0; i < 8; ++i)
	{
		cout << cuboid_assignment[i] << " ";
		if (i % 4 == 3) cout << "\n";
	}
	temp = cuboid_assignment.SideLength();
	cout << "Side Lendth: ";
	for (int i = 0; i < 3; ++i) cout << temp[i] << " ";
	cout << endl;
	delete[] temp;

	temp = cuboid_assignment.SideArea();
	cout << "Side Area:   ";
	for (int i = 0; i < 3; ++i) cout << temp[i] << " ";
	cout << endl;
	delete[] temp;

	cout << "Area:        " << std::fixed << std::setprecision(3) << cuboid_assignment.Area() << endl;
	cout << "Perimeter:   " << std::fixed << std::setprecision(3) << cuboid_assignment.Perimeter() << endl;
	cout << "Volume:      " << std::fixed << std::setprecision(3) << cuboid_assignment.Volume() << endl << endl;
	delete cuboid_constructor;

	/* Cylinder */

	// generate data by random
	double cylinder_points[2][3];
	double cylinder_radius = (double)(rand() % 100);
	for (int i = 0; i < 3; ++i)
	{
		cylinder_points[0][i] = (double)(rand() % 100);
		cylinder_points[1][i] = (double)(rand() % 100);
	}

	// generate one by constructors
	arr[2] = new Cylinder(
		Point(cylinder_points[0][0], cylinder_points[0][1], cylinder_points[0][2]),
		Point(cylinder_points[1][0], cylinder_points[1][1], cylinder_points[1][1]),
		cylinder_radius
	);

	// generate one by copy constructors
	Cylinder *cylinder_constructor = new Cylinder(*((Cylinder*)arr[2]));

	// generate one by constructors, then change by assignment operator
	Cylinder cylinder_assignment(Point(0, 0, 0), Point(0, 0, 0), 0);
	cylinder_assignment = *((Cylinder*)arr[2]);

	// Test
	cout << "/* Cylinder */\n";
	// Constructor
	cout << "// constructor\n";
	cout << "Top:         " << ((Cylinder*)arr[2])->getTopPoint() << endl;
	cout << "Bottom:      " << ((Cylinder*)arr[2])->getBottomPoint() << endl;
	cout << "Radius:      " << std::fixed << std::setprecision(3) << ((Cylinder*)arr[2])->getRadius() << endl;
	cout << "Height:      " << std::fixed << std::setprecision(3) << ((Cylinder*)arr[2])->Height() << endl;
	cout << "Bottom Area: " << std::fixed << std::setprecision(3) << ((Cylinder*)arr[2])->BottomArea() << endl;
	cout << "Side Area:   " << std::fixed << std::setprecision(3) << ((Cylinder*)arr[2])->SideArea() << endl;
	cout << "Area:        " << std::fixed << std::setprecision(3) << arr[2]->Area() << endl;
	cout << "Perimeter:   " << std::fixed << std::setprecision(3) << arr[2]->Perimeter() << endl;
	cout << "Volume:      " << std::fixed << std::setprecision(3) << arr[2]->Volume() << endl << endl;
	// Copy Constructor
	cout << "// copy constructor\n";
	cout << "Top:         " << cylinder_constructor->getTopPoint() << endl;
	cout << "Bottom:      " << cylinder_constructor->getBottomPoint() << endl;
	cout << "Radius:      " << std::fixed << std::setprecision(3) << cylinder_constructor->getRadius() << endl;
	cout << "Height:      " << std::fixed << std::setprecision(3) << cylinder_constructor->Height() << endl;
	cout << "Bottom Area: " << std::fixed << std::setprecision(3) << cylinder_constructor->BottomArea() << endl;
	cout << "Side Area:   " << std::fixed << std::setprecision(3) << cylinder_constructor->SideArea() << endl;
	cout << "Area:        " << std::fixed << std::setprecision(3) << cylinder_constructor->Area() << endl;
	cout << "Perimeter:   " << std::fixed << std::setprecision(3) << cylinder_constructor->Perimeter() << endl;
	cout << "Volume:      " << std::fixed << std::setprecision(3) << cylinder_constructor->Volume() << endl << endl;
	// Assignment Operator
	cout << "// assignment operator\n";
	cout << "Top:         " << cylinder_assignment.getTopPoint() << endl;
	cout << "Bottom:      " << cylinder_assignment.getBottomPoint() << endl;
	cout << "Radius:      " << std::fixed << std::setprecision(3) << cylinder_assignment.getRadius() << endl;
	cout << "Height:      " << std::fixed << std::setprecision(3) << cylinder_assignment.Height() << endl;
	cout << "Bottom Area: " << std::fixed << std::setprecision(3) << cylinder_assignment.BottomArea() << endl;
	cout << "Side Area:   " << std::fixed << std::setprecision(3) << cylinder_assignment.SideArea() << endl;
	cout << "Area:        " << std::fixed << std::setprecision(3) << cylinder_assignment.Area() << endl;
	cout << "Perimeter:   " << std::fixed << std::setprecision(3) << cylinder_assignment.Perimeter() << endl;
	cout << "Volume:      " << std::fixed << std::setprecision(3) << cylinder_assignment.Volume() << endl << endl;
	delete cylinder_constructor;

	delete arr[0];
	delete arr[1];
	delete arr[2];
	delete[] arr;

	system("pause");
}