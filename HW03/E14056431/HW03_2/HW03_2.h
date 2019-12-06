// Copyright © 2019 趙珈葦. All Rights Reserved.
// 系級: 機械109
// 學號: E14056431

#pragma once
#ifndef HW03_2_H
#define HW03_2_H

#include <iostream>
using std::cout;

#define DefaultQueueSize 10

template<class KeyType>
class Queue
{
private:
	int front, rear;
	KeyType* queue;
	int MaxSize;

public:
	// Constructor
	Queue(int MaxQueueSize = DefaultQueueSize)
	{
		this->MaxSize = MaxQueueSize;
		this->queue = new KeyType[MaxQueueSize];
		front = -1;
		rear = -1;
	}

	// Copy Constructor
	Queue(const Queue& queue)
	{
		this->MaxSize = queue.getMaxSize();
		this->queue = new KeyType[MaxSize];
		this->front = queue.getFront();
		this->rear = queue.getRear();
		for (int i = 0; i < MaxSize; ++i)
			this->queue[i] = queue.getQueue()[i];
	}
	
	// Destructor
	~Queue()
	{
		cout << "Queue destructed\n";
		if (queue != nullptr)
			delete[] queue;
		return;
	}
	
	// Asignment operator
	void operator=(const Queue& queue)
	{
		if (this->MaxSize != queue.getMaxSize())
		{
			delete[] this->queue;
			this->MaxSize = queue.getMaxSize();
			this->queue = new KeyType[this->MaxSize];
		}
		this->front = queue.getFront();
		this->rear = queue.getRear();
		for (int i = 0; i < this->MaxSize; ++i)
			this->queue[i] = queue.getQueue()[i];
	}

	// If queue is full
	bool isFull()
	{
		if (front - rear == 1 || rear - front == MaxSize - 1)
			return true;
		else
			return false;
	}

	// If queue is empty
	bool isEmpty()
	{
		if (front == -1 && rear == -1)
			return true;
		else
			return false;
	}

	// Add an item
	void Add(const KeyType& item)
	{
		// if full
		if (this->isFull())
		{
			this->QueueFull();
			return;
		}
		// not full
		else
		{
			cout << "Insert success.\n";
			// if empty
			if (this->isEmpty()) 
			{
				this->front = 0;
				this->rear = 0;
				this->queue[this->rear] = item;
			}
			// not empty
			else
			{
				this->rear = (this->rear + 1) % this->MaxSize;
				this->queue[rear] = item;
			}
		}
	}

	// Delete an item
	KeyType* Delete()
	{
		// if empty
		if (this->isEmpty())
		{
			this->QueueEmpty();
			return nullptr;
		}
		// not empty
		else
		{
			// if one element left
			if (this->front == this->rear)
			{
				KeyType* temp = this->queue + front;
				this->front = -1;
				this->rear = -1;
				return temp;
			}
			// else
			else
			{
				KeyType* temp = this->queue + front;
				this->front = (this->front + 1) % this->MaxSize;
				return temp;
			}
		}
	}

	// Get functions
	int getMaxSize() const
	{
		return this->MaxSize;
	}

	// Get queue
	KeyType* getQueue() const
	{
		return this->queue;
	}

	// Get front
	int getFront() const
	{
		return this->front;
	}

	// Get rear
	int getRear() const
	{
		return this->rear;
	}

	// Message when queue is full
	void QueueFull()
	{
		cout << "The queue is full.\n";
	}

	// Message when queue is empty
	void QueueEmpty()
	{
		cout << "The queue is empty.\n";
	}
};

#endif // !HW03_2_H
