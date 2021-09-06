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
		cout << "1. �������� ������ ������" << endl;
		cout << "2. �������� ������" << endl;
		cout << "3. ��������� ������ �� �������" << endl;
		cout << "4. ������ �������� �� �����" << endl;
		cout << "5. �������� �������� �� �����" << endl;
		cout << "6. �������� �������� �� �����" << endl;
		cout << "7. ������� �������� �� �����" << endl;
		cout << "8. ������� �������� ������ � �������" << endl;
		cout << "9. ������� ����� ������� t_Lt_Rt" << endl;
		cout << "10. ��������� begin() ���������" << endl;
		cout << "11. ��������� end() ���������" << endl;
		cout << "12. ��������� iterator++" << endl;
		cout << "13. ��������� iterator--" << endl;
		cout << "14. ���������, ����� �� �������� begin()" << endl;
		cout << "15. ���������, ����� �� �������� end()" << endl;
		cout << "16. ���������, �� ����� �� �������� begin()" << endl;
		cout << "17. ���������, �� ����� �� �������� end()" << endl;
		cout << "18. ��������� rbegin() ��������� ���������" << endl;
		cout << "19. ��������� rend() ��������� ���������" << endl;
		cout << "20. ��������� reverseiterator++" << endl;
		cout << "21. ��������� reverseiterator--" << endl;
		cout << "22. ���������, ����� �� �������� �������� rbegin()" << endl;
		cout << "23. ���������, ����� �� �������� rend()" << endl;
		cout << "24. ���������, �� ����� �� �������� �������� rbegin()" << endl;
		cout << "25. ���������, �� ����� �� �������� �������� rend()" << endl;
		cout << endl;
		cout << "������� ����� ��������: ";
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
			tree.Add(key, value, tree.root);
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
			cout << "������� ������� �� ����������" << endl;
			break;
		}
	}
	return 1;
}