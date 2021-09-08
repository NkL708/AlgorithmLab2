#pragma once
#include <iostream>
#include <iomanip>
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

template<typename T>
inline Tree<T>::Item::Item(int key, T data, Item* right, Item* left, Item* parent)
{
	this->key = key;
	this->data = data;
	this->right = right;
	this->left = left;
	this->parent = parent;
}

template<typename T>
inline Tree<T>::Tree()
{
}

template<typename T>
inline Tree<T>::~Tree()
{
}

template<typename T>
inline void Tree<T>::PrintSize()
{
	cout << "Текущий размер дерева равен: " << size << endl;
}

template<typename T>
inline void Tree<T>::Clear(Item*& root)
{
	if (root->left) 
		Clear(root->left);
	if (root->right) 
		Clear(root->right);
	root = nullptr;
	size--;
}

template<typename T>
inline bool Tree<T>::IsEmpty() { 
	if (!root) return true;
	else return false;
}

template<typename T>
inline void Tree<T>::Read(int key, Item*& root)
{
	if (key == root->key)
		cout << "Данные элемента с ключом " << key << ": " << root->data << endl;
	else if (key < root->key) 
		Read(key, root->left);
	else if (key > root->key) 
		Read(key, root->right);
}

template<typename T>
inline void Tree<T>::Edit(int key, T newData, Item*& root)
{
	if (key == root->key)
		root->data = newData;
	else if (key < root->key)
		Edit(key, newData, root->left);
	else if (key > root->key)
		Edit(key, newData, root->right);
}

template<typename T>
inline void Tree<T>::Add(int key, T data, Item*& root, Item*& parent)
{
	if (!root) {
		root = new Item(key, data);
		root->parent = parent;
		size++;
	}
	else if (key == root->key)
		cout << "Данный ключ уже существует в дереве" << endl;
	else if (key < root->key)
		Add(key, data, root->left, root);
	else if (key > root->key)
		Add(key, data, root->right, root);
}

template<typename T>
inline void Tree<T>::Delete(int key, Item*& root)
{
	if (key < root->key)
		Delete(key, root->left);
	else if (key > root->key)
		Delete(key, root->right);
	else if (key == root->key && !root->left && !root->right) {
		root = nullptr;
		size--;
	}
	else if (key == root->key && !root->left) {
		root = root->right;
		root->right = nullptr;
	}
	else if (key == root->key && !root->right) {
		root = root->left;
		root->left = nullptr;
	}
	else if (key == root->key) {
		root->key = root->left->key;
		root->data = root->left->data;
		root->left = nullptr;
	}
}

template<typename T>
inline void Tree<T>::Print(Item*& root, int indent)
{
	if (root) {
		if (root->right)
			Print(root->right, indent + 4);
		if (indent)
			cout << setw(indent) << ' ';
		if (root->right) cout << " /\n" << setw(indent) << ' ';
		cout << root->key << ":" << root->data << "\n ";
		if (root->left) {
			cout << setw(indent) << ' ' << " \\\n";
			Print(root->left, indent + 4);
		}
	}
	else cout << "Дерево пустое" << endl;
}

template<typename T>
inline void Tree<T>::t_Lt_Rt(Item*& root)
{
	if (!root) return;
	cout << root->key << " ";
	Print_Lt_Rt_t(root->left);
	Print_Lt_Rt_t(root->right);
}

template<typename T>
inline void Tree<T>::Print_Lt_Rt_t(Item*& root)
{
	if (!root) return;
	Print_Lt_Rt_t(root->left);
	Print_Lt_Rt_t(root->right);
	cout << root->key << " ";
}

template<typename T>
inline Tree<T>::Iterator Tree<T>::begin()
{
	Iterator it;
	it.obj = root;
	return it;
}

template<typename T>
inline Tree<T>::Iterator Tree<T>::end()
{
	Iterator it;
	it.obj = root;
	while (it.obj->left)
		it.obj = it.obj->left;
	while (it.obj->right)
		it.obj = it.obj->right;
	return it;
}

template<typename T>
inline Tree<T>::Item* Tree<T>::Lt_Rt_t(Item*& root)
{
	if (!root) return nullptr;
	Lt_Rt_t(root->left);
	Lt_Rt_t(root->right);
	return root;
}

template<typename T>
inline T& Tree<T>::Iterator::operator*()
{
	return this->obj->data;
}

template<typename T>
inline void Tree<T>::Iterator::operator++(int)
{
	Iterator it = *this;
	if (it.obj->left)
		it.obj = it.obj->left;
	else if (it.obj->right)
		it.obj = it.obj->right;
	else {
		// Написать!
	}
	*this = it;
}

template<typename T>
inline void Tree<T>::Iterator::operator--(int)
{
	Iterator it = *this;
	it.obj = it.obj->parent;
	*this = it;
}

template<typename T>
inline bool Tree<T>::Iterator::operator==(const Iterator& it)
{
	if (obj == it.obj) return true;
	else return false;
}

template<typename T>
inline bool Tree<T>::Iterator::operator!=(const Iterator& it)
{
	if (obj != it.obj) return true;
	else return false;
}

template<typename T>
inline Tree<T>::ReverseIterator Tree<T>::rbegin()
{
	return ReverseIterator();
}

template<typename T>
inline Tree<T>::ReverseIterator Tree<T>::rend()
{
	return ReverseIterator();
}

template<typename T>
inline T& Tree<T>::ReverseIterator::operator*()
{
	return this->obj->data;
}

template<typename T>
inline void Tree<T>::ReverseIterator::operator++(int)
{

}

template<typename T>
inline void Tree<T>::ReverseIterator::operator--(int)
{

}

template<typename T>
inline bool Tree<T>::ReverseIterator::operator==(const ReverseIterator& it)
{
	if (obj == it.obj) return true;
	else return false;
}

template<typename T>
inline bool Tree<T>::ReverseIterator::operator!=(const ReverseIterator& it)
{
	if (obj != it.obj) return true;
	else return false;
}
