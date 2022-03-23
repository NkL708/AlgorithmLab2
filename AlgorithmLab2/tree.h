#pragma once
#include <iostream>
#include <iomanip>
#include <stack>
#include <queue>

typedef unsigned long long INT_64;

template <typename T>
class Tree
{
	struct Item 
	{
		INT_64 key;
		T data;
		Item* right;
		Item* left;
		Item* parent;
		int consoleW;
		Item(INT_64 key, T data, Item* right = nullptr, Item* left = nullptr, Item* parent = nullptr);
	};

	void print_Lt_Rt_t(Item*& root);
	Tree<T>::Item* lt_Rt_t(Item*& root);
public:
	int viewedItems = 0;
	int size = 0;
	Item* root = nullptr;

	Tree();															// Конструктор
	~Tree();														// Деструктор
	int getSize();													// Получение размера
	void clear(Item*& root);										// Очистка
	bool isEmpty();													// Проверка на пустоту
	T read(INT_64 key, Item*& root);								// Чтение значения
	void edit(INT_64 key, T newData, Item*& root);					// Изменение значения
	void add(INT_64 key, T data, Item*& root, Item*& parent);		// Добавление значения
	void deleteItem(INT_64 key, Item*& root);						// Удаление значения
	void printHorizontal(Item*& root, int indent = 0);				// Вывод горизонтальный
	void printVertical(Item*& root);								// Вывод вертикальный
	void t_Lt_Rt(Item*& root);
	int getTreeHeight(Item*& root);									// Получение высоты дерева
	int getDepth(Item*& target);									// Получение уровня элемента
	bool isContain(INT_64 key, Item*& root);						// Содержит ли дерево значение
	int getViewedItems();

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
inline Tree<T>::Item::Item(INT_64 key, T data, Item* right, Item* left, Item* parent)
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
	clear(root);
}

template<typename T>
inline int Tree<T>::getSize()
{
	return size;
}

template<typename T>
inline void Tree<T>::clear(Item*& root)
{
	if (root) {
		if (root->left) {
			clear(root->left);
		}
		if (root->right) {
			clear(root->right);
		}
		root = nullptr;
		size--;
	}
}

