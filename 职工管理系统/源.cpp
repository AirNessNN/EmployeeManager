#include<stdio.h>
#include<Windows.h>
#include"struct.h"
#include<iostream>
#include<conio.h>

#define INIT (LinkedList*)malloc(sizeof(LinkedList))//����ָ���ڴ溯��

using namespace std;

LinkedList *root;			//ְ��������ڵ�
LinkedList *last;			//���Ľڵ�
int emp_count;			//ְ������



void gotoxy(int x, int y) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}







//��ʼ��
void initialize() {
	root = INIT;
	last = INIT;
	emp_count = 0;
}



//��ȡ�ļ�
void read_file_into_array() {

}






//д���ļ�
void wirte_file_from_array() {

}






//���
void add_employee() {
	while (1) {
		//����
		system("cls");

		//��������
		Employee emp;
		
		//
		cout << "�����������������ݣ����س���������һ�����ݣ�\n���\t����\t����\t����\t�ۿ�\n";
		cin >> emp.num;
		gotoxy(8, 2);
		cin >> emp.name;
		gotoxy(16, 2);
		cin >> emp.base_money;
		gotoxy(24, 2);
		cin >> emp.bonus;
		gotoxy(32, 2);
		cin >> emp.deduct_money;
		//����¼�룬�ж��ύ
		cout << "�Ƿ��ύ���ݣ�y/n\n";
		int c = _getch();
		if (c == 'n') {
			cout << "�Ƿ��ٴ��ύ��y/n\n";
			c = _getch();
			if (c == 'y')
				continue;
			else
				break;
		}
		if (c == 'y') {
			//ȷ��Ҫ�ύ
			//����
			int flag = 0;
			LinkedList *link = root->next;
			while (1) {
				if (link == NULL) {
					break;
				}
				if (link->emp.num == emp.num||strcmp(link->emp.name, emp.name) == 0) {
					cout << "�б����Ѿ����ڸ�Ա��������������Ч��" << endl;
					flag = 1;
					break;
				}
				link = link->next;
			}
			//�����ڵ�
			LinkedList *node;
			node = INIT;
			node->emp = emp;//����������
			node->next = NULL;//ָ�����ʼ��

			//����
			if (emp_count < 1) {
				root->next = node;//���Ӹ��ڵ�
			}
			else {
				last->next = node;
			}
			last = node;//����β�ڵ�
		}
		else {
			cout << "�������ٴ�¼�롣\n";
			break;
		}
		emp_count++;
		//�ٴ�����
		cout << "�Ƿ�¼����һ��Ա����y/n\n";
		c = _getch();
		if (c == 'n')
			break;
	}
}

//ɾ��
void delete_employee() {
	system("cls");
	cout << "���������ֻ��߱��";
}

//�޸�
void edit_employee() {

}

//���ҹ���
void seach() {

}






//����
void sort() {

}




//��ʾ
void show() {
	system("cls");

	if (emp_count == 0) {
		cout << "��Ա����" << endl;
	}
	else {
		cout << "\t���      \t����    \t��������  \t����\t�ۿ�    " << endl;
		LinkedList *link = root->next;
		while (1) {
			if (link == NULL) {
				break;
			}
			printf_s("%10d            %s      %8d  \t%10d  %5d\n", link->emp.num, link->emp.name, link->emp.base_money, link->emp.bonus, link->emp.deduct_money);
			link = link->next;
		}
	}
}



//�˳�
void exit_and_save() {

	wirte_file_from_array();//�˳�֮ǰ�����ļ�
	exit(0);
}



//�˵�
void menu() {
	int chioce;//�����û���ѡ��
	system("cls");//����
	if (emp_count > 0) {
		cout << "++++����ְ����" << emp_count << "��++++\n" << endl;
	}
	cout << "ְ�����ʹ���ϵͳ\n1�����ְ����Ϣ\n2���޸�ְ����Ϣ\n3��ɾ��ְ����Ϣ\n4����ʾ����Ա����Ϣ\n9���˳�\n�������ѡ��";
	cin >> chioce;
	switch (chioce)
	{
	case 1:
		add_employee();
		break;
	case 2:
		edit_employee();
		break;
	case 3:
		delete_employee();
		break;
	case 4:
		show();
		break;
	case 9:
		exit_and_save();
	default:
		cout << "\nû�����ѡ������������" << endl;
		break;
	}
	system("pause");
}





int main() {
	initialize();//��ʼ��
	read_file_into_array();//�����ȶ����ļ��������
	/*Employee e;
	LinkedList l;
	
	e.num = 10;
	e.base_money = 10;
	cin >> e.name;
	e.bonus = 10;
	e.deduct_money = 10;
	emp_count++;
	l.emp = e;
	root = &l;
	last = &l;
	l.hasNext = 0;*/

	while (1) {
		menu();
	}
}

