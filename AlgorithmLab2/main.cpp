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

	// ��� �������
	//tree.add(25, "String1", tree.root, tree.root);
	//tree.add(13, "String2", tree.root, tree.root);
	//tree.add(100, "String3", tree.root, tree.root);
	//tree.add(15, "String4", tree.root, tree.root);
	//tree.add(2, "String5", tree.root, tree.root);
	//tree.add(63, "String6", tree.root, tree.root);
	//tree.add(8, "String7", tree.root, tree.root);
	//tree.add(42, "String8", tree.root, tree.root);


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
		std::cout << "\t14. ��������� iterator++\n";
		std::cout << "\t15. ��������� iterator--\n";
		std::cout << "\t16. ���������, ����� �� �������� begin()\n";
		std::cout << "\t17. ���������, ����� �� �������� end()\n";
		std::cout << "\t18. ���������, �� ����� �� �������� begin()\n";
		std::cout << "\t19. ���������, �� ����� �� �������� end()\n";
		std::cout << "\t20. ��������� rbegin() ��������� ���������\n";
		std::cout << "\t21. ��������� rend() ��������� ���������\n";
		std::cout << "\t22. ������� �������� ��������� ���������\n";
		std::cout << "\t23. ��������� reverseIterator++\n";
		std::cout << "\t24. ��������� reverseIterator--\n";
		std::cout << "\t25. ���������, ����� �� �������� �������� rbegin()\n";
		std::cout << "\t26. ���������, ����� �� �������� rend()\n";
		std::cout << "\t27. ���������, �� ����� �� �������� �������� rbegin()\n";
		std::cout << "\t28. ���������, �� ����� �� �������� �������� rend()\n";
		std::cout << "\t29. ���������� ������ ������\n";
		std::cout << "\t30. ����� �� ���������\n\n";
		std::cout << "������� ����� ��������: \n";
		std::cin >> sw;
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
			tree.read(key, tree.root);
			break;
		case 5:
			std::cout << "������� ���� ";
			std::cin >> key;
			std::cout << "������� ����� �������� ";
			std::cin >> value;
			tree.edit(key, value, tree.root);
			break;
		case 6:
			std::cout << "������� ���� ";
			std::cin >> key;
			std::cout << "������� ����� �������� ";
			std::cin >> value;
			tree.add(key, value, tree.root, tree.root);
			break;
		case 7:
			std::cout << "������� ���� ";
			std::cin >> key;
			tree.deleteItem(key, tree.root);
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
			iterator++;
			break;
		case 15:
			iterator--;
			break;
		case 16:
			std::cout << (iterator == tree.begin());
			break;
		case 17:
			std::cout << (iterator == tree.end());
			break;
		case 18:
			std::cout << (iterator != tree.begin());
			break;
		case 19:
			std::cout << (iterator != tree.end());
			break;
		case 20:
			reverseIterator = tree.rBegin();
			break;
		case 21:
			reverseIterator = tree.rEnd();
			break;
		case 22:
			std::cout << *reverseIterator;
			break;
		case 23:
			reverseIterator++;
			break;
		case 24:
			reverseIterator--;
			break;
		case 25:
			std::cout << (reverseIterator == tree.rBegin());
			break;
		case 26:
			std::cout << (reverseIterator == tree.rEnd());
			break;
		case 27:
			std::cout << (reverseIterator != tree.rBegin());
			break;
		case 28:
			std::cout << (reverseIterator != tree.rEnd());
			break;
		case 29:
			std::cout << tree.getTreeHeight(tree.root);
			break;
		case 30:
			exit = true;
			break;
		default:
			std::cout << "������� ������� �� ����������\n";
			break;
		}
	}
	return 0;
}