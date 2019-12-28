// Copyright © 2019 趙珈葦. All Rights Reserved.
// 系級: 機械109
// 學號: E14056431

#include <fstream>
#include <iostream>
#include <iomanip>
#include <chrono>

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
	bool operator == (Point&);
	bool operator != (Point&);
	friend std::istream& operator >> (std::istream&, Point&);
	friend std::ostream& operator<<(std::ostream&, const Point&);
};

Point* LoadPoint(const char*, unsigned int&);

int main()
{
	
	std::chrono::steady_clock::time_point start, end;//紀錄時間的變數

	start = std::chrono::steady_clock::now();//紀錄讀檔開始時間
	unsigned int nPoint;
	Point* point_array = LoadPoint("HW5-3-1.bin", nPoint);//讀點
	end = std::chrono::steady_clock::now();//紀錄讀檔結束時間
	std::cout << "Time " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;
	std::cout << "Number of point " << nPoint << std::endl;

	start = std::chrono::steady_clock::now();//紀錄移除重複點開始時間

	//請將移除重複點演算法撰寫於此

	// 原point_array即為過濾後點陣列,但將以第一點作為刪除點
	// Use first point to be the symbol of empty one, considering every point is possible
	Point empty = point_array[0];
	int left = nPoint;

	// Check each one with pushing forward starter
	for (int i = 0; i < nPoint - 1; ++i)
	{
		// Check if the point isn't removed yet
		if (i == 0 || point_array[i] != empty) {
			for (int j = i + 1; j < nPoint; ++j)
			{
				// If same, remove & minus one
				if (point_array[i] == point_array[j])
				{
					point_array[j] = empty;
					left--;
				}
			}
		}
	}

	end = std::chrono::steady_clock::now();//紀錄移除重複點結束時間

	std::cout << "Time " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;
	std::cout << left << std::endl;
	// Record the first point for removing

	delete[]point_array;
	system("pause");
	return 0;
}


Point* LoadPoint(const char* filename, unsigned int& nPoint)		// 從文字檔讀入多個點資料
{
	using namespace std;
	Point* pPoint;

	try
	{
		if (!filename)
			throw new exception("引數錯誤");
		
		ifstream fin;
		fin.open(filename, ios::in | ios::binary);
		if (!fin.good())
			throw new exception("檔名或路徑錯誤! 無法開啟檔案!");
		
		const unsigned int tmpLen = 80;
		char tmpBuff[tmpLen];
		
		//read Header
		fin.read(tmpBuff, tmpLen);
		if (!fin.good())
			throw new exception("格式不合(header錯誤)");

		//how many point ?
		fin.read((char *)&nPoint, 4);//unsigned long, must be 4 bytes
		if (!fin.good())
			throw new exception("格式不合(三角網格數錯誤)");
		
		//allocate array memory
		if (nPoint == 0)
		{
			throw new exception("NO Point!");
		}
		pPoint = new Point[nPoint];

		//read triangles
		fin.seekg(84, ios::beg);
		for (int i = 0; i < nPoint; i++)
		{
			fin.read(tmpBuff, 14);
			if (!fin.good())
				throw new exception("格式不合");
			int gc = fin.gcount();
			if (gc < 14)
				throw;

			memcpy(&pPoint[i], tmpBuff, 12);
		}
		fin.clear();
		fin.close();
	}
	catch (exception *)
	{
		pPoint = 0;
		return (Point *)0;
	}

	return pPoint;
}


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

bool Point::operator == (Point& point)
{
	if (this->x == point[0] && this->y == point[1] && this->z == point[2]) return true;
	else return false;
}

bool Point::operator != (Point& point)
{
	if (this->x == point[0] && this->y == point[1] && this->z == point[2]) return false;
	else return true;
}