template<typename T>
inline bool Tree<T>::isEmpty() 
{
	if (size > 0) {
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
inline T Tree<T>::read(INT_64 key, Item*& root)
{
	viewedItems = 1;
	if (root) {
		viewedItems++;
		if (key == root->key) {
			return root->data;
		}
		else if (key < root->key) {
			read(key, root->left);
		}
		else if (key > root->key) {
			read(key, root->right);
		}
	}
}

template<typename T>
inline void Tree<T>::edit(INT_64 key, T newData, Item*& root)
{
	viewedItems = 1;
	if (root) {
		viewedItems++;
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
}

template<typename T>
inline void Tree<T>::add(INT_64 key, T data, Item*& root, Item*& parent)
{
	if (root) {
		viewedItems++;
		if (key < root->key) {
			add(key, data, root->left, root);
		}
		else if (key > root->key) {
			add(key, data, root->right, root);
		}
	}
	root = new Item(key, data);
	if (getSize()) {
		root->parent = parent;
	}
	size++;
}

template<typename T>
inline void Tree<T>::deleteItem(INT_64 key, Item*& root)
{
	// Остаётся ли ключ в дереве?
	viewedItems = 1;
	if (root) {
		viewedItems++;
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
}

// Рекурсивный вывод
template<typename T>
inline void Tree<T>::printHorizontal(Item*& root, int indent)
{
	if (root) {
		if (root->right) {
			printHorizontal(root->right, indent + 4);
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
			printHorizontal(root->left, indent + 4);
		}
	}
	else {
		std::cout << "Дерево пустое\n";
	}	
}

// Итеративный вывод
template<typename T>
inline void Tree<T>::printVertical(Item*& root)
{
	if (root) {
		int height = getTreeHeight(root);
		std::queue<Item*>* treeLevels = new std::queue<Item*>[height];
		// Заполнение очередей по уровням
		for (int i = 1; i <= height; i++) {
			std::stack<Item*> stack;
			stack.push(root);
			while (!stack.empty()) {
				Item* current = stack.top();
				// Достаём элемент, помещаем в стек его потомков
				stack.pop();
				if (current->right) {
					stack.push(current->right);
				}
				if (current->left) {
					stack.push(current->left);
				}
				// Если текущий элемент с нужного уровня дерева
				if (getDepth(current) == i) {
					treeLevels[i - 1].push(current);
				}
			}
		}
		// Вывод всех очередей в консоль
		int step = 10;
		for (int i = 0; i < height; i++) {
			bool first = true;
			while (!treeLevels[i].empty()) {
				Item* current = treeLevels[i].front();
				int rNum = rand() % 3;
				int lenght;
				// Корень дерева
				if (!current->parent) {
					// Примерно центр консоли
					current->consoleW = 50;
					std::cout << std::setw(current->consoleW);
				}
				// Левый
				else if (current->parent->key > current->key) {
					current->consoleW = current->parent->consoleW - (step + rNum);
					lenght = current->parent->consoleW;
					std::cout << std::setw(lenght) << "/\n";
					std::cout << std::setw(current->consoleW);
				}
				// Правый
				else if (current->parent->key < current->key) {
					current->consoleW = current->parent->consoleW + (step + rNum);
					lenght = current->consoleW;
					std::cout << std::setw(lenght) << "\\\n";
					std::cout << std::setw(current->consoleW);
				}
				std::cout << current->key << ':' << current->data << "\n";
				treeLevels[i].pop();
			}
		}
		delete[] treeLevels;
	}
	else {
		std::cout << "Дерево пустое\n";
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
inline int Tree<T>::getTreeHeight(Item*& root)
{
	// Итеративный алгоритм с методички
	int h1 = 0, h2 = 0;
	if (!root) {
		return 0;
	}
	if (root->left) {
		h2 = getTreeHeight(root->left);
	}
	if (root->right) {
		h1 = getTreeHeight(root->right);
	}
	return (std::max(h1, h2) + 1);
}

template<typename T>
inline int Tree<T>::getDepth(Item*& target)
{
	Item* current = target;
	int depth = 1;
	while (current != root) {
		current = current->parent;
		depth++;
	}
	return depth;
}

template<typename T>
inline bool Tree<T>::isContain(INT_64 key, Item*& root)
{
	while (root) {
		if (key == root->key) {
			return true;
		}
		else if (key < root->key) {
			root = root->left;
		}
		else if (key > root->key) {
			root = root->right;
		}
	}
	return false;
}

template<typename T>
inline int Tree<T>::getViewedItems()
{
	return viewedItems;
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
	// Итеративный алгоритм с методички
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
	// Возвращение к корню дерева
	while (it.obj->parent) {
		it.obj = it.obj->parent;
	}
	std::stack<Item*> stack;
	// Помещаем корень в стек
	stack.push(it.obj);
	while (!stack.empty()) {
		// Буфер текущего элемента важен
		Item* current = stack.top();
		// Достаём элемент, помещаем в стек его потомков
		stack.pop();
		if (current->right) {
			stack.push(current->right);
		}
		if (current->left) {
			stack.push(current->left);
		}
		// Если нашли итератор, отдаём следующему элементу в стеке
		if (current == this->obj && stack.size()) {
			it.obj = stack.top();
			break;
		}
		else if (!stack.size()) {
			std::cout << "Выход за пределы!\n";
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
		std::cout << "Выход за пределы!\n";
		return;
	}
	// Возвращение к корню дерева
	while (it.obj->parent) {
		it.obj = it.obj->parent;
	}
	std::stack<Item*> stack;
	// Помещаем корень в стек
	stack.push(it.obj);
	while (!stack.empty()) {
		// Буфер текущего элемента важен
		Item* current = stack.top();
		// Достаём элемент, помещаем в стек его потомков
		stack.pop();
		if (current->right) {
			stack.push(current->right);
		}
		if (current->left) {
			stack.push(current->left);
		}
		// Если нашли итератор, отдаём предыдущему (буфер) элементу в стеке
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
	// Итеративный алгоритм с методички
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
		std::cout << "Выход за пределы!\n";
		return;
	}
	// Возвращение к корню дерева
	while (it.obj->parent) {
		it.obj = it.obj->parent;
	}
	std::stack<Item*> stack;
	// Помещаем корень в стек
	stack.push(it.obj);
	while (!stack.empty()) {
		// Буфер текущего элемента важен
		Item* current = stack.top();
		// Достаём элемент, помещаем в стек его потомков
		stack.pop();
		if (current->right) {
			stack.push(current->right);
		}
		if (current->left) {
			stack.push(current->left);
		}
		// Если нашли итератор, отдаём предыдущему (буфер) элементу в стеке
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
	// Возвращение к корню дерева
	while (it.obj->parent) {
		it.obj = it.obj->parent;
	}	
	std::stack<Item*> stack;
	// Помещаем корень в стек
	stack.push(it.obj);
	while (!stack.empty()) {
		// Буфер текущего элемента важен
		Item* current = stack.top();
		// Достаём элемент, помещаем в стек его потомков
		stack.pop();
		if (current->right) {
			stack.push(current->right);
		}
		if (current->left) {
			stack.push(current->left);
		}
		// Если нашли итератор, отдаём следующему элементу в стеке
		if (current == this->obj && stack.size()) {
			it.obj = stack.top();
			break;
		}
		else if (!stack.size()) {
			std::cout << "Выход за пределы!\n";
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