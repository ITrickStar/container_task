#pragma once

template <class T>
struct Node
{
	T value;
	Node *next;
};

template <class T>
class List
{
private:
	Node<T> *head;

public:
	void Push(T val){};
	T Pop(){};
};
