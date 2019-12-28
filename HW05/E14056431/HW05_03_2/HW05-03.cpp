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

// Linked list
class Node
{
public:
	Point value;
	Node* next;
	Node(Point& point) { this->value = point; this->next = nullptr; }
	~Node() {}
};

class List
{
public:
	int size = 0;
	Node* head;
	Node* tail;
	List() { this->head = nullptr; this->tail = nullptr; }
	~List()
	{
		Node *temp = head;
		while (temp != nullptr)
		{
			Node *temp2 = temp->next;
			delete temp;
			temp = temp2;
		}
	}

	bool isEmpty()
	{
		if (this->head == nullptr && this->tail == nullptr) return true;
		else return false;
	}

	void insert(Point& point)
	{
		this->size++;
		if (this->isEmpty())
			this->head = this->tail = new Node(point);
		else {
			tail->next = new Node(point);
			tail = tail->next;
		}
	}

	bool find(Point& point)
	{
		if (this->isEmpty()) return false;
		Node* temp = this->head;
		while (temp != nullptr)
		{
			if (point == temp->value) return true;
			temp = temp->next;
		}
		return false;
	}
};

Point* LoadPoint(const char*, unsigned int&);

int main()
{

	std::chrono::steady_clock::time_point start, end;//紀錄時間的變數

	start = std::chrono::steady_clock::now();//紀錄讀檔開始時間
	unsigned int nPoint;
	Point* point_array = LoadPoint("HW5-3-3.bin", nPoint);//讀點
	end = std::chrono::steady_clock::now();//紀錄讀檔結束時間
	std::cout << "Time " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;
	std::cout << "Number of point " << nPoint << std::endl;

	start = std::chrono::steady_clock::now();//紀錄移除重複點開始時間



	//請將移除重複點演算法撰寫於此

	// 過濾點陣列為result,為一個三維的linked list陣列
	// A three-dimension array of linked list, categorate points by its tail of integer part
	List ****result = new List***[100];
	for (int i = 0; i < 100; ++i)
		result[i] = new List**[100];
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			result[i][j] = new List*[100];
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			for (int p = 0; p < 100; ++p)
				result[i][j][p] = new List();

	// Check if a point exist at its list, if not, insert it
	for (int i = 0; i < nPoint; ++i)
	{
		int x = (long long int)(point_array[i][0]) >= 0 ? (long long int)(point_array[i][0]) % 100 : (long long int)(-point_array[i][0]) % 100;
		int y = (long long int)(point_array[i][1]) >= 0 ? (long long int)(point_array[i][1]) % 100 : (long long int)(-point_array[i][1]) % 100;
		int z = (long long int)(point_array[i][2]) >= 0 ? (long long int)(point_array[i][2]) % 100 : (long long int)(-point_array[i][2]) % 100;
		if (!result[x][y][z]->find(point_array[i]))
			result[x][y][z]->insert(point_array[i]);
	}

	int size = 0;

	// Get sum of sizes, and release memory
	delete[]point_array;
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			for (int p = 0; p < 100; ++p)
			{
				size += result[i][j][p]->size;
				delete result[i][j][p];
			}
			delete[] result[i][j];
		}
		delete[] result[i];
	}
	delete[] result;

	end = std::chrono::steady_clock::now();//紀錄移除重複點結束時間

	std::cout << "Time " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;
	std::cout << size << std::endl;

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