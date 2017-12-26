#pragma once

//工人结构体
struct Employee
{
	int num;
	char name[9];
	int base_money;//基础工资
	int bonus;//奖金
	int deduct_money;//扣款
};



//链表
struct LinkedList
{
	struct Employee emp;
	int hasNext;
	struct LinkedList *next;
};