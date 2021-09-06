#include "tree.h"
#define TYPE string

int main() {
	setlocale(0, "");
	Tree<TYPE> tree;
	tree.Add(10, "hello", tree.root);
	tree.Add(100, "qwe", tree.root);
	tree.Add(5, "some", tree.root);
	tree.Print(tree.root);
	//tree.t_Lt_Rt(tree.root);
	//tree.Clear(tree.root);
	//tree.Print(tree.root);
	//cout << tree.IsEmpty();
	//tree.Read(2, tree.root);
	//tree.Delete(2, tree.root);
	int sw;
	bool exit = false;
	while (!exit) {
		sw = 0;
		int key;
		TYPE value;
		cout << endl;
		cout << "1. Получить размер списка" << endl;
		cout << "2. Очистить список" << endl;
		cout << "3. Проверить список на пустоту" << endl;
		cout << "4. Чтение значение по ключу" << endl;
		cout << "5. Изменить значение по ключу" << endl;
		cout << "5. Изменить значение по ключу" << endl;
		cout << endl;
		cout << "Введите номер операции: ";
		cin >> sw;
		switch (sw) {
		case 1:
			tree.PrintSize();
			break;
		case 2:
			tree.Clear(tree.root);
			break;
		case 3:
			cout << tree.IsEmpty();
			break;
		case 4:
			cout << "Введите ключ ";
			cin >> key;
			tree.Read(key, tree.root);
			break;
		case 5:
			cout << "Введите ключ ";
			cin >> key;
			cout << "Введите новое значение ";
			cin >> value;
			tree.Edit(key, value, tree.root);
			break;
		default:
			cout << "Данного индекса не существует" << endl;
			break;
		}
	}
	return 1;
}