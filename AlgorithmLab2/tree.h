#pragma once
#include <iostream>
#include <iomanip>
#include <stack>
using namespace std;

template <typename T>
class Tree
{
	struct Item {
		int key;
		T data;
		Item* right;
		Item* left;
		Item* parent;
		Item(int key, T data, Item* right = nullptr, Item* left = nullptr, Item* parent = nullptr);
	};
	
	void Print_Lt_Rt_t(Item*& root);
	Tree<T>::Item* Lt_Rt_t(Item*& root);
public:
	int size = 0;
	Item* root = nullptr;

	Tree();
	~Tree();
	void PrintSize();
	void Clear(Item*& root);
	bool IsEmpty();
	void Read(int key, Item*& root);
	void Edit(int key, T newData, Item*& root);
	void Add(int key, T data, Item*& root, Item*& parent);
	void Delete(int key, Item*& root);
	void Print(Item*& root, int indent = 0);
	void t_Lt_Rt(Item*& root);
	int GetHeight(Item*& root);

	class Iterator {
	public:
		Item* obj;
		T& operator*();
		void operator++(int);
		void operator--(int);
		bool operator ==(const Iterator& it);
		bool operator !=(const Iterator& it);
	};
	Iterator begin();
	Iterator end();

	class ReverseIterator {

	public:
		Item* obj;
		T& operator*();
		void operator++(int);
		void operator--(int);
		bool operator ==(const ReverseIterator& it);
		bool operator !=(const ReverseIterator& it);
	};
	ReverseIterator rbegin();
	ReverseIterator rend();
};

#include "tree.inl"