#include <iostream>
#include "tree.h"

typedef unsigned long long INT_64;

//���������� � ��������� ���������� LineRand()
static INT_64 RRand = 15750;
const INT_64 mRand = (1 << 63) - 1;
const INT_64 aRand = 6364136223846793005;
const INT_64 cRand = 1442695040888963407;

//������� ��������� ������� ���������� ����� �� �����
//����������
void sRand()
{
	srand(time(0));
	RRand = (INT_64)rand();
}

//������� ��������� ���������� �����
//�������� ������������ ��������� Xi+1=(a*Xi+c)%m
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
	//�������� ������ ��� 64 � ��������� ������ ���� INT_64
	Tree<int, INT_64> tree;
	//������ ��� ������, ������� ������������ � ������
	INT_64* m = new INT_64[n];
	//��������� ������� ���������� �����
	sRand();
	//���������� ������ � ������� ����������
	//�� ���������� �������
	for (int i = 0; i < n; i++)
	{
		m[i] = LineRand();
		tree.viewedItems = 1;
		tree.add(m[i], 1, tree.root, tree.root);
	}
	//����� ������� ������ �� �����
	std::cout << "items count:" << tree.getSize() << std::endl;
	//��������� ��������� ����������� �������,
	//�������� � ������
	double I = 0;
	double D = 0;
	double S = 0;
	//��������� ������ ��������, 10% - ������� ��������
	for (int i = 0; i < n / 2; i++)
		if (i % 10 == 0) //10% ��������
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
			//��������� ���������� ��� ������ �������� ������
			catch (int) 
			{ 
				S += tree.getViewedItems(); 
			}
		}
		else //90% �������� ��������
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
			//��������� ���������� ��� ������ �������� ������
			catch (int) 
			{ 
				S += tree.getViewedItems(); 
			}
		} //����� �����
	   //����� �����������:
	   //����� ������� ������ ����� �����
	std::cout << "items count:" << tree.getSize() << std::endl;
	//������������� ������ ����������� �������� BST
	std::cout << "1.39*log2(n)=" << 1.39 * (log((double)n) / log(2.0)) << std::endl;
	//����������������� ������ ����������� �������
	std::cout << "Count insert: " << I / (n / 2) << std::endl;
	//����������������� ������ ����������� ��������
	std::cout << "Count delete: " << D / (n / 2) << std::endl;
	//����������������� ������ ����������� ������
	std::cout << "Count search: " << S / (n / 2) << std::endl;
	//������������ ������ ������� m[]
	delete[] m;
}

