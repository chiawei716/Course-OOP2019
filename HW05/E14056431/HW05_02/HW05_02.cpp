// Copyright © 2019 趙珈葦. All Rights Reserved.
// 系級: 機械109
// 學號: E14056431

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

template <class T>
T average_list(initializer_list<T> l) {
	T result = 0;
	initializer_list<T>::iterator i;
	for (i = l.begin(); i != l.end(); ++i)
		result += *i;
	result /= l.size();
	return result;
}

int main()
{
	// list of double deduced from list contents
	auto q = average_list({ 15.4, 10.7, 9.0 });
	cout << q << endl;  
	// list of int deduced from list contents   
	cout << average_list({ 20, 30, 19, 17, 45, 38 }) << endl;  
	// forced list of double   
	auto ad = average_list<double>({ 'A', 70, 65.33 });
	cout << ad << endl;
	system("pause");
	return 0;
}