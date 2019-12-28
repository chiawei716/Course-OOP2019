// Copyright © 2019 趙珈葦. All Rights Reserved.
// 系級: 機械109
// 學號: E14056431

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

// #1: outint() -> lambda_1
auto lambda_1 = [](int n) { std::cout << n << " "; };

// #2: f100 -> lambda_2
auto lambda_2 = [](const int & n) { return  n > 100; };

int main()
{
	int vals[10] = { 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };
	std::list<int> yadayada(vals, vals + 10);
	std::list<int> etcetera(vals, vals + 10);

	std::cout << "Original lists:\n";
	for_each(yadayada.begin(), yadayada.end(), lambda_1);			// #1 - Replace outint() with lambda_1 functor
	std::cout << std::endl;
	for_each(etcetera.begin(), etcetera.end(), lambda_1);
	std::cout << std::endl;

	yadayada.remove_if(lambda_2);									// #2 - Replace f100 with lambda_2 functor
	etcetera.remove_if([](const int & n) {return n > 200; });		// #3 - Replace TooBig<int>(200) with functor

	std::cout << "Trimmed lists:\n";
	for_each(yadayada.begin(), yadayada.end(), lambda_1);
	std::cout << std::endl;
	for_each(etcetera.begin(), etcetera.end(), lambda_1);
	std::cout << std::endl;
	std::cin.get();
	return 0;
}