void test_ord(int n)
{
	//�������� ������ ��� 64 � ��������� ������ ���� INT_64
	Tree<int, INT_64> tree;
	//������ ��� ������, ������� ������������ � ������
	INT_64* m = new INT_64[n];
	//���������� ������ � ������� ����������
	// � ������������� ������� �������
	//�� ��������� [0, 10000, 20000, ... ,10000*n]
	for (int i = 0; i < n; i++) 
	{
		m[i] = i * 10000;
		tree.viewedItems = 1;
		tree.add(m[i], 1, tree.root, tree.root);
	}
	//����� ������� ������ �� �����
	std::cout << "items count:" << tree.getSize() << std::endl;
	//��������� ��������� ����������� �������,
	// �������� � ������
	double I = 0;
	double D = 0;
	double S = 0;
	//��������� ������� ���������� �����
	sRand();
	//��������� ������ ��������, 10% - ������� ��������
	for (int i = 0; i < n / 2; i++)
	{
		if (i % 10 == 0) //10% ��������
		{
			int k = LineRand() % (10000 * n);
			k = k + !(k % 2); //��������� �������� ����
			tree.viewedItems = 1;
			tree.deleteItem(k, tree.root);
			D += tree.getViewedItems();
			tree.viewedItems = 1;
			tree.add(m[rand() % n], 1, tree.root, tree.root);
			I += tree.getViewedItems();
			k = LineRand() % (10000 * n);
			k = k + !(k % 2); // ��������� �������� ����
			try 
			{
				tree.viewedItems = 1;
				tree.read(k, tree.root);
				S += tree.getViewedItems();
			}
			//��������� ���������� ��� ������ �������� ������
			catch (int) 
			{ 
				S += tree.getViewedItems(); 
			}
		}
		else //90% �������� ��������
		{
			int ind = rand() % n;
			tree.viewedItems = 1;
			tree.deleteItem(m[ind], tree.root);
			D += tree.getViewedItems();;
			int k = LineRand() % (10000 * n);
			k = k + k % 2; // ��������� ������ ����
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
			//��������� ���������� ��� ������ �������� ������
			catch (int) 
			{ 
				S += tree.getViewedItems(); 
			}
		}
	}
	//����� �����������:
	// ����� ������� ������ ����� �����
	std::cout << "items count:" << tree.getSize() << std::endl;
	//������������� ������ ����������� �������� BST
	std::cout << "n/2 =" << n / 2 << std::endl;
	//����������������� ������ ����������� �������
	std::cout << "Count insert: " << I / (n / 2) << std::endl;
	//����������������� ������ ����������� ��������
	std::cout << "Count delete: " << D / (n / 2) << std::endl;
	//����������������� ������ ����������� ������
	std::cout << "Count search: " << S / (n / 2) << std::endl;
	//������������ ������ ������� m[]
	delete[] m;
} //����� �����

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
	std::exception exception("����������");

	// ��� �������
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
		"\n\t1.  �������� ������ ������\n" ,
		"\t2.  �������� ������\n" , 
		"\t3.  ��������� ������ �� �������\n" ,
		"\t4.  ��������� ��������\n" ,
		"\t5.  �������� ��������\n" ,
		"\t6.  �������� ��������\n" ,
		"\t7.  ������� ��������\n" ,
		"\t8.  ������� ������ � �������\n" ,
		"\t9.  �������� � ����������\n" ,
		"\t10. �������� � �������� ����������\n" ,
		"\t11. �������������� ��������\n" ,
		"\t0. ����� �� ���������\n" ,
		"\n������� ����� ��������: " 
	};
	std::string iteratorMenu[]
	{
		"\n\t1.  ��������� begin() ���������\n" ,
		"\t2.  ��������� end() ���������\n" ,
		"\t3.  ������� �������� ���������\n" ,
		"\t4.  �������� �������� ���������\n" ,
		"\t5.  ��������� iterator++\n" ,
		"\t6.  ��������� iterator--\n" ,
		"\t7.  ���������, ����� �� �������� begin()\n" ,
		"\t8.  ���������, ����� �� �������� end()\n" ,
		"\t9.  ���������, �� ����� �� �������� begin()\n" ,
		"\t10. ���������, �� ����� �� �������� end()\n" ,
		"\t0. ��������� �����\n" ,
		"\n������� ����� ��������: "
	};
	std::string reverseIteratorMenu[] 
	{
		"\n\t1. ��������� rbegin() ��������� ���������\n" ,
		"\t2. ��������� rend() ��������� ���������\n" ,
		"\t3. ������� �������� ��������� ���������\n" ,
		"\t4. �������� �������� ��������� ���������\n" ,
		"\t5. ��������� reverseIterator++\n" ,
		"\t6. ��������� reverseIterator--\n" ,
		"\t7. ���������, ����� �� �������� �������� rbegin()\n" ,
		"\t8. ���������, ����� �� �������� rend()\n" ,
		"\t9. ���������, �� ����� �� �������� �������� rbegin()\n" ,
		"\t10. ���������, �� ����� �� �������� �������� rend()\n" ,
		"\t0. ��������� �����\n" ,
		"\n������� ����� ��������: "
	};
	std::string extraMenu[]
	{
		"\n\t1. ������� ����� ������� t_Lt_Rt\n" ,
		"\t2. ���������� ������ ������\n" ,
		"\t3. ������� ������ � ������� �����������\n" ,
		"\t4. ���� ����������� ���������� ������\n" ,
		"\t5. ���� ����������� ������������ ������\n" ,
		"\t0. ��������� �����\n" ,
		"\n������� ����� ��������: "
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
				std::cout << "������� ���� ";
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
				std::cout << "������� ���� ";
				std::cin >> key;
				std::cout << "������� ����� �������� ";
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
				std::cout << "������� ���� ";
				std::cin >> key;
				std::cout << "������� ����� �������� ";
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
				std::cout << "������� ���� ";
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
						std::cout << "������� ����� �������� ";
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
						std::cout << "������� ������� �� ����������\n";
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
						std::cout << "������� ����� �������� ";
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
						std::cout << "������� ������� �� ����������\n";
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
						std::cout << "������� ������ ";
						std::cin >> value;
						test_rand(value);
						break;
					case 5:
						std::cout << "������� ������ ";
						std::cin >> value;
						test_ord(value);
						break;
					case 0:
						exit = true;
						break;
					default:
						std::cout << "������� ������� �� ����������\n";
						break;
					}
				}
				exit = false;
				break;
			case 0:
				exit = true;
				break;
			default:
				std::cout << "������� ������� �� ����������\n";
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