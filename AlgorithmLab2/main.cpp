#include "tree.h"
#define TYPE std::string

int main() {
	setlocale(0, "");
	Tree<TYPE> tree;
	Tree<TYPE>::Iterator iterator;
	Tree<TYPE>::ReverseIterator reverseIterator;
	TYPE value;
	int sw = 0, key;
	bool exit = false;

	while (!exit) {
		std::cout << "\n\tСПИСОК ОПЕРАЦИЙ\n";
		std::cout << "\t1. Получить размер списка\n";
		std::cout << "\t2. Очистить список\n";
		std::cout << "\t3. Проверить список на пустоту\n";
		std::cout << "\t4. Чтение значения по ключу\n";
		std::cout << "\t5. Изменить значение по ключу\n";
		std::cout << "\t6. Добавить значение по ключу\n";
		std::cout << "\t7. Удалить значение по ключу\n";
		std::cout << "\t8. Вывести дерево в консоль\n";
		std::cout << "\t9. Вывести ключи методом t_Lt_Rt\n";
		std::cout << "\t10. Присвоить begin() итератору\n";
		std::cout << "\t11. Присвоить end() итератору\n";
		std::cout << "\t12. Вывести значение итератора\n";
		std::cout << "\t13. Выполнить iterator++\n";
		std::cout << "\t14. Выполнить iterator--\n";
		std::cout << "\t15. Проверить, равен ли итератор begin()\n";
		std::cout << "\t16. Проверить, равен ли итератор end()\n";
		std::cout << "\t17. Проверить, не равен ли итератор begin()\n";
		std::cout << "\t18. Проверить, не равен ли итератор end()\n";
		std::cout << "\t19. Присвоить rbegin() обратному итератору\n";
		std::cout << "\t20. Присвоить rend() обратному итератору\n";
		std::cout << "\t21. Вывести значение обратного итератора\n";
		std::cout << "\t22. Выполнить reverseIterator++\n";
		std::cout << "\t23. Выполнить reverseIterator--\n";
		std::cout << "\t24. Проверить, равен ли обратный итератор rbegin()\n";
		std::cout << "\t25. Проверить, равен ли итератор rend()\n";
		std::cout << "\t26. Проверить, не равен ли обртаный итератор rbegin()\n";
		std::cout << "\t27. Проверить, не равен ли обртаный итератор rend()\n";
		std::cout << "\t28. Вычисление высоты дерева\n";
		std::cout << "\t29. Выход из программы\n\n";
		std::cout << "Введите номер операции: \n";
		std::cin >> sw;
		switch (sw) {
		case 1:
			tree.printSize();
			break;
		case 2:
			tree.clear(tree.root);
			break;
		case 3:
			std::cout << tree.isEmpty();
			break;
		case 4:
			std::cout << "Введите ключ ";
			std::cin >> key;
			tree.read(key, tree.root);
			break;
		case 5:
			std::cout << "Введите ключ ";
			std::cin >> key;
			std::cout << "Введите новое значение ";
			std::cin >> value;
			tree.edit(key, value, tree.root);
			break;
		case 6:
			std::cout << "Введите ключ ";
			std::cin >> key;
			std::cout << "Введите новое значение ";
			std::cin >> value;
			tree.add(key, value, tree.root, tree.root);
			break;
		case 7:
			std::cout << "Введите ключ ";
			std::cin >> key;
			tree.deleteItem(key, tree.root);
			break;
		case 8:
			tree.print(tree.root);
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
			std::cout << *iterator;
			break;
		case 13:
			iterator++;
			break;
		case 14:
			iterator--;
			break;
		case 15:
			std::cout << (iterator == tree.begin());
			break;
		case 16:
			std::cout << (iterator == tree.end());
			break;
		case 17:
			std::cout << (iterator != tree.begin());
			break;
		case 18:
			std::cout << (iterator != tree.end());
			break;
		case 19:
			reverseIterator = tree.rBegin();
			break;
		case 20:
			reverseIterator = tree.rEnd();
			break;
		case 21:
			std::cout << *reverseIterator;
			break;
		case 22:
			reverseIterator++;
			break;
		case 23:
			reverseIterator--;
			break;
		case 24:
			std::cout << (reverseIterator == tree.rBegin());
			break;
		case 25:
			std::cout << (reverseIterator == tree.rEnd());
			break;
		case 26:
			std::cout << (reverseIterator != tree.rBegin());
			break;
		case 27:
			std::cout << (reverseIterator != tree.rEnd());
			break;
		case 28:
			std::cout << tree.getHeight(tree.root);
			break;
		case 29:
			exit = true;
			break;
		default:
			std::cout << "Данного индекса не существует\n";
			break;
		}
	}
	return 1;
}