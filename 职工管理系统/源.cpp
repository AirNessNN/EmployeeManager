#include<stdio.h>
#include<Windows.h>
#include"struct.h"
#include<iostream>
#include<conio.h>

#define INIT (LinkedList*)malloc(sizeof(LinkedList))//分配指针内存函数

using namespace std;

LinkedList *root;			//职工链表根节点
LinkedList *last;			//最后的节点
int emp_count;			//职工数量



void gotoxy(int x, int y) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}







//初始化
void initialize() {
	root = INIT;
	last = INIT;
	emp_count = 0;
}



//读取文件
void read_file_into_array() {

}






//写入文件
void wirte_file_from_array() {

}






//添加
void add_employee() {
	while (1) {
		//清屏
		system("cls");

		//声明数据
		Employee emp;
		
		//
		cout << "请依次输入以下数据，按回车键输入下一个数据：\n编号\t姓名\t工资\t奖金\t扣款\n";
		cin >> emp.num;
		gotoxy(8, 2);
		cin >> emp.name;
		gotoxy(16, 2);
		cin >> emp.base_money;
		gotoxy(24, 2);
		cin >> emp.bonus;
		gotoxy(32, 2);
		cin >> emp.deduct_money;
		//结束录入，判断提交
		cout << "是否提交数据？y/n\n";
		int c = _getch();
		if (c == 'n') {
			cout << "是否再次提交？y/n\n";
			c = _getch();
			if (c == 'y')
				continue;
			else
				break;
		}
		if (c == 'y') {
			//确认要提交
			//排重
			int flag = 0;
			LinkedList *link = root->next;
			while (1) {
				if (link == NULL) {
					break;
				}
				if (link->emp.num == emp.num||strcmp(link->emp.name, emp.name) == 0) {
					cout << "列表中已经存在该员工，此条数据无效！" << endl;
					flag = 1;
					break;
				}
				link = link->next;
			}
			//声明节点
			LinkedList *node;
			node = INIT;
			node->emp = emp;//数据域连接
			node->next = NULL;//指针域初始化

			//连接
			if (emp_count < 1) {
				root->next = node;//连接根节点
			}
			else {
				last->next = node;
			}
			last = node;//设置尾节点
		}
		else {
			cout << "错误！请再次录入。\n";
			break;
		}
		emp_count++;
		//再次输入
		cout << "是否录入下一个员工？y/n\n";
		c = _getch();
		if (c == 'n')
			break;
	}
}

//删除
void delete_employee() {
	system("cls");
	cout << "请输入名字或者编号";
}

//修改
void edit_employee() {

}

//查找功能
void seach() {

}






//排序
void sort() {

}




//显示
void show() {
	system("cls");

	if (emp_count == 0) {
		cout << "无员工！" << endl;
	}
	else {
		cout << "\t编号      \t姓名    \t基础工资  \t奖金\t扣款    " << endl;
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



//退出
void exit_and_save() {

	wirte_file_from_array();//退出之前保存文件
	exit(0);
}



//菜单
void menu() {
	int chioce;//接纳用户的选择
	system("cls");//清屏
	if (emp_count > 0) {
		cout << "++++现有职工：" << emp_count << "个++++\n" << endl;
	}
	cout << "职工工资管理系统\n1：添加职工信息\n2：修改职工信息\n3：删除职工信息\n4：显示所有员工信息\n9：退出\n输入你的选择：";
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
		cout << "\n没有这个选择，请重新输入" << endl;
		break;
	}
	system("pause");
}





int main() {
	initialize();//初始化
	read_file_into_array();//启动先读出文件里的数组
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

