#pragma once
#include <iostream>
using namespace std;
#define ElemType int
#define OK 1
#define ERROR 0
//#define OVERFLOW -2
#define MAXSIZE 6
typedef int Status;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

//��ʼ��
Status InitList(LinkList& L)
{
	L = new LNode;      //����ͷ�ڵ�
	L->next = NULL;
	return OK;
}
//ȡֵ
Status GerElem(LinkList& L, int i, ElemType& e)
{
	LNode* p = L->next;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i) return ERROR;
	e = p->data;
	return OK;
}
//����
LNode* LocateElem(LinkList L, ElemType e)
{
	LNode* p = L->next;
	while (p && p->data != e)
		p = p->next;
	return p;
}
//����
Status LinkInsert(LinkList& L, int i, ElemType e)
{
	LNode* p = L->next;
	int j = 0;
	while (p && j < i - 1)
	{
		p = p->next;
		j++;
	}
	while (!p || j > i - 1) return ERROR;
	LNode* s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}
//ɾ��
Status ListDelete(LinkList& L, int i)
{
	LNode* p = L->next;
	int j = 0;
	while (p->next && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || j > i - 1) return ERROR;
	LNode* q = p->next;
	p->next = q->next;
	delete q;
	return OK;
}
//ͷ�巨
void CreateList_H(LinkList& L, int n)
{
	L = new LNode;
	L->next = NULL;
	for (int i = 0; i < n; i++)
	{
		LNode* p = new LNode;
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
}
//β�巨
void CreateList_R(LinkList& L, int n)
{
	L = new LNode;
	L->next = NULL;
	LNode* r = L;
	for (int i = 0; i < n; i++)
	{
		LNode* p = new LNode;
		cin >> p->data;
		p->next = NULL;
		r->next = p;
		r = p;
	}
}
void Destroy(LinkList& L)
{
	LNode* p, * q;
	p = L;
	while (p)
	{
		q = p->next;
		delete p;
		p = q;
	}
}
//˫������
typedef struct DuLNode
{
	ElemType data;
	struct DulNode* prior;
	struct DulNode* next;
}DuLNode, * DuLinkList;

////˫������Ĳ���
//Status ListInsert_DuL(DuLinkList& L, int i, ElemType e)
//{
//
//}