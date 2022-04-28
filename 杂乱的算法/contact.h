#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NAME 20    //名字的最大字符数
#define MAX_SEX 10     //性别
#define MAX_TELE 12    //电话号码位数
#define MAX_ADDR 30    //地址

typedef struct PeoInFo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
	struct PeoInFo* next;
}*PeoInFo;

typedef struct Contact
{
	PeoInFo data;  //指向动态申请的空间 用来存放联系人的信息
	int sz;         //记录当前通讯录有效信息的个数

}Contact;
void Initcontact(Contact* pc);  //初始化通讯录

void AddContact(Contact* pc);  //增加联系人

void PrintContact(const Contact* pc); //打印通讯录

void DelContact(Contact* pc);  //删除联系人

void FindContact(Contact* pc);  //查找指定的联系人

void ModifyContact(Contact* pc);  //修改指定联系人

void DestoryContact(Contact* pc);  //销毁通讯录

void SaveContact(Contact* pc);   //保存信息到通讯录

void LoadContact(Contact* pc); //加载文件保存的通讯录

void SortContact(Contact* pc);  //对通讯录里的信息进行姓名字典序排序或者年龄排序
#pragma once
