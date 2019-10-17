// Copyright © 2019 趙珈葦. All Rights Reserved.
// 系級: 機械109
// 學號: E14056431

#include "HW01_02.h"

namespace MyGeo = MyGeometry;

int main()
{
	unsigned int nPoint = 0;

	// Test for #1~3
	cout << "// #1-3\n";
	struct MyGeo::Point testPt = { 3, 4 };
	cout << "一測試點 ";
	cout << testPt.CoutPoint();
	cout << ", 其與原點距離為 ";
	cout << testPt.Length() << "\n";

	// Test for #4
	cout << "\n\n// #4\n";
	struct MyGeo::Point* pts = MyGeo::LoadPoint("points.txt", nPoint);
	cout << nPoint << " points read. List below:\n\n";
	for (int i = 0; i < nPoint; i++)
		cout << i + 1 << " - " << pts[i].CoutPoint() << "\n";

	// Test for #5
	cout << "\n\n// #5\n";
	cout << "最接近 x+y=1/x+y-1=0 的點為： ";
	cout << MyGeo::MinDistance(pts, nPoint, 1, 1, -1).CoutPoint();
	cout << ", 距離為： ";
	cout << MyGeo::MinDistance(pts, nPoint, 1, 1, -1).DistanceToLine(1, 1, -1) << "\n";

	// Test for #6
	cout << "\n\n// #6\n";
	cout << "Points sorted. List below: [pos - dist]\n\n";
	MyGeo::SortbyLength(pts, nPoint);
	for (int i = 0; i < nPoint; i++)
	{
		cout << pts[i].CoutPoint();
		cout << " - ";
		cout << pts[i].Length();
		cout << "\n";
	}

	// Test for #7
	cout << "\n\n// #7\n";
	cout << "Please check the .txt file generated.\n";
	MyGeo::Report(
		"Report.txt",
		"E14056431",
		"趙珈葦",
		nPoint,
		MyGeo::MinDistance(pts, nPoint, 1, 1, -1),
		pts[nPoint - 1]
	);
}