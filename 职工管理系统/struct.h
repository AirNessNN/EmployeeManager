#pragma once

//���˽ṹ��
struct Employee
{
	int num;
	char name[9];
	int base_money;//��������
	int bonus;//����
	int deduct_money;//�ۿ�
};



//����
struct LinkedList
{
	struct Employee emp;
	int hasNext;
	struct LinkedList *next;
};