#pragma once
#include <iostream>
#include <iomanip>
#include <stack>
#include <queue>

template <typename Data, typename Key>
class Tree
{
	struct Node
	{
		Key key;
		Data data;
		Node* right;
		Node* left;
		Node* parent;
		int consoleW;

		Node(Key key, Data data = nullptr, Node* right = nullptr,
			Node* left = nullptr, Node* parent = nullptr, int consoleW = 0);
	};

	// Не пользовательские методы
	Node* getMinNode(Node* root);									// Поиск эл-а с минимальным ключом
	Node* getMaxNode(Node* root);									// Поиск эл-а с максимальным ключом
	int getDepth(Node*& target);									// Глубина эл-а
	void Lt_Rt_t(Node*& root);										// Схема обхода Lt_Rt_t
	static void L_t_R(Node*& root, std::queue<Node*>& queue);		// Для прямого хода
	static void L_t_R(Node*& root, std::stack<Node*>& stack);		// Для обратного хода
	
public:
	int viewedNodes = 0;
	int size = 0;
	Node* root = nullptr;

	Tree();															// Конструктор
	~Tree();														// Деструктор
	int getSize();													// Получение размера
	void clear(Node*& root);										// Очистка
	bool isEmpty();													// Проверка на пустоту
	// Основные методы
	Data read(Key key, Node*& root);								// Поиск элемента
	void edit(Key key, Data newData, Node*& root);					// Изменение элемента
	void add(Key key, Data data, Node*& root, Node*& parent);		// Добавление элемента
	void deleteNode(Key key, Node*& root);							// Удаление элемента
	// Дополнительные методы
	int getTreeHeight(Node*& root);									// Получение высоты дерева
	void t_Lt_Rt(Node*& root);										// Вывод последовательности ключей по схеме t_Lt_Rt
	// Отладочные методы
	bool isContain(Key key, Node*& root);							// Содержит ли дерево значение
	int getViewedNodes();											// Получить кол-во просмотренных эл-ов последней операцией
	void resetViewed();												// Сброс кол-ва просмотренных эл-ов
	void printTreeH(Node*& root, int indent = 0);					// Горизонтальный вывод
	void printTreeV(Node*& root);									// Вертикальный вывод

	// Итераторы
	class Iterator
	{
	public:
		Node* obj;

		Iterator(Node* obj = nullptr);
		Data& operator*();
		void operator++(int);
		void operator--(int);
		bool operator ==(const Iterator& it);
		bool operator !=(const Iterator& it);
	};
public:
	Iterator begin();
	Iterator end();

	class ReverseIterator
	{
	public:
		Node* obj;

		ReverseIterator(Node* obj = nullptr);
		Data& operator*();
		void operator++(int);
		void operator--(int);
		bool operator ==(const ReverseIterator& it);
		bool operator !=(const ReverseIterator& it);
	};

	ReverseIterator rBegin();
	ReverseIterator rEnd();
};

template<typename Data, typename Key>
inline Tree<Data, Key>::Node::Node(Key key, Data data, Node* right, Node* left, Node* parent, int consoleW)
{
	this->key = key;
	this->data = data;
	this->right = right;
	this->left = left;
	this->parent = parent;
	this->consoleW = consoleW;
}

template<typename Data, typename Key>
inline Tree<Data, Key>::Node* Tree<Data, Key>::getMinNode(Node* root)
{
	while (root) 
	{
		if (root->left)
			root = root->left;
		else
			return root;
	}
}

template<typename Data, typename Key>
inline Tree<Data, Key>::Node* Tree<Data, Key>::getMaxNode(Node* root)
{
	while (root)
	{
		if (root->right)
			root = root->right;
		else
			return root;
	}
}

template<typename Data, typename Key>
inline Tree<Data, Key>::Tree()
{

}

template<typename Data, typename Key>
inline Tree<Data, Key>::~Tree()
{
	clear(root);
}

template<typename Data, typename Key>
inline int Tree<Data, Key>::getSize()
{
	return size;
}

