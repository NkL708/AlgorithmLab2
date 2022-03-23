//#include "tree.h"
//#define TYPE std::string
//
//int main() {
//	setlocale(LC_ALL, "Russian");
//	Tree<TYPE> tree;
//	Tree<TYPE>::Iterator iterator;
//	Tree<TYPE>::ReverseIterator reverseIterator;
//	TYPE value;
//	int sw = 0, key;
//	bool exit = false;
//
//	// Для отладки
//	tree.add(25, "String1", tree.root, tree.root);
//	tree.add(13, "String2", tree.root, tree.root);
//	tree.add(100, "String3", tree.root, tree.root);
//	//tree.add(15, "String4", tree.root, tree.root);
//	//tree.add(2, "String5", tree.root, tree.root);
//	//tree.add(63, "String6", tree.root, tree.root);
//	//tree.add(8, "String7", tree.root, tree.root);
//	//tree.add(42, "String8", tree.root, tree.root);
//
//	std::exception exception("Исключение");
//
//	while (!exit) {
//		std::cout << "\n\tСПИСОК ОПЕРАЦИЙ\n";
//		std::cout << "\t1. Получить размер дерева\n";
//		std::cout << "\t2. Очистить дерево\n";
//		std::cout << "\t3. Проверить дерево на пустоту\n";
//		std::cout << "\t4. Чтение значения по ключу\n";
//		std::cout << "\t5. Изменить значение по ключу\n";
//		std::cout << "\t6. Добавить значение по ключу\n";
//		std::cout << "\t7. Удалить значение по ключу\n";
//		std::cout << "\t8. Вывести дерево в консоль (Горизонтально)\n";
//		std::cout << "\t9. Вывести дерево в консоль (Вертикально)\n";
//		std::cout << "\t10. Вывести ключи методом t_Lt_Rt\n";
//		std::cout << "\t11. Присвоить begin() итератору\n";
//		std::cout << "\t12. Присвоить end() итератору\n";
//		std::cout << "\t13. Вывести значение итератора\n";
//		std::cout << "\t14. Выполнить iterator++\n";
//		std::cout << "\t15. Выполнить iterator--\n";
//		std::cout << "\t16. Проверить, равен ли итератор begin()\n";
//		std::cout << "\t17. Проверить, равен ли итератор end()\n";
//		std::cout << "\t18. Проверить, не равен ли итератор begin()\n";
//		std::cout << "\t19. Проверить, не равен ли итератор end()\n";
//		std::cout << "\t20. Присвоить rbegin() обратному итератору\n";
//		std::cout << "\t21. Присвоить rend() обратному итератору\n";
//		std::cout << "\t22. Вывести значение обратного итератора\n";
//		std::cout << "\t23. Выполнить reverseIterator++\n";
//		std::cout << "\t24. Выполнить reverseIterator--\n";
//		std::cout << "\t25. Проверить, равен ли обратный итератор rbegin()\n";
//		std::cout << "\t26. Проверить, равен ли итератор rend()\n";
//		std::cout << "\t27. Проверить, не равен ли обртаный итератор rbegin()\n";
//		std::cout << "\t28. Проверить, не равен ли обртаный итератор rend()\n";
//		std::cout << "\t29. Вычисление высоты дерева\n";
//		std::cout << "\t30. Выход из программы\n\n";
//		std::cout << "Введите номер операции: \n";
//		std::cin >> sw;
//		try {
//			switch (sw) {
//			case 1:
//				std::cout << tree.getSize();
//				break;
//			case 2:
//				tree.clear(tree.root);
//				break;
//			case 3:
//				std::cout << tree.isEmpty();
//				break;
//			case 4:
//				std::cout << "Введите ключ ";
//				std::cin >> key;
//				if (tree.isContain(tree.root, key)) {
//					std::cout << tree.read(key, tree.root) << std::endl;
//				}
//				else {
//					throw exception;
//				}
//				break;
//			case 5:
//				std::cout << "Введите ключ ";
//				std::cin >> key;
//				std::cout << "Введите новое значение ";
//				std::cin >> value;
//				if (tree.isContain(tree.root, key)) {
//					tree.edit(key, value, tree.root);
//				}
//				else {
//					throw exception;
//				}
//				break;
//			case 6:
//				std::cout << "Введите ключ ";
//				std::cin >> key;
//				std::cout << "Введите новое значение ";
//				std::cin >> value;
//				if (!tree.isContain(tree.root, key)) {
//					tree.add(key, value, tree.root, tree.root);
//				}
//				else {
//					throw exception;
//				}
//				break;
//			case 7:
//				std::cout << "Введите ключ ";
//				std::cin >> key;
//				if (tree.isContain(tree.root, key)) {
//					tree.deleteItem(key, tree.root);
//				}
//				else {
//					throw exception;
//				}
//				break;
//			case 8:
//				tree.printHorizontal(tree.root);
//				break;
//			case 9:
//				tree.printVertical(tree.root);
//				break;
//			case 10:
//				tree.t_Lt_Rt(tree.root);
//				break;
//			case 11:
//				iterator = tree.begin();
//				break;
//			case 12:
//				iterator = tree.end();
//				break;
//			case 13:
//				std::cout << *iterator;
//				break;
//			case 14:
//				iterator++;
//				break;
//			case 15:
//				iterator--;
//				break;
//			case 16:
//				std::cout << (iterator == tree.begin());
//				break;
//			case 17:
//				std::cout << (iterator == tree.end());
//				break;
//			case 18:
//				std::cout << (iterator != tree.begin());
//				break;
//			case 19:
//				std::cout << (iterator != tree.end());
//				break;
//			case 20:
//				reverseIterator = tree.rBegin();
//				break;
//			case 21:
//				reverseIterator = tree.rEnd();
//				break;
//			case 22:
//				std::cout << *reverseIterator;
//				break;
//			case 23:
//				reverseIterator++;
//				break;
//			case 24:
//				reverseIterator--;
//				break;
//			case 25:
//				std::cout << (reverseIterator == tree.rBegin());
//				break;
//			case 26:
//				std::cout << (reverseIterator == tree.rEnd());
//				break;
//			case 27:
//				std::cout << (reverseIterator != tree.rBegin());
//				break;
//			case 28:
//				std::cout << (reverseIterator != tree.rEnd());
//				break;
//			case 29:
//				std::cout << tree.getTreeHeight(tree.root);
//				break;
//			case 30:
//				exit = true;
//				break;
//			default:
//				std::cout << "Данного индекса не существует\n";
//				break;
//			}
//		}
//		catch (const std::exception& exception) {
//			std::cout << exception.what();
//		}
//
//	}
//	return 0;
//}

