#include <iostream>
#include "tree.h"

#define TYPE int

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
	RRand = y1 & 0xFFFFFFFF00000000LL ^ (y2 & 0xFFFFFFFF00000000LL) >> 32;
	return RRand;
}

void test_rand(int n)
{
	//�������� ������ ��� 64 � ��������� ������ ���� INT_64
	Tree<TYPE> tree;
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
			tree.viewedItems = 1;
			tree.deleteItem(LineRand(), tree.root);
			D += tree.getViewedItems();
			tree.viewedItems = 1;
			tree.add(m[rand() % n], 1, tree.root, tree.root);
			I += tree.getViewedItems();
			try {
				tree.viewedItems = 1;
				tree.read(LineRand(), tree.root);
				S += tree.getViewedItems();
			}
			//��������� ���������� ��� ������ �������� ������
			catch (int) { S += tree.getViewedItems(); }
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
			try {
				tree.viewedItems = 1;
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

void test_ord(int n)
{
	//�������� ������ ��� 64 � ��������� ������ ���� INT_64
	Tree<TYPE> tree;
	//������ ��� ������, ������� ������������ � ������
	INT_64* m = new INT_64[n];
	//���������� ������ � ������� ����������
	// � ������������� ������� �������
	//�� ��������� [0, 10000, 20000, ... ,10000*n]
	for (int i = 0; i < n; i++) {
		m[i] = i * 10000;
		tree.viewedItems = 1;
		tree.add(m[i], 1, tree.root, tree.root);
	}
	//����� ������� ������ �� �����
	cout << "items count:" << tree.getSize() << endl;
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
			try {
				tree.viewedItems = 1;
				tree.read(k, tree.root);
				S += tree.getViewedItems();
			}
			//��������� ���������� ��� ������ �������� ������
			catch (int) { S += tree.getViewedItems(); }
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
			try {
				tree.viewedItems = 1;
				tree.read(m[rand() % n], tree.root);
				S += tree.getViewedItems();;
			}
			//��������� ���������� ��� ������ �������� ������
			catch (int) { S += tree.getViewedItems(); }
		}
	}
	//����� �����������:
	// ����� ������� ������ ����� �����
	cout << "items count:" << tree.getSize() << endl;
	//������������� ������ ����������� �������� BST
	cout << "n/2 =" << n / 2 << endl;
	//����������������� ������ ����������� �������
	cout << "Count insert: " << I / (n / 2) << endl;
	//����������������� ������ ����������� ��������
	cout << "Count delete: " << D / (n / 2) << endl;
	//����������������� ������ ����������� ������
	cout << "Count search: " << S / (n / 2) << endl;
	//������������ ������ ������� m[]
	delete[] m;
} //����� �����

