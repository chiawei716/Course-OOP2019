// Copyright © 2019 趙珈葦. All Rights Reserved.
// 系級: 機械109
// 學號: E14056431

#include "HW02.h"
#include <iostream>
#include <stdio.h>
#include "HW02.h"
using namespace std;

int main()
{
	// Open file
	FILE *in;
	errno_t err;
	const char filename[30] = "Point_HW2.txt";
	if (err = fopen_s(&in, filename, "r+") != 0)
	{
		cerr << "Failed opening file.\n";
		system("pause");
		return 0;
	}
	else
		cout << filename << " opened.\n\n";

	// Read number of points
	int count;
	fscanf_s(in, "Point count : %d\n", &count);
	
	// Read points, and insert into the tree
	float x, y;
	QuadtreeNode* tree1 = nullptr;
	while (true)
	{
		if (feof(in)) break;
		fscanf_s(in, "%f %f\n", &x, &y);
		if (tree1 == nullptr)
			tree1 = new QuadtreeNode(Point(x, y), Point(0.0f, 0.0f), 200);
		else
			tree1->InsertPoint(Point(x, y));
		cout << Point(x, y) << " inserted.\n";
	}
	cout << "\n\n";

	// Point input, including checking if input is valid
	Point input;
	float input_x, input_y;
	cout << "Please enter a point:\nx: ";
	if (!(cin>>input_x))
	{
		cerr << "Invalid input!!\n";
		system("pause");
		return 0;
	}
	cout << "y: ";
	if (!(cin >> input_y))
	{
		cerr << "Invalid input!!\n";
		system("pause");
		return 0;
	}
	input.Set_data(input_x, input_y);

	// Find with original tree
	cout << "\nFind the closest point \nWith original tree: ";
	cout << tree1->findClosestPoint(input) << endl;
	

	QuadtreeNode* tree2 = new QuadtreeNode(*tree1);
	delete tree1;

	// Find with original tree
	cout << "With copied tree:   ";
	cout << tree2->findClosestPoint(input) << endl << endl;


	system("pause");
	return 0;
}