#pragma once
#include <iostream>
#include <iomanip>
#include <stack>

template <typename T>
class Tree
{
	struct Item 
	{
		int key;
		T data;
		Item* right;
		Item* left;
		Item* parent;
		Item(int key, T data, Item* right = nullptr, Item* left = nullptr, Item* parent = nullptr);
	};

	void print_Lt_Rt_t(Item*& root);
	Tree<T>::Item* lt_Rt_t(Item*& root);
public:
	int size = 0;
	Item* root = nullptr;

	Tree();
	~Tree();
	void printSize();
	void clear(Item*& root);
	bool isEmpty();
	void read(int key, Item*& root);
	void edit(int key, T newData, Item*& root);
	void add(int key, T data, Item*& root, Item*& parent);
	void deleteItem(int key, Item*& root);
	void print(Item*& root, int indent = 0);
	void t_Lt_Rt(Item*& root);
	int getHeight(Item*& root);

	class Iterator 
	{
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

	class ReverseIterator 
	{
	public:
		Item* obj;
		T& operator*();
		void operator++(int);
		void operator--(int);
		bool operator ==(const ReverseIterator& it);
		bool operator !=(const ReverseIterator& it);
	};
	ReverseIterator rBegin();
	ReverseIterator rEnd();
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
inline void Tree<T>::printSize()
{
	std::cout << "������� ������ ������ �����: " << size << std::endl;
}

template<typename T>
inline void Tree<T>::clear(Item*& root)
{
	if (root->left) {
		clear(root->left);
	}
	if (root->right) {
		clear(root->right);
	}
	root = nullptr;
	size--;
}

template<typename T>
inline bool Tree<T>::isEmpty() 
{
	if (!root) return true;
	else return false;
}

template<typename T>
inline void Tree<T>::read(int key, Item*& root)
{
	if (key == root->key) {
		std::cout << "������ �������� � ������ " << key << ": " << root->data << std::endl;
	}
	else if (key < root->key) {
		read(key, root->left);
	}
	else if (key > root->key) {
		read(key, root->right);
	}
}

template<typename T>
inline void Tree<T>::edit(int key, T newData, Item*& root)
{
	if (key == root->key) {
		root->data = newData;
	}
	else if (key < root->key) {
		edit(key, newData, root->left);
	}	
	else if (key > root->key) {
		edit(key, newData, root->right);
	}	
}

template<typename T>
inline void Tree<T>::add(int key, T data, Item*& root, Item*& parent)
{
	if (!root) {
		root = new Item(key, data);
		if (root != parent) {
			root->parent = parent;
		}
		size++;
	}
	else if (key == root->key) {
		std::cout << "������ ���� ��� ���������� � ������\n";
	}
	else if (key < root->key) {
		add(key, data, root->left, root);
	}	
	else if (key > root->key) {
		add(key, data, root->right, root);
	}
}

template<typename T>
inline void Tree<T>::deleteItem(int key, Item*& root)
{
	if (key < root->key) {
		deleteItem(key, root->left);
	}
	else if (key > root->key) {
		deleteItem(key, root->right);
	}	
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
inline void Tree<T>::print(Item*& root, int indent)
{
	if (root) {
		if (root->right) {
			print(root->right, indent + 4);
		}
		if (indent) {
			std::cout << std::setw(indent) << ' ';
		}
		if (root->right) {
			std::cout << " /\n" << std::setw(indent) << ' ';
		}
		std::cout << root->key << ":" << root->data << "\n ";
		if (root->left) {
			std::cout << std::setw(indent) << ' ' << " \\\n";
			print(root->left, indent + 4);
		}
	}
	else {
		std::cout << "������ ������\n";
	}	
}

template<typename T>
inline void Tree<T>::t_Lt_Rt(Item*& root)
{
	if (!root) {
		return;
	}
	std::cout << root->key << " ";
	print_Lt_Rt_t(root->left);
	print_Lt_Rt_t(root->right);
}

template<typename T>
inline int Tree<T>::getHeight(Item*& root)
{
	// ����������� �������� � ���������
	int h1 = 0, h2 = 0;
	if (!root) {
		return 0;
	}
	if (root->left) {
		h2 = getHeight(root->left);
	}
	if (root->right) {
		h1 = getHeight(root->right);
	}
	return (std::max(h1, h2) + 1);
}

template<typename T>
inline void Tree<T>::print_Lt_Rt_t(Item*& root)
{
	if (!root) {
		return;
	}
	print_Lt_Rt_t(root->left);
	print_Lt_Rt_t(root->right);
	std::cout << root->key << " ";
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
	// ����������� �������� � ���������
	Iterator it;
	it.obj = nullptr;
	std::stack<Item*> stack;
	stack.push(root);
	while (!stack.empty()) {
		Item* current = stack.top();
		it.obj = current;
		stack.pop();
		if (current->right) {
			stack.push(current->right);
		}
		if (current->left) {
			stack.push(current->left);
		}
	}
	return it;
}

template<typename T>
inline Tree<T>::Item* Tree<T>::lt_Rt_t(Item*& root)
{
	if (!root) {
		return nullptr;
	}
	lt_Rt_t(root->left);
	lt_Rt_t(root->right);
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
	// ����������� � ����� ������
	while (it.obj->parent) {
		it.obj = it.obj->parent;
	}
	std::stack<Item*> stack;
	// �������� ������ � ����
	stack.push(it.obj);
	while (!stack.empty()) {
		// ����� �������� �������� �����
		Item* current = stack.top();
		// ������ �������, �������� � ���� ��� ��������
		stack.pop();
		if (current->right) {
			stack.push(current->right);
		}
		if (current->left) {
			stack.push(current->left);
		}
		// ���� ����� ��������, ����� ���������� �������� � �����
		if (current == this->obj && stack.size()) {
			it.obj = stack.top();
			break;
		}
		else if (!stack.size()) {
			std::cout << "����� �� �������!\n";
			return;
		}
	}
	*this = it;
}

template<typename T>
inline void Tree<T>::Iterator::operator--(int)
{
	Iterator it = *this;
	if (it.obj->parent == nullptr) {
		std::cout << "����� �� �������!\n";
		return;
	}
	// ����������� � ����� ������
	while (it.obj->parent) {
		it.obj = it.obj->parent;
	}
	std::stack<Item*> stack;
	// �������� ������ � ����
	stack.push(it.obj);
	while (!stack.empty()) {
		// ����� �������� �������� �����
		Item* current = stack.top();
		// ������ �������, �������� � ���� ��� ��������
		stack.pop();
		if (current->right) {
			stack.push(current->right);
		}
		if (current->left) {
			stack.push(current->left);
		}
		// ���� ����� ��������, ����� ����������� (�����) �������� � �����
		if (stack.top() == this->obj) {
			it.obj = current;
			break;
		}
	}
	*this = it;
}

template<typename T>
inline bool Tree<T>::Iterator::operator==(const Iterator& it)
{
	if (obj == it.obj) {
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
inline bool Tree<T>::Iterator::operator!=(const Iterator& it)
{
	if (obj != it.obj) {
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
inline Tree<T>::ReverseIterator Tree<T>::rBegin()
{
	// ����������� �������� � ���������
	ReverseIterator it;
	it.obj = nullptr;
	std::stack<Item*> stack;
	stack.push(root);
	while (!stack.empty()) {
		Item* current = stack.top();
		it.obj = current;
		stack.pop();
		if (current->right) {
			stack.push(current->right);
		}
		if (current->left) {
			stack.push(current->left);
		}
	}
	return it;
}

template<typename T>
inline Tree<T>::ReverseIterator Tree<T>::rEnd()
{
	ReverseIterator it;
	it.obj = root;
	return it;
}

template<typename T>
inline T& Tree<T>::ReverseIterator::operator*()
{
	return this->obj->data;
}

template<typename T>
inline void Tree<T>::ReverseIterator::operator++(int)
{
	ReverseIterator it = *this;
	if (it.obj->parent == nullptr) {
		std::cout << "����� �� �������!\n";
		return;
	}
	// ����������� � ����� ������
	while (it.obj->parent) {
		it.obj = it.obj->parent;
	}
	std::stack<Item*> stack;
	// �������� ������ � ����
	stack.push(it.obj);
	while (!stack.empty()) {
		// ����� �������� �������� �����
		Item* current = stack.top();
		// ������ �������, �������� � ���� ��� ��������
		stack.pop();
		if (current->right) {
			stack.push(current->right);
		}
		if (current->left) {
			stack.push(current->left);
		}
		// ���� ����� ��������, ����� ����������� (�����) �������� � �����
		if (stack.top() == this->obj) {
			it.obj = current;
			break;
		}
	}
	*this = it;
}

template<typename T>
inline void Tree<T>::ReverseIterator::operator--(int)
{
	ReverseIterator it = *this;
	// ����������� � ����� ������
	while (it.obj->parent) {
		it.obj = it.obj->parent;
	}	
	std::stack<Item*> stack;
	// �������� ������ � ����
	stack.push(it.obj);
	while (!stack.empty()) {
		// ����� �������� �������� �����
		Item* current = stack.top();
		// ������ �������, �������� � ���� ��� ��������
		stack.pop();
		if (current->right) {
			stack.push(current->right);
		}
		if (current->left) {
			stack.push(current->left);
		}
		// ���� ����� ��������, ����� ���������� �������� � �����
		if (current == this->obj && stack.size()) {
			it.obj = stack.top();
			break;
		}
		else if (!stack.size()) {
			std::cout << "����� �� �������!\n";
			return;
		}
	}
	*this = it;
}

template<typename T>
inline bool Tree<T>::ReverseIterator::operator==(const ReverseIterator& it)
{
	if (obj == it.obj) {
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
inline bool Tree<T>::ReverseIterator::operator!=(const ReverseIterator& it)
{
	if (obj != it.obj) {
		return true;
	}
	else {
		return false;
	}
}