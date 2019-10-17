// Copyright © 2019 趙珈葦. All Rights Reserved.
// 系級: 機械109
// 學號: E14056431

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

// Find Maximum
template <class T> const T Max(T array[], int size)
{
	// Find maximum
	T temp = array[0];
	for (int i = 0; i < size; i++)
		if (array[i] > temp) temp = array[i];

	return temp;
}

// Char pointer only
const char* Max(char* array[], int size)
{
	// If empty, return null-pointer
	if (size == 0) return nullptr;

	int tempStr = 0;
	size_t tempLen = strlen(array[0]);
	for (int i = 0; i < size; i++)
		if (strlen(array[i]) > tempLen)
		{
			tempLen = strlen(array[i]);
			tempStr = i;
		}

	return array[tempStr];
}

// Print out an array
template <class T> void showArray(T array[], int size)
{
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << "\n";
	return;
}

int main() {
	srand(time(NULL));

	// short
	short shortArray[6];
	for (int i = 0; i < 6; i++)
		shortArray[i] = (short)(rand() % 1000);
	cout << "//Short\nArray: ";
	showArray(shortArray, 6);
	cout << "Maxinum: " << Max(shortArray, 6) << "\n\n";

	// double
	double doubleArray[8];
	for (int i = 0; i < 8; i++)
		doubleArray[i] = (double)(rand() % 1000);
	cout << "//Double\nArray: ";
	showArray(doubleArray, 8);
	cout << "Maxinum: " << Max(doubleArray, 8) << "\n\n";

	// char
	const char* strArr[] = { "1", "22", "333", "4444", "55555", "4444" };
	cout << "//Char\nArray: ";
	showArray(strArr, 6);
	cout << "Longest_content: " << Max(strArr, 6) << "\n";
	printf("Longest_address: %p\n", Max(strArr, 6));
}