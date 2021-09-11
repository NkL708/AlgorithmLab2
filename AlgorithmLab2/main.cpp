#include "tree.h"
#define TYPE string

int main() {
	setlocale(0, "");
	Tree<TYPE> tree;
	Tree<TYPE>::Iterator iterator;
	Tree<TYPE>::ReverseIterator reverseIterator;
	int sw;
	bool exit = false;
	tree.Add(10, "10", tree.root, tree.root);
	tree.Add(9, "9", tree.root, tree.root);
	tree.Add(12, "12", tree.root, tree.root);
	tree.Add(7, "7", tree.root, tree.root);
	tree.Add(8, "8", tree.root, tree.root);
	tree.Add(11, "11", tree.root, tree.root);
	tree.Add(13, "13", tree.root, tree.root);

	while (!exit) {
		sw = 0;
		int key;
		TYPE value;
		cout << endl;
		cout << "1. Получить размер списка" << endl;
		cout << "2. Очистить список" << endl;
		cout << "3. Проверить список на пустоту" << endl;
		cout << "4. Чтение значения по ключу" << endl;
		cout << "5. Изменить значение по ключу" << endl;
		cout << "6. Добавить значение по ключу" << endl;
		cout << "7. Удалить значение по ключу" << endl;
		cout << "8. Вывести дерево в консоль" << endl;
		cout << "9. Вывести ключи методом t_Lt_Rt" << endl;
		cout << "10. Присвоить begin() итератору" << endl;
		cout << "11. Присвоить end() итератору" << endl;
		cout << "12. Вывести значение итератора" << endl;
		cout << "13. Выполнить iterator++" << endl;
		cout << "14. Выполнить iterator--" << endl;
		cout << "15. Проверить, равен ли итератор begin()" << endl;
		cout << "16. Проверить, равен ли итератор end()" << endl;
		cout << "17. Проверить, не равен ли итератор begin()" << endl;
		cout << "18. Проверить, не равен ли итератор end()" << endl;
		cout << "19. Присвоить rbegin() обратному итератору" << endl;
		cout << "20. Присвоить rend() обратному итератору" << endl;
		cout << "21. Вывести значение обратного итератора" << endl;
		cout << "22. Выполнить reverseIterator++" << endl;
		cout << "23. Выполнить reverseIterator--" << endl;
		cout << "24. Проверить, равен ли обратный итератор rbegin()" << endl;
		cout << "25. Проверить, равен ли итератор rend()" << endl;
		cout << "26. Проверить, не равен ли обртаный итератор rbegin()" << endl;
		cout << "27. Проверить, не равен ли обртаный итератор rend()" << endl;
		cout << "28. Вычисление высоты дерева" << endl;
		cout << "29. Выход из программы" << endl;
		cout << endl;
		cout << "Введите номер операции: ";
		cin >> sw;
		system("cls");
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
		case 6:
			cout << "Введите ключ ";
			cin >> key;
			cout << "Введите новое значение ";
			cin >> value;
			tree.Add(key, value, tree.root, tree.root);
			break;
		case 7:
			cout << "Введите ключ ";
			cin >> key;
			tree.Delete(key, tree.root);
			break;
		case 8:
			tree.Print(tree.root);
			break;
		case 9:
			tree.t_Lt_Rt(tree.root);
			break;
		case 10:
			iterator = tree.begin();
			break;
		case 11:
			iterator = tree.end();
			break;
		case 12:
			cout << *iterator;
			break;
		case 13:
			iterator++;
			break;
		case 14:
			iterator--;
			break;
		case 15:
			cout << (iterator == tree.begin());
			break;
		case 16:
			cout << (iterator == tree.end());
			break;
		case 17:
			cout << (iterator != tree.begin());
			break;
		case 18:
			cout << (iterator != tree.end());
			break;
		case 19:
			reverseIterator = tree.rbegin();
			break;
		case 20:
			reverseIterator = tree.rend();
			break;
		case 21:
			cout << *reverseIterator;
			break;
		case 22:
			reverseIterator++;
			break;
		case 23:
			reverseIterator--;
			break;
		case 24:
			cout << (reverseIterator == tree.rbegin());
			break;
		case 25:
			cout << (reverseIterator == tree.rend());
			break;
		case 26:
			cout << (reverseIterator != tree.rbegin());
			break;
		case 27:
			cout << (reverseIterator != tree.rend());
			break;
		case 28:
			cout << tree.GetHeight(tree.root);
			break;
		case 29:
			exit = true;
			break;
		default:
			cout << "Данного индекса не существует" << endl;
			break;
		}
	}
	return 1;
}