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
//	// ��� �������
//	tree.add(25, "String1", tree.root, tree.root);
//	tree.add(13, "String2", tree.root, tree.root);
//	tree.add(100, "String3", tree.root, tree.root);
//	//tree.add(15, "String4", tree.root, tree.root);
//	//tree.add(2, "String5", tree.root, tree.root);
//	//tree.add(63, "String6", tree.root, tree.root);
//	//tree.add(8, "String7", tree.root, tree.root);
//	//tree.add(42, "String8", tree.root, tree.root);
//
//	std::exception exception("����������");
//
//	while (!exit) {
//		std::cout << "\n\t������ ��������\n";
//		std::cout << "\t1. �������� ������ ������\n";
//		std::cout << "\t2. �������� ������\n";
//		std::cout << "\t3. ��������� ������ �� �������\n";
//		std::cout << "\t4. ������ �������� �� �����\n";
//		std::cout << "\t5. �������� �������� �� �����\n";
//		std::cout << "\t6. �������� �������� �� �����\n";
//		std::cout << "\t7. ������� �������� �� �����\n";
//		std::cout << "\t8. ������� ������ � ������� (�������������)\n";
//		std::cout << "\t9. ������� ������ � ������� (�����������)\n";
//		std::cout << "\t10. ������� ����� ������� t_Lt_Rt\n";
//		std::cout << "\t11. ��������� begin() ���������\n";
//		std::cout << "\t12. ��������� end() ���������\n";
//		std::cout << "\t13. ������� �������� ���������\n";
//		std::cout << "\t14. ��������� iterator++\n";
//		std::cout << "\t15. ��������� iterator--\n";
//		std::cout << "\t16. ���������, ����� �� �������� begin()\n";
//		std::cout << "\t17. ���������, ����� �� �������� end()\n";
//		std::cout << "\t18. ���������, �� ����� �� �������� begin()\n";
//		std::cout << "\t19. ���������, �� ����� �� �������� end()\n";
//		std::cout << "\t20. ��������� rbegin() ��������� ���������\n";
//		std::cout << "\t21. ��������� rend() ��������� ���������\n";
//		std::cout << "\t22. ������� �������� ��������� ���������\n";
//		std::cout << "\t23. ��������� reverseIterator++\n";
//		std::cout << "\t24. ��������� reverseIterator--\n";
//		std::cout << "\t25. ���������, ����� �� �������� �������� rbegin()\n";
//		std::cout << "\t26. ���������, ����� �� �������� rend()\n";
//		std::cout << "\t27. ���������, �� ����� �� �������� �������� rbegin()\n";
//		std::cout << "\t28. ���������, �� ����� �� �������� �������� rend()\n";
//		std::cout << "\t29. ���������� ������ ������\n";
//		std::cout << "\t30. ����� �� ���������\n\n";
//		std::cout << "������� ����� ��������: \n";
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
//				std::cout << "������� ���� ";
//				std::cin >> key;
//				if (tree.isContain(tree.root, key)) {
//					std::cout << tree.read(key, tree.root) << std::endl;
//				}
//				else {
//					throw exception;
//				}
//				break;
//			case 5:
//				std::cout << "������� ���� ";
//				std::cin >> key;
//				std::cout << "������� ����� �������� ";
//				std::cin >> value;
//				if (tree.isContain(tree.root, key)) {
//					tree.edit(key, value, tree.root);
//				}
//				else {
//					throw exception;
//				}
//				break;
//			case 6:
//				std::cout << "������� ���� ";
//				std::cin >> key;
//				std::cout << "������� ����� �������� ";
//				std::cin >> value;
//				if (!tree.isContain(tree.root, key)) {
//					tree.add(key, value, tree.root, tree.root);
//				}
//				else {
//					throw exception;
//				}
//				break;
//			case 7:
//				std::cout << "������� ���� ";
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
//				std::cout << "������� ������� �� ����������\n";
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

// ���������� �����������	|
//							|
//							V

#include <time.h>
#include <math.h>
#include <iostream>
#include "tree.h"

using namespace std;
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
	Tree<INT_64> tree;
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
	cout << "items count:" << tree.getSize() << endl;
	//��������� ��������� ����������� �������,
	//�������� � ������
	double I = 0;
	double D = 0;
	double S = 0;
	//��������� ������ ��������, 10% - ������� ��������
	for (int i = 0; i < n / 2; i++)
		if (i % 10 == 0) //10% ��������
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
			//��������� ���������� ��� ������ �������� ������
			catch (int) { S += tree.getViewedItems(); }
		}
		else //90% �������� ��������
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
				//��������� ���������� ��� ������ �������� ������
				catch (int) { S += tree.getViewedItems(); }
		} //����� �����
	   //����� �����������:
	   //����� ������� ������ ����� �����
	cout << "items count:" << tree.getSize() << endl;
	//������������� ������ ����������� �������� BST
	cout << "1.39*log2(n)=" << 1.39 * (log((double)n) / log(2.0)) << endl;
	//����������������� ������ ����������� �������
	cout << "Count insert: " << I / (n / 2) << endl;
	//����������������� ������ ����������� ��������
	cout << "Count delete: " << D / (n / 2) << endl;
	//����������������� ������ ����������� ������
	cout << "Count search: " << S / (n / 2) << endl;
	//������������ ������ ������� m[]
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