// Вычисление трудоёмкости	|
//							|
//							V

#include <time.h>
#include <math.h>
#include <iostream>
#include "tree.h"

using namespace std;
typedef unsigned long long INT_64;

//переменная и константы генератора LineRand()
static INT_64 RRand = 15750;
const INT_64 mRand = (1 << 63) - 1;
const INT_64 aRand = 6364136223846793005;
const INT_64 cRand = 1442695040888963407;
//функция установки первого случайного числа от часов
//компьютера
void sRand() 
{ 
	srand(time(0)); 
	RRand = (INT_64)rand(); 
}
//функция генерации случайного числа
//линейный конгруэнтный генератор Xi+1=(a*Xi+c)%m
//habr.com/ru/post/208178
INT_64 LineRand()
{
	INT_64 y1, y2;
	y1 = (aRand * RRand + cRand) % mRand;
	y2 = (aRand * y1 + cRand) % mRand;
	RRand = y1 & 0xFFFFFFFF00000000LL ^ (y2 &
		0xFFFFFFFF00000000LL) >> 32;
	return RRand;
}

void test_rand(int n)
{
	//создание дерева для 64 – разрядных ключей типа INT_64
	Tree<INT_64> tree;
	//массив для ключей, которые присутствуют в дереве
	INT_64* m = new INT_64[n];
	//установка первого случайного числа
	sRand();
	//заполнение дерева и массива элементами
	//со случайными ключами
	for (int i = 0; i < n; i++)
	{
		m[i] = LineRand();
		tree.viewedItems = 1;
		tree.add(m[i], 1, tree.root, tree.root);
	}
	//вывод размера дерева до теста
	cout << "items count:" << tree.getSize() << endl;
	//обнуление счётчиков трудоёмкости вставки,
	//удаления и поиска
	double I = 0;
	double D = 0;
	double S = 0;
	//генерация потока операций, 10% - промахи операций
	for (int i = 0; i < n / 2; i++)
		if (i % 10 == 0) //10% промахов
		{
			tree.deleteItem(LineRand(), tree.root);
			D += tree.getViewedItems();
			tree.viewedItems = 1;
			tree.add(m[rand() % n], 1, tree.root, tree.root);
			I += tree.getViewedItems();
			try {
				tree.read(LineRand(), tree.root);
				S += tree.getViewedItems();
			}
			//обработка исключения при ошибке операции поиска
			catch (int) { S += tree.getViewedItems(); }
		}
		else //90% успешных операций
		{
			int ind = rand() % n;
			tree.deleteItem(m[ind], tree.root);
			D += tree.getViewedItems();
			INT_64 key = LineRand();
			tree.viewedItems = 1;
			tree.add(key, 1, tree.root, tree.root);
			I += tree.getViewedItems();
			m[ind] = key;
			try {
				tree.read(m[rand() % n], tree.root);
				S += tree.getViewedItems();
			}
				//обработка исключения при ошибке операции поиска
				catch (int) { S += tree.getViewedItems(); }
		} //конец теста
	   //вывод результатов:
	   //вывод размера дерева после теста
	cout << "items count:" << tree.getSize() << endl;
	//теоретической оценки трудоёмкости операций BST
	cout << "1.39*log2(n)=" << 1.39 * (log((double)n) / log(2.0)) << endl;
	//экспериментальной оценки трудоёмкости вставки
	cout << "Count insert: " << I / (n / 2) << endl;
	//экспериментальной оценки трудоёмкости удаления
	cout << "Count delete: " << D / (n / 2) << endl;
	//экспериментальной оценки трудоёмкости поиска
	cout << "Count search: " << S / (n / 2) << endl;
	//освобождение памяти массива m[]
	delete[] m;
}

int main() 
{
	setlocale(LC_ALL, "Russian");
	int n = 100;
	test_rand(n);
	//test_ord(n);
	return 0;
}