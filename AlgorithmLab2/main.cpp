#include <iostream>
#include "tree.h"

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
	Tree<int, INT_64> tree;
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
	std::cout << "items count:" << tree.getSize() << std::endl;
	//обнуление счётчиков трудоёмкости вставки,
	//удаления и поиска
	double I = 0;
	double D = 0;
	double S = 0;
	//генерация потока операций, 10% - промахи операций
	for (int i = 0; i < n / 2; i++)
		if (i % 10 == 0) //10% промахов
		{
			tree.viewedItems = 1;
			tree.deleteItem(LineRand(), tree.root);
			D += tree.getViewedItems();
			tree.viewedItems = 1;
			tree.add(m[rand() % n], 1, tree.root, tree.root);
			I += tree.getViewedItems();
			try 
			{
				tree.viewedItems = 1;
				tree.read(LineRand(), tree.root);
				S += tree.getViewedItems();
			}
			//обработка исключения при ошибке операции поиска
			catch (int) 
			{ 
				S += tree.getViewedItems(); 
			}
		}
		else //90% успешных операций
		{
			int ind = rand() % n;
			tree.viewedItems = 1;
			tree.deleteItem(m[ind], tree.root);
			D += tree.getViewedItems();
			INT_64 key = LineRand();
			tree.viewedItems = 1;
			tree.add(key, 1, tree.root, tree.root);
			I += tree.getViewedItems();
			m[ind] = key;
			try
			{
				tree.viewedItems = 1;
				tree.read(m[rand() % n], tree.root);
				S += tree.getViewedItems();
			}
			//обработка исключения при ошибке операции поиска
			catch (int) 
			{ 
				S += tree.getViewedItems(); 
			}
		} //конец теста
	   //вывод результатов:
	   //вывод размера дерева после теста
	std::cout << "items count:" << tree.getSize() << std::endl;
	//теоретической оценки трудоёмкости операций BST
	std::cout << "1.39*log2(n)=" << 1.39 * (log((double)n) / log(2.0)) << std::endl;
	//экспериментальной оценки трудоёмкости вставки
	std::cout << "Count insert: " << I / (n / 2) << std::endl;
	//экспериментальной оценки трудоёмкости удаления
	std::cout << "Count delete: " << D / (n / 2) << std::endl;
	//экспериментальной оценки трудоёмкости поиска
	std::cout << "Count search: " << S / (n / 2) << std::endl;
	//освобождение памяти массива m[]
	delete[] m;
}

void test_ord(int n)
{
	//создание дерева для 64 – разрядных ключей типа INT_64
	Tree<int, INT_64> tree;
	//массив для ключей, которые присутствуют в дереве
	INT_64* m = new INT_64[n];
	//заполнение дерева и массива элементами
	// с возрастающими чётными ключами
	//на интервале [0, 10000, 20000, ... ,10000*n]
	for (int i = 0; i < n; i++) 
	{
		m[i] = i * 10000;
		tree.viewedItems = 1;
		tree.add(m[i], 1, tree.root, tree.root);
	}
	//вывод размера дерева до теста
	std::cout << "items count:" << tree.getSize() << std::endl;
	//обнуление счётчиков трудоёмкости вставки,
	// удаления и поиска
	double I = 0;
	double D = 0;
	double S = 0;
	//установка первого случайного числа
	sRand();
	//генерация потока операций, 10% - промахи операций
	for (int i = 0; i < n / 2; i++)
	{
		if (i % 10 == 0) //10% промахов
		{
			int k = LineRand() % (10000 * n);
			k = k + !(k % 2); //случайный нечётный ключ
			tree.viewedItems = 1;
			tree.deleteItem(k, tree.root);
			D += tree.getViewedItems();
			tree.viewedItems = 1;
			tree.add(m[rand() % n], 1, tree.root, tree.root);
			I += tree.getViewedItems();
			k = LineRand() % (10000 * n);
			k = k + !(k % 2); // случайный нечётный ключ
			try 
			{
				tree.viewedItems = 1;
				tree.read(k, tree.root);
				S += tree.getViewedItems();
			}
			//обработка исключения при ошибке операции поиска
			catch (int) 
			{ 
				S += tree.getViewedItems(); 
			}
		}
		else //90% успешных операций
		{
			int ind = rand() % n;
			tree.viewedItems = 1;
			tree.deleteItem(m[ind], tree.root);
			D += tree.getViewedItems();;
			int k = LineRand() % (10000 * n);
			k = k + k % 2; // случайный чётный ключ
			tree.viewedItems = 1;
			tree.add(k, 1, tree.root, tree.root);
			I += tree.getViewedItems();;
			m[ind] = k;
			try 
			{
				tree.viewedItems = 1;
				tree.read(m[rand() % n], tree.root);
				S += tree.getViewedItems();;
			}
			//обработка исключения при ошибке операции поиска
			catch (int) 
			{ 
				S += tree.getViewedItems(); 
			}
		}
	}
	//вывод результатов:
	// вывод размера дерева после теста
	std::cout << "items count:" << tree.getSize() << std::endl;
	//теоретической оценки трудоёмкости операций BST
	std::cout << "n/2 =" << n / 2 << std::endl;
	//экспериментальной оценки трудоёмкости вставки
	std::cout << "Count insert: " << I / (n / 2) << std::endl;
	//экспериментальной оценки трудоёмкости удаления
	std::cout << "Count delete: " << D / (n / 2) << std::endl;
	//экспериментальной оценки трудоёмкости поиска
	std::cout << "Count search: " << S / (n / 2) << std::endl;
	//освобождение памяти массива m[]
	delete[] m;
} //конец теста