template<typename Data, typename Key>
inline void Tree<Data, Key>::clear(Node*& root)
{
	if (root) 
	{
		viewedNodes++;
		if (root->left) 
			clear(root->left);
		if (root->right) 
			clear(root->right);
		root = nullptr;
		size--;
	}
}

template<typename Data, typename Key>
inline bool Tree<Data, Key>::isEmpty()
{
	if (size < 0) 
		return true;
	else 
		return false;
}

template<typename Data, typename Key>
inline Data Tree<Data, Key>::read(Key key, Node*& root)
{
	if (root) 
	{
		viewedNodes++;
		if (key == root->key)
			return root->data;
		else if (key < root->key)
			return read(key, root->left);
		else
			return read(key, root->right);
	}
}

template<typename Data, typename Key>
inline void Tree<Data, Key>::edit(Key key, Data newData, Node*& root)
{
	if (root) 
	{
		viewedNodes++;
		if (key == root->key) 
			root->data = newData;
		else if (key < root->key) 
			edit(key, newData, root->left);
		else
			edit(key, newData, root->right);
	}
}

template<typename Data, typename Key>
inline void Tree<Data, Key>::add(Key key, Data data, Node*& root, Node*& parent)
{
	if (root) 
	{
		viewedNodes++;
		if (key < root->key)
			add(key, data, root->left, root);
		else
			add(key, data, root->right, root);
	}
	else 
	{
		root = new Node(key, data, nullptr, nullptr, 
			getSize() > 0 ? parent : nullptr);
		size++;
	}
}

template<typename Data, typename Key>
inline void Tree<Data, Key>::deleteNode(Key key, Node*& root)
{
	if (root) 
	{
		viewedNodes++;
		if (key < root->key)
			deleteNode(key, root->left);
		else if (key > root->key)
			deleteNode(key, root->right);
		else if (!root->left && !root->right)
			root = nullptr;
		else if (!root->left)
			root = root->right;
		else if (!root->right)
			root = root->left;
		// Есть два потомка
		else 
		{
			// Находим минимальный элемент в правом поддереве
			Node* temp = getMinNode(root->right);
			// Сохраняем его данные
			Data tempData = temp->data; Key tempKey = temp->key;
			// Удаляем его
			deleteNode(temp->key, root);
			// Вставляем его данные в удалённый элемент
			root->data = tempData;
			root->key = tempKey;
		}
	}
}

// Рекурсивный вывод
template<typename Data, typename Key>
inline void Tree<Data, Key>::printTreeH(Node*& root, int indent)
{
	if (root) 
	{
		if (root->right) 
			printTreeH(root->right, indent + 4);
		if (indent) 
			std::cout << std::setw(indent) << ' ';
		if (root->right) 
			std::cout << " /\n" << std::setw(indent) << ' ';
		std::cout << root->key << ":" << root->data << "\n ";
		if (root->left) 
		{
			std::cout << std::setw(indent) << ' ' << " \\\n";
			printTreeH(root->left, indent + 4);
		}
	}
	else
		std::cout << "Дерево пустое\n";
}