int main() {
	setlocale(LC_ALL, "Russian");
	Tree<TYPE> tree;
	Tree<TYPE>::Iterator iterator;
	Tree<TYPE>::ReverseIterator reverseIterator;
	TYPE value;
	int sw = 0, key;
	bool exit = false;

	// ��� �������
	//tree.add(25, 1, tree.root, tree.root);
	//tree.add(13, 1, tree.root, tree.root);
	//tree.add(100, 1, tree.root, tree.root);
	//tree.add(15, 1, tree.root, tree.root);
	//tree.add(2, 1, tree.root, tree.root);
	//tree.add(63, 1, tree.root, tree.root);
	//tree.add(8, 1, tree.root, tree.root);
	//tree.add(42, 1, tree.root, tree.root);

	std::exception exception("����������");

	while (!exit) {
		std::cout << "\n\t������ ��������\n";
		std::cout << "\t1. �������� ������ ������\n";
		std::cout << "\t2. �������� ������\n";
		std::cout << "\t3. ��������� ������ �� �������\n";
		std::cout << "\t4. ������ �������� �� �����\n";
		std::cout << "\t5. �������� �������� �� �����\n";
		std::cout << "\t6. �������� �������� �� �����\n";
		std::cout << "\t7. ������� �������� �� �����\n";
		std::cout << "\t8. ������� ������ � ������� (�������������)\n";
		std::cout << "\t9. ������� ������ � ������� (�����������)\n";
		std::cout << "\t10. ������� ����� ������� t_Lt_Rt\n";
		std::cout << "\t11. ��������� begin() ���������\n";
		std::cout << "\t12. ��������� end() ���������\n";
		std::cout << "\t13. ������� �������� ���������\n";
		std::cout << "\t14. �������� �������� ���������\n";
		std::cout << "\t15. ��������� iterator++\n";
		std::cout << "\t16. ��������� iterator--\n";
		std::cout << "\t17. ���������, ����� �� �������� begin()\n";
		std::cout << "\t18. ���������, ����� �� �������� end()\n";
		std::cout << "\t19. ���������, �� ����� �� �������� begin()\n";
		std::cout << "\t20. ���������, �� ����� �� �������� end()\n";
		std::cout << "\t21. ��������� rbegin() ��������� ���������\n";
		std::cout << "\t22. ��������� rend() ��������� ���������\n";
		std::cout << "\t23. ������� �������� ��������� ���������\n";
		std::cout << "\t24. �������� �������� ��������� ���������\n";
		std::cout << "\t25. ��������� reverseIterator++\n";
		std::cout << "\t26. ��������� reverseIterator--\n";
		std::cout << "\t27. ���������, ����� �� �������� �������� rbegin()\n";
		std::cout << "\t28. ���������, ����� �� �������� rend()\n";
		std::cout << "\t29. ���������, �� ����� �� �������� �������� rbegin()\n";
		std::cout << "\t30. ���������, �� ����� �� �������� �������� rend()\n";
		std::cout << "\t31. ���������� ������ ������\n";
		std::cout << "\t32. ���� ����������� ���������� ������\n";
		std::cout << "\t33. ���� ����������� ������������ ������\n";
		std::cout << "\t34. ����� �� ���������\n\n";
		std::cout << "������� ����� ��������: \n";
		std::cin >> sw;
		try {
			switch (sw) {
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
				if (tree.isContain(key, tree.root)) {
					std::cout << tree.read(key, tree.root) << std::endl;
				}
				else {
					throw exception;
				}
				break;
			case 5:
				std::cout << "������� ���� ";
				std::cin >> key;
				std::cout << "������� ����� �������� ";
				std::cin >> value;
				if (tree.isContain(key, tree.root)) {
					tree.edit(key, value, tree.root);
				}
				else {
					throw exception;
				}
				break;
			case 6:
				std::cout << "������� ���� ";
				std::cin >> key;
				std::cout << "������� ����� �������� ";
				std::cin >> value;
				if (!tree.isContain(key, tree.root)) {
					tree.add(key, value, tree.root, tree.root);
				}
				else {
					throw exception;
				}
				break;
			case 7:
				std::cout << "������� ���� ";
				std::cin >> key;
				if (tree.isContain(key, tree.root)) {
					tree.deleteItem(key, tree.root);
				}
				else {
					throw exception;
				}
				break;
			case 8:
				tree.printHorizontal(tree.root);
				break;
			case 9:
				tree.printVertical(tree.root);
				break;
			case 10:
				tree.t_Lt_Rt(tree.root);
				break;
			case 11:
				iterator = tree.begin();
				break;
			case 12:
				iterator = tree.end();
				break;
			case 13:
				std::cout << *iterator;
				break;
			case 14:
				std::cout << "������� ����� �������� ";
				std::cin >> value;
				*iterator = value;
				break;
			case 15:
				iterator++;
				break;
			case 16:
				iterator--;
				break;
			case 17:
				std::cout << (iterator == tree.begin());
				break;
			case 18:
				std::cout << (iterator == tree.end());
				break;
			case 19:
				std::cout << (iterator != tree.begin());
				break;
			case 20:
				std::cout << (iterator != tree.end());
				break;
			case 21:
				reverseIterator = tree.rBegin();
				break;
			case 22:
				reverseIterator = tree.rEnd();
				break;
			case 23:
				std::cout << *reverseIterator;
				break;
			case 24:
				std::cout << "������� ����� �������� ";
				std::cin >> value;
				*reverseIterator = value;
				break;
			case 25:
				reverseIterator++;
				break;
			case 26:
				reverseIterator--;
				break;
			case 27:
				std::cout << (reverseIterator == tree.rBegin());
				break;
			case 28:
				std::cout << (reverseIterator == tree.rEnd());
				break;
			case 29:
				std::cout << (reverseIterator != tree.rBegin());
				break;
			case 30:
				std::cout << (reverseIterator != tree.rEnd());
				break;
			case 31:
				std::cout << tree.getTreeHeight(tree.root);
				break;
			case 32:
				std::cout << "������� ������ ";
				std::cin >> key;
				test_rand(key);
				break;
			case 33:
				std::cout << "������� ������ ";
				std::cin >> key;
				test_ord(key);
				break;
			case 34:
				exit = true;
				break;
			default:
				std::cout << "������� ������� �� ����������\n";
				break;
			}
		}
		catch (const std::exception& exception) {
			std::cout << exception.what();
		}

	}
	return 0;
}