#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NAME 20    //���ֵ�����ַ���
#define MAX_SEX 10     //�Ա�
#define MAX_TELE 12    //�绰����λ��
#define MAX_ADDR 30    //��ַ

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
	PeoInFo data;  //ָ��̬����Ŀռ� ���������ϵ�˵���Ϣ
	int sz;         //��¼��ǰͨѶ¼��Ч��Ϣ�ĸ���

}Contact;
void Initcontact(Contact* pc);  //��ʼ��ͨѶ¼

void AddContact(Contact* pc);  //������ϵ��

void PrintContact(const Contact* pc); //��ӡͨѶ¼

void DelContact(Contact* pc);  //ɾ����ϵ��

void FindContact(Contact* pc);  //����ָ������ϵ��

void ModifyContact(Contact* pc);  //�޸�ָ����ϵ��

void DestoryContact(Contact* pc);  //����ͨѶ¼

void SaveContact(Contact* pc);   //������Ϣ��ͨѶ¼

void LoadContact(Contact* pc); //�����ļ������ͨѶ¼

void SortContact(Contact* pc);  //��ͨѶ¼�����Ϣ���������ֵ������������������
#pragma once
