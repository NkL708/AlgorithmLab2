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
		std::cout << "\n\t������ ��������\n";
		std::cout << "\t1. �������� ������ ������\n";
		std::cout << "\t2. �������� ������\n";
		std::cout << "\t3. ��������� ������ �� �������\n";
		std::cout << "\t4. ������ �������� �� �����\n";
		std::cout << "\t5. �������� �������� �� �����\n";
		std::cout << "\t6. �������� �������� �� �����\n";
		std::cout << "\t7. ������� �������� �� �����\n";
		std::cout << "\t8. ������� ������ � �������\n";
		std::cout << "\t9. ������� ����� ������� t_Lt_Rt\n";
		std::cout << "\t10. ��������� begin() ���������\n";
		std::cout << "\t11. ��������� end() ���������\n";
		std::cout << "\t12. ������� �������� ���������\n";
		std::cout << "\t13. ��������� iterator++\n";
		std::cout << "\t14. ��������� iterator--\n";
		std::cout << "\t15. ���������, ����� �� �������� begin()\n";
		std::cout << "\t16. ���������, ����� �� �������� end()\n";
		std::cout << "\t17. ���������, �� ����� �� �������� begin()\n";
		std::cout << "\t18. ���������, �� ����� �� �������� end()\n";
		std::cout << "\t19. ��������� rbegin() ��������� ���������\n";
		std::cout << "\t20. ��������� rend() ��������� ���������\n";
		std::cout << "\t21. ������� �������� ��������� ���������\n";
		std::cout << "\t22. ��������� reverseIterator++\n";
		std::cout << "\t23. ��������� reverseIterator--\n";
		std::cout << "\t24. ���������, ����� �� �������� �������� rbegin()\n";
		std::cout << "\t25. ���������, ����� �� �������� rend()\n";
		std::cout << "\t26. ���������, �� ����� �� �������� �������� rbegin()\n";
		std::cout << "\t27. ���������, �� ����� �� �������� �������� rend()\n";
		std::cout << "\t28. ���������� ������ ������\n";
		std::cout << "\t29. ����� �� ���������\n\n";
		std::cout << "������� ����� ��������: \n";
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
			std::cout << "������� ������� �� ����������\n";
			break;
		}
	}
	return 1;
}