// Итеративный вывод
template<typename Data, typename Key>
inline void Tree<Data, Key>::printTreeV(Node*& root)
{
	if (root) 
	{
		int height = getTreeHeight(root);
		std::queue<Node*>* treeLevels = new std::queue<Node*>[height];
		// Заполнение очередей по уровням
		for (int i = 1; i <= height; i++) 
		{
			std::stack<Node*> stack;
			stack.push(root);
			while (!stack.empty()) 
			{
				Node* current = stack.top();
				// Достаём элемент, помещаем в стек его потомков
				stack.pop();
				if (current->right) 
					stack.push(current->right);
				if (current->left) 
					stack.push(current->left);
				// Если текущий элемент с нужного уровня дерева
				if (getDepth(current) == i) 
					treeLevels[i - 1].push(current);
			}
		}
		// Вывод всех очередей в консоль
		int step = 10;
		for (int i = 0; i < height; i++) 
		{
			bool first = true;
			while (!treeLevels[i].empty()) 
			{
				Node* current = treeLevels[i].front();
				int rNum = rand() % 3;
				int lenght;
				// Корень дерева
				if (!current->parent) 
				{
					// Примерно центр консоли
					current->consoleW = 50;
					std::cout << std::setw(current->consoleW);
				}
				// Левый
				else if (current->parent->key > current->key) 
				{
					current->consoleW = current->parent->consoleW - (step + rNum);
					lenght = current->parent->consoleW;
					std::cout << std::setw(lenght) << "/\n";
					std::cout << std::setw(current->consoleW);
				}
				// Правый
				else if (current->parent->key < current->key) 
				{
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
	else 
		std::cout << "Дерево пустое\n";
}

template<typename Data, typename Key>
inline void Tree<Data, Key>::t_Lt_Rt(Node*& root)
{
	if (root) 
	{
		std::cout << root->key << " ";
		Lt_Rt_t(root->left);
		Lt_Rt_t(root->right);
	}
}

template<typename Data, typename Key>
inline void Tree<Data, Key>::Lt_Rt_t(Node*& root)
{
	if (root) 
	{
		Lt_Rt_t(root->left);
		Lt_Rt_t(root->right);
		std::cout << root->key << " ";
	}
}

template<typename Data, typename Key>
inline int Tree<Data, Key>::getTreeHeight(Node*& root)
{
	// Итеративный алгоритм с методички
	int h1 = 0, h2 = 0;
	viewedNodes++;
	if (!root) 
		return 0;
	if (root->left) 
		h2 = getTreeHeight(root->left);
	if (root->right) 
		h1 = getTreeHeight(root->right);
	return (std::max(h1, h2) + 1);
}

template<typename Data, typename Key>
inline int Tree<Data, Key>::getDepth(Node*& target)
{
	Node* current = target;
	int depth = 1;
	while (current != root) 
	{
		viewedNodes++;
		current = current->parent;
		depth++;
	}
	return depth;
}

template<typename Data, typename Key>
inline bool Tree<Data, Key>::isContain(Key key, Node*& root)
{
	if (root)
	{
		viewedNodes++;
		if (key == root->key) 
			return true;
		else if (key < root->key) 
			return isContain(key, root->left);
		else if (key > root->key) 
			return isContain(key, root->right);
	}
	return false;
}

template<typename Data, typename Key>
inline int Tree<Data, Key>::getViewedNodes()
{
	return viewedNodes;
}

template<typename Data, typename Key>
inline void Tree<Data, Key>::resetViewed()
{
	viewedNodes = 0;
}

template<typename Data, typename Key>
inline void Tree<Data, Key>::L_t_R(Node*& root, std::queue<Node*>& queue)
{
	if (root) 
	{
		if (root->left)
			L_t_R(root->left, queue);
		// Если предыдущий элемент в рекурсии совпадает с итератором
		queue.push(root);
		if (root->right)
			L_t_R(root->right, queue);
	}
}

template<typename Data, typename Key>
inline void Tree<Data, Key>::L_t_R(Node*& root, std::stack<Node*>& stack)
{
	if (root)
	{
		if (root->left)
			L_t_R(root->left, stack);
		// Если предыдущий элемент в рекурсии совпадает с итератором
		stack.push(root);
		if (root->right)
			L_t_R(root->right, stack);
	}
}

template<typename Data, typename Key>
inline Tree<Data, Key>::Iterator Tree<Data, Key>::begin()
{
	Iterator it(getMinNode(root));
	return it;
}

template<typename Data, typename Key>
inline Tree<Data, Key>::Iterator Tree<Data, Key>::end()
{
	Iterator it(getMaxNode(root));
	return it;
}

template<typename Data, typename Key>
inline Tree<Data, Key>::Iterator::Iterator(Node* obj)
{
	this->obj = obj;
}

template<typename Data, typename Key>
inline Data& Tree<Data, Key>::Iterator::operator*()
{
	return this->obj->data;
}

template<typename Data, typename Key>
inline void Tree<Data, Key>::Iterator::operator++(int)
{
	std::queue<Node*> queue;
	Iterator root(this->obj);
	// Возвращение к корню дерева
	while (root.obj->parent)
		root.obj = root.obj->parent;
	L_t_R(root.obj, queue);
	Node* current;
	while (!queue.empty())
	{
		current = queue.front();
		queue.pop();

		// Если вышли за предел дерева
		if (queue.empty()) 
		{
			// Если вышли за предел дерева
			throw std::exception("Исключение");
		}
		// Если элемент совпадает с итератором
		// то следующий элемент итератора в коллекции
		else if (current == this->obj) 
		{
			this->obj = queue.front();
			return;
		}
	}
}

template<typename Data, typename Key>
inline void Tree<Data, Key>::Iterator::operator--(int)
{
	std::stack<Node*> stack;
	Iterator root(this->obj);
	// Возвращение к корню дерева
	while (root.obj->parent)
		root.obj = root.obj->parent;
	L_t_R(root.obj, stack);
	Node* current;
	while (!stack.empty())
	{
		current = stack.top();
		stack.pop();
		// Если вышли за предел дерева
		if (stack.empty())
		{
			// Если вышли за предел дерева
			throw std::exception("Исключение");
		}
		// Если элемент совпадает с итератором
		// то следующий элемент итератора в коллекции
		else if (current == this->obj)
		{
			this->obj = stack.top();
			return;
		}
	}
}

template<typename Data, typename Key>
inline bool Tree<Data, Key>::Iterator::operator==(const Iterator& it)
{
	if (obj == it.obj) 
		return true;
	else 
		return false;
}

template<typename Data, typename Key>
inline bool Tree<Data, Key>::Iterator::operator!=(const Iterator& it)
{
	if (obj != it.obj)
		return true;
	else 
		return false;
}

template<typename Data, typename Key>
inline Tree<Data, Key>::ReverseIterator Tree<Data, Key>::rBegin()
{
	ReverseIterator it(getMaxNode(root));
	return it;
}

template<typename Data, typename Key>
inline Tree<Data, Key>::ReverseIterator Tree<Data, Key>::rEnd()
{
	ReverseIterator it(getMinNode(root));
	return it;
}

template<typename Data, typename Key>
inline Tree<Data, Key>::ReverseIterator::ReverseIterator(Node* obj)
{
	this->obj = obj;
}

template<typename Data, typename Key>
inline Data& Tree<Data, Key>::ReverseIterator::operator*()
{
	return this->obj->data;
}


template<typename Data, typename Key>
inline void Tree<Data, Key>::ReverseIterator::operator++(int)
{
	std::stack<Node*> stack;
	Iterator root(this->obj);
	// Возвращение к корню дерева
	while (root.obj->parent)
		root.obj = root.obj->parent;
	L_t_R(root.obj, stack);
	Node* current;
	while (!stack.empty())
	{
		current = stack.top();
		stack.pop();
		// Если вышли за предел дерева
		if (stack.empty())
		{
			// Если вышли за предел дерева
			throw std::exception("Исключение");
		}
		// Если элемент совпадает с итератором
		// то следующий элемент итератора в коллекции
		else if (current == this->obj)
		{
			this->obj = stack.top();
			return;
		}
	}
}

template<typename Data, typename Key>
inline void Tree<Data, Key>::ReverseIterator::operator--(int)
{
	std::queue<Node*> queue;
	Iterator root(this->obj);
	// Возвращение к корню дерева
	while (root.obj->parent)
		root.obj = root.obj->parent;
	L_t_R(root.obj, queue);
	Node* current;
	while (!queue.empty())
	{
		current = queue.front();
		queue.pop();

		// Если вышли за предел дерева
		if (queue.empty())
		{
			// Если вышли за предел дерева
			throw std::exception("Исключение");
		}
		// Если элемент совпадает с итератором
		// то следующий элемент итератора в коллекции
		else if (current == this->obj)
		{
			this->obj = queue.front();
			return;
		}
	}
}

template<typename Data, typename Key>
inline bool Tree<Data, Key>::ReverseIterator::operator==(const ReverseIterator& it)
{
	if (obj == it.obj) 
		return true;
	else 
		return false;
}

template<typename Data, typename Key>
inline bool Tree<Data, Key>::ReverseIterator::operator!=(const ReverseIterator& it)
{
	if (obj != it.obj) 
		return true;
	else 
		return false;
}