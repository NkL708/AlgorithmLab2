#include "tree.h"
#define TYPE string

int main() {
	setlocale(0, "");
	Tree<TYPE> tree;
	Tree<TYPE>::Iterator iterator;
	Tree<TYPE>::ReverseIterator reverseIterator;
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
		cout << "4. Чтение значения по ключу" << endl;
		cout << "5. Изменить значение по ключу" << endl;
		cout << "6. Добавить значение по ключу" << endl;
		cout << "7. Удалить значение по ключу" << endl;
		cout << "8. Вывести бинарное дерево в консоль" << endl;
		cout << "9. Вывести ключи методом t_Lt_Rt" << endl;
		cout << "10. Присвоить begin() итератору" << endl;
		cout << "11. Присвоить end() итератору" << endl;
		cout << "12. Выполнить iterator++" << endl;
		cout << "13. Выполнить iterator--" << endl;
		cout << "14. Проверить, равен ли итератор begin()" << endl;
		cout << "15. Проверить, равен ли итератор end()" << endl;
		cout << "16. Проверить, не равен ли итератор begin()" << endl;
		cout << "17. Проверить, не равен ли итератор end()" << endl;
		cout << "18. Присвоить rbegin() обратному итератору" << endl;
		cout << "19. Присвоить rend() обратному итератору" << endl;
		cout << "20. Выполнить reverseiterator++" << endl;
		cout << "21. Выполнить reverseiterator--" << endl;
		cout << "22. Проверить, равен ли обратный итератор rbegin()" << endl;
		cout << "23. Проверить, равен ли итератор rend()" << endl;
		cout << "24. Проверить, не равен ли обртаный итератор rbegin()" << endl;
		cout << "25. Проверить, не равен ли обртаный итератор rend()" << endl;
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
		case 6:
			cout << "Введите ключ ";
			cin >> key;
			cout << "Введите новое значение ";
			cin >> value;
			tree.Add(key, value, tree.root);
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
			iterator++;
			break;
		case 13:
			iterator--;
			break;
		case 14:
			cout << (iterator == tree.begin());
			break;
		case 15:
			cout << (iterator == tree.end());
			break;
		case 16:
			cout << (iterator != tree.begin());
			break;
		case 17:
			cout << (iterator != tree.end());
			break;
		case 18:
			reverseIterator = tree.rbegin();
			break;
		case 19:
			reverseIterator = tree.rend();
			break;
		case 20:
			reverseIterator++;
			break;
		case 21:
			reverseIterator--;
			break;
		case 22:
			cout << (reverseIterator == tree.rbegin());
			break;
		case 23:
			cout << (reverseIterator == tree.rend());
			break;
		case 24:
			cout << (reverseIterator != tree.rbegin());
			break;
		case 25:
			cout << (reverseIterator != tree.rend());
			break;
		default:
			cout << "Данного индекса не существует" << endl;
			break;
		}
	}
	return 1;
}