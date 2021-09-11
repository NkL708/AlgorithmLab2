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
		cout << "1. �������� ������ ������" << endl;
		cout << "2. �������� ������" << endl;
		cout << "3. ��������� ������ �� �������" << endl;
		cout << "4. ������ �������� �� �����" << endl;
		cout << "5. �������� �������� �� �����" << endl;
		cout << "6. �������� �������� �� �����" << endl;
		cout << "7. ������� �������� �� �����" << endl;
		cout << "8. ������� ������ � �������" << endl;
		cout << "9. ������� ����� ������� t_Lt_Rt" << endl;
		cout << "10. ��������� begin() ���������" << endl;
		cout << "11. ��������� end() ���������" << endl;
		cout << "12. ������� �������� ���������" << endl;
		cout << "13. ��������� iterator++" << endl;
		cout << "14. ��������� iterator--" << endl;
		cout << "15. ���������, ����� �� �������� begin()" << endl;
		cout << "16. ���������, ����� �� �������� end()" << endl;
		cout << "17. ���������, �� ����� �� �������� begin()" << endl;
		cout << "18. ���������, �� ����� �� �������� end()" << endl;
		cout << "19. ��������� rbegin() ��������� ���������" << endl;
		cout << "20. ��������� rend() ��������� ���������" << endl;
		cout << "21. ������� �������� ��������� ���������" << endl;
		cout << "22. ��������� reverseIterator++" << endl;
		cout << "23. ��������� reverseIterator--" << endl;
		cout << "24. ���������, ����� �� �������� �������� rbegin()" << endl;
		cout << "25. ���������, ����� �� �������� rend()" << endl;
		cout << "26. ���������, �� ����� �� �������� �������� rbegin()" << endl;
		cout << "27. ���������, �� ����� �� �������� �������� rend()" << endl;
		cout << "28. ���������� ������ ������" << endl;
		cout << "29. ����� �� ���������" << endl;
		cout << endl;
		cout << "������� ����� ��������: ";
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
			cout << "������� ���� ";
			cin >> key;
			tree.Read(key, tree.root);
			break;
		case 5:
			cout << "������� ���� ";
			cin >> key;
			cout << "������� ����� �������� ";
			cin >> value;
			tree.Edit(key, value, tree.root);
			break;
		case 6:
			cout << "������� ���� ";
			cin >> key;
			cout << "������� ����� �������� ";
			cin >> value;
			tree.Add(key, value, tree.root, tree.root);
			break;
		case 7:
			cout << "������� ���� ";
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
			cout << "������� ������� �� ����������" << endl;
			break;
		}
	}
	return 1;
}