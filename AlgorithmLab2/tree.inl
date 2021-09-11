#include "tree.h"
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
		if (root != parent)
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
inline int Tree<T>::GetHeight(Item*& root)
{
	// Итеративный алгоритм с методички
	int h1 = 0, h2 = 0;
	if (!root)
		return 0;
	if (root->left)
		h2 = GetHeight(root->left);
	if (root->right)
		h1 = GetHeight(root->right);
	return (max(h1, h2) + 1);
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
	// Итеративный алгоритм с методички
	Iterator it;
	it.obj = nullptr;
	stack<Item*> stack;
	stack.push(root);
	while (!stack.empty()) {
		Item* current = stack.top();
		it.obj = current;
		stack.pop();
		if (current->right)
			stack.push(current->right);
		if (current->left)
			stack.push(current->left);
	}
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
	// Возвращение к корню дерева
	while (it.obj->parent)
		it.obj = it.obj->parent;
	stack<Item*> stack;
	// Помещаем корень в стек
	stack.push(it.obj);
	while (!stack.empty()) {
		// Буфер текущего элемента важен
		Item* current = stack.top();
		// Достаём элемент, помещаем в стек его потомков
		stack.pop();
		if (current->right)
			stack.push(current->right);
		if (current->left)
			stack.push(current->left);
		// Если нашли итератор, отдаём следующему элементу в стеке
		if (current == this->obj && stack.size()) {
			it.obj = stack.top();
			break;
		}
		else if (!stack.size()) {
			cout << "Выход за пределы!" << endl;
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
		cout << "Выход за пределы!" << endl;
		return;
	}
	// Возвращение к корню дерева
	while (it.obj->parent)
		it.obj = it.obj->parent;
	stack<Item*> stack;
	// Помещаем корень в стек
	stack.push(it.obj);
	while (!stack.empty()) {
		// Буфер текущего элемента важен
		Item* current = stack.top();
		// Достаём элемент, помещаем в стек его потомков
		stack.pop();
		if (current->right)
			stack.push(current->right);
		if (current->left)
			stack.push(current->left);
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
	// Итеративный алгоритм с методички
	ReverseIterator it;
	it.obj = nullptr;
	stack<Item*> stack;
	stack.push(root);
	while (!stack.empty()) {
		Item* current = stack.top();
		it.obj = current;
		stack.pop();
		if (current->right)
			stack.push(current->right);
		if (current->left)
			stack.push(current->left);
	}
	return it;
}

template<typename T>
inline Tree<T>::ReverseIterator Tree<T>::rend()
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
		cout << "Выход за пределы!" << endl;
		return;
	}
	// Возвращение к корню дерева
	while (it.obj->parent)
		it.obj = it.obj->parent;
	stack<Item*> stack;
	// Помещаем корень в стек
	stack.push(it.obj);
	while (!stack.empty()) {
		// Буфер текущего элемента важен
		Item* current = stack.top();
		// Достаём элемент, помещаем в стек его потомков
		stack.pop();
		if (current->right)
			stack.push(current->right);
		if (current->left)
			stack.push(current->left);
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
	while (it.obj->parent)
		it.obj = it.obj->parent;
	stack<Item*> stack;
	// Помещаем корень в стек
	stack.push(it.obj);
	while (!stack.empty()) {
		// Буфер текущего элемента важен
		Item* current = stack.top();
		// Достаём элемент, помещаем в стек его потомков
		stack.pop();
		if (current->right)
			stack.push(current->right);
		if (current->left)
			stack.push(current->left);
		// Если нашли итератор, отдаём следующему элементу в стеке
		if (current == this->obj && stack.size()) {
			it.obj = stack.top();
			break;
		}
		else if (!stack.size()) {
			cout << "Выход за пределы!" << endl;
			return;
		}
	}
	*this = it;
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