int main() 
{
	setlocale(LC_ALL, "Russian");
	Tree<int, INT_64> tree;
	Tree<int, INT_64>::Iterator iterator;
	Tree<int, INT_64>::ReverseIterator reverseIterator;
	int value;
	INT_64 key;
	int sw = 0;
	bool exit = false;
	std::exception exception("Исключение");

	// Для отладки
	//tree.add(25, "String1", tree.root, tree.root);
	//tree.add(13, "String2", tree.root, tree.root);
	//tree.add(100, "String3", tree.root, tree.root);
	//tree.add(15, "String4", tree.root, tree.root);
	//tree.add(2, "String5", tree.root, tree.root);
	//tree.add(63, "String6", tree.root, tree.root);
	//tree.add(8, "String7", tree.root, tree.root);
	//tree.add(42, "String8", tree.root, tree.root);

	std::string firstMenu[] = 
	{
		"\n\t1.  Получить размер дерева\n" ,
		"\t2.  Очистить дерево\n" , 
		"\t3.  Проверить дерево на пустоту\n" ,
		"\t4.  Прочитать значение\n" ,
		"\t5.  Изменить значение\n" ,
		"\t6.  Добавить значение\n" ,
		"\t7.  Удалить значение\n" ,
		"\t8.  Вывести дерево в консоль\n" ,
		"\t9.  Операции с итератором\n" ,
		"\t10. Операции с обратным итератором\n" ,
		"\t11. Дополнительные операции\n" ,
		"\t0. Выход из программы\n" ,
		"\nВведите номер операции: " 
	};
	std::string iteratorMenu[]
	{
		"\n\t1.  Присвоить begin() итератору\n" ,
		"\t2.  Присвоить end() итератору\n" ,
		"\t3.  Вывести значение итератора\n" ,
		"\t4.  Изменить значение итератора\n" ,
		"\t5.  Выполнить iterator++\n" ,
		"\t6.  Выполнить iterator--\n" ,
		"\t7.  Проверить, равен ли итератор begin()\n" ,
		"\t8.  Проверить, равен ли итератор end()\n" ,
		"\t9.  Проверить, не равен ли итератор begin()\n" ,
		"\t10. Проверить, не равен ли итератор end()\n" ,
		"\t0. Вернуться назад\n" ,
		"\nВведите номер операции: "
	};
	std::string reverseIteratorMenu[] 
	{
		"\n\t1. Присвоить rbegin() обратному итератору\n" ,
		"\t2. Присвоить rend() обратному итератору\n" ,
		"\t3. Вывести значение обратного итератора\n" ,
		"\t4. Изменить значение обратного итератора\n" ,
		"\t5. Выполнить reverseIterator++\n" ,
		"\t6. Выполнить reverseIterator--\n" ,
		"\t7. Проверить, равен ли обратный итератор rbegin()\n" ,
		"\t8. Проверить, равен ли итератор rend()\n" ,
		"\t9. Проверить, не равен ли обртаный итератор rbegin()\n" ,
		"\t10. Проверить, не равен ли обртаный итератор rend()\n" ,
		"\t0. Вернуться назад\n" ,
		"\nВведите номер операции: "
	};
	std::string extraMenu[]
	{
		"\n\t1. Вывести ключи методом t_Lt_Rt\n" ,
		"\t2. Вычисление высоты дерева\n" ,
		"\t3. Вывести дерево в консоль вертикально\n" ,
		"\t4. Тест трудоёмкости случайного дерева\n" ,
		"\t5. Тест трудоёмкости вырожденного дерева\n" ,
		"\t0. Вернуться назад\n" ,
		"\nВведите номер операции: "
	};

	while (!exit) 
	{
		for (int i = 0; i < sizeof(firstMenu) / sizeof(std::string); i++)
		{
			std::cout << firstMenu[i];
		}
		std::cin >> sw;
		try
		{
			switch (sw) 
			{
			case 1:
				std::cout << tree.getSize();
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
				if (tree.isContain(key, tree.root)) 
				{
					std::cout << tree.read(key, tree.root) << std::endl;
				}
				else 
				{
					throw exception;
				}
				break;
			case 5:
				std::cout << "Введите ключ ";
				std::cin >> key;
				std::cout << "Введите новое значение ";
				std::cin >> value;
				if (tree.isContain(key, tree.root)) 
				{
					tree.edit(key, value, tree.root);
				}
				else 
				{
					throw exception;
				}
				break;
			case 6:
				std::cout << "Введите ключ ";
				std::cin >> key;
				std::cout << "Введите новое значение ";
				std::cin >> value;
				if (!tree.isContain(key, tree.root)) 
				{
					tree.add(key, value, tree.root, tree.root);
				}
				else 
				{
					throw exception;
				}
				break;
			case 7:
				std::cout << "Введите ключ ";
				std::cin >> key;
				if (tree.isContain(key, tree.root)) 
				{
					tree.deleteItem(key, tree.root);
				}
				else 
				{
					throw exception;
				}
				break;
			case 8:
				tree.printHorizontal(tree.root);
				break;
			// Iterator
			case 9:
				while (!exit)
				{
					for (int i = 0; i < sizeof(iteratorMenu) / sizeof(std::string); i++)
					{
						std::cout << iteratorMenu[i];
					}
					std::cin >> sw;
					switch (sw)
					{
					case 1:
						iterator = tree.begin();
						break;
					case 2:
						iterator = tree.end();
						break;
					case 3:
						std::cout << *iterator;
						break;
					case 4:
						std::cout << "Введите новое значение ";
						std::cin >> value;
						*iterator = value;
						break;
					case 5:
						iterator++;
						break;
					case 6:
						iterator--;
						break;
					case 7:
						std::cout << (iterator == tree.begin());
						break;
					case 8:
						std::cout << (iterator == tree.end());
						break;
					case 9:
						std::cout << (iterator != tree.begin());
						break;
					case 10:
						std::cout << (iterator != tree.end());
						break;
					case 0:
						exit = true;
						break;
					default:
						std::cout << "Данного индекса не существует\n";
						break;
					}
				}
				exit = false;
				break;
			// ReverseIterator
			case 10:
				while (!exit)
				{
					for (int i = 0; i < sizeof(reverseIteratorMenu) / sizeof(std::string); i++)
					{
						std::cout << reverseIteratorMenu[i];
					}
					std::cin >> sw;
					switch (sw)
					{
					case 1:
						reverseIterator = tree.rBegin();
						break;
					case 2:
						reverseIterator = tree.rEnd();
						break;
					case 3:
						std::cout << *reverseIterator;
						break;
					case 4:
						std::cout << "Введите новое значение ";
						std::cin >> value;
						*reverseIterator = value;
						break;
					case 5:
						reverseIterator++;
						break;
					case 6:
						reverseIterator--;
						break;
					case 7:
						std::cout << (reverseIterator == tree.rBegin());
						break;
					case 8:
						std::cout << (reverseIterator == tree.rEnd());
						break;
					case 9:
						std::cout << (reverseIterator != tree.rBegin());
						break;
					case 10:
						std::cout << (reverseIterator != tree.rEnd());
						break;
					case 0:
						exit = true;
						break;
					default:
						std::cout << "Данного индекса не существует\n";
						break;
					}
				}
				exit = false;
				break;
			// Extra operations
			case 11:
				while (!exit)
				{
					for (int i = 0; i < sizeof(extraMenu) / sizeof(std::string); i++)
					{
						std::cout << extraMenu[i];
					}
					std::cin >> sw;
					switch (sw)
					{
					case 1:
						tree.t_Lt_Rt(tree.root);
						break;
					case 2:
						tree.getTreeHeight(tree.root);
						break;
					case 3:
						tree.printVertical(tree.root);
						break;
					case 4:
						std::cout << "Введите размер ";
						std::cin >> value;
						test_rand(value);
						break;
					case 5:
						std::cout << "Введите размер ";
						std::cin >> value;
						test_ord(value);
						break;
					case 0:
						exit = true;
						break;
					default:
						std::cout << "Данного индекса не существует\n";
						break;
					}
				}
				exit = false;
				break;
			case 0:
				exit = true;
				break;
			default:
				std::cout << "Данного индекса не существует\n";
				break;
			}
		}
		catch (const std::exception& exception) 
		{
			std::cout << exception.what();
		}

	}
	return 0;
}