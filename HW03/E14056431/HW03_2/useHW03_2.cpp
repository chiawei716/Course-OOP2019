// Copyright © 2019 趙珈葦. All Rights Reserved.
// 系級: 機械109
// 學號: E14056431

#include "HW03_2.h"
using namespace std;

int main()
{
	/* Default constructor ( type: int, size: 10 ) */
	Queue<int> *defaultOne = new Queue<int>();
	cout << "/* Default Queue (type: int, size: 10) */\n";

	// Add 11 element ( 0 ~ 10 )
	cout << "// Add 0 ~ 10\n";
	for (int i = 0; i < 11; ++i) defaultOne->Add(i);
	cout << endl;

	// Delete 11 times ( expected 0 ~ 9 )
	cout << "// Delete 11 times\n";
	for (int i = 0; i < 11; ++i)
	{
		int* temp = defaultOne->Delete();
		if (temp != nullptr)
			cout << "Delete " << *temp << endl;
	}
	cout << endl;

	// Destruct
	cout << "// Destruct deault one\n";
	delete defaultOne;
	defaultOne = nullptr;
	cout << endl << endl;


	/* Custom constructor ( type: double, size: 5 ) */
	Queue<double> *customOne = new Queue<double>(5);
	cout << "/* Custom Queue ( type: double, size: 5) */\n";

	// Add 7 element ( 0 ~ 6 )
	cout << "// Add 0 ~ 6\n";
	for (int i = 0; i < 7; ++i) customOne->Add(i);
	cout << endl;

	cout << "Copy and Assignment ones construct now!!!\n\n";

	// Copy Constructor
	Queue<double> *copyOne = new Queue<double>(*customOne);

	// Asignment Operator
	Queue<double> assignmentOne = *customOne;

	// Delete 7 times ( expected 0 ~ 6 )
	// Custom Queue
	cout << "// Delete 7 times\n";
	for (int i = 0; i < 7; ++i)
	{
		double* temp = customOne->Delete();
		if (temp != nullptr)
			cout << "Delete " << *temp << endl;
	}
	cout << endl;

	// Copied Queue
	cout << "/* Copied Queue ( with custom queue ) */\n";
	cout << "// Delete 7 times\n";
	for (int i = 0; i < 7; ++i)
	{
		double* temp = copyOne->Delete();
		if (temp != nullptr)
			cout << "Delete " << *temp << endl;
	}
	cout << endl;

	// Assigned Queue
	cout << "/* Assigned Queue ( with custom queue ) */\n";
	cout << "// Delete 7 times\n";
	for (int i = 0; i < 7; ++i)
	{
		double* temp = assignmentOne.Delete();
		if (temp != nullptr)
			cout << "Delete " << *temp << endl;
	}
	cout << endl;

	// Destruct
	cout << "// Destruct custom and copied ones\n";
	delete customOne;
	delete copyOne;

	cout << endl;
	system("pause");
}