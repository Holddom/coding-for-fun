#include "ģ��.h"
//1����֪һ���ǿյĴ�ͷ������������ L�������һ����Ч�㷨ɾ�������� L
//��Ԫ�ص�ֵ��[x, y]�Ľ�㣬ʹ�� L ��Ϊ��������
void deletexy(LinkList& L, int x, int y)
{
	LNode* p = L->next;
	LNode* q = L->next;
	L->next = NULL;
	LNode* m = L;
	while (q)
	{
		if (p->data<x || p->data>y)
		{
			m->next = p;
			m = p;
		}
		q = q->next;
		p = q;
	}
	m->next = NULL;
}
//2���� A = (a1, a2, ��, an)��B = (b1, b2, ��, bm)������������������Ա����� n, m ����
//�� 1������ÿ������������Ԫ�ؾ�����ͬ���� A �� B �����ô�ͷ���ĵ������
//�������һ�������ܸ�Ч���㷨�ж� B �Ƿ�Ϊ A ��һ�����������У���������
//��Ƶ��㷨��ʱ�临�Ӷȡ�
int JudgeAwB(LinkList A, LinkList B) //o(n)
{
	LinkList a = A->next;
	LinkList b = B->next;
	int flag = 1;
	while (a)
	{
		if (a->data == b->data)
		{
			while (a && b)
			{
				if (a->data != b->data)
				{
					flag = 0;
					break;
				}
				a = a->next;
				b = b->next;
			}
			if (a == NULL && b != NULL)
			{
				flag = 0;
				break;
			}
			if (b == NULL)
				break;
		}
		a = a->next;
	}
	return flag;
}
//3����֪һ����ͷ���ĵ������ڲ��ı������ǰ���£����һ����Ч���㷨��
//���������е����� k ��λ���ϵĽ��
LNode* nodek(LinkList L, int k)
{
	if (k < 1)return NULL;
	LinkList fast = L->next;
	LinkList slow = L->next;
	int i = 0;
	while (fast != NULL)
	{
		if (i < k)i++;
		else slow = slow->next;
		fast = fast->next;
	}

	return slow;
}
//��������ĲA-B A��ÿһ��Ԫ����B�������������������ȵ�Ԫ�أ�����A�н���ɾ����
void Dset(LinkList& A, LinkList& B)
{
	LNode* a = A->next;
	LNode* pre = A;
	LNode* b = B->next;
	while (a)
	{
		b = B->next;
		while (b)
		{
			if (a->data == b->data)
				break;
			b = b->next;
		}
		if (b != NULL)
		{
			LNode* r = a;
			a = a->next;
			pre->next = a;
			delete r;
		}
		else
		{
			pre = a;
			a = a->next;
			pre->next = a;
		}

	}

}
//�󼯺�A��B�Ľ���    ��A��ÿһ��Ԫ�طŵ�B�������������ͬ����A����B��û������A�н���ɾ��
void AwithB(LinkList& A, LinkList& B)
{
	LNode* a = A->next;
	LNode* pa = A;
	LNode* b = B->next;
	while (a)
	{
		b = B->next;
		while (b)
		{
			if (b->data == a->data)
				break;
			b = b->next;
		}
		if (b != NULL)
		{
			pa = a;
			a = a->next;
		}
		else
		{
			LNode* s = a;
			a = a->next;
			pa->next = a;
			delete s;
		}
	}

}
//��A��B�Ĳ���    ����A��ͷ�ڵ㣬��B�е�ÿһ��Ԫ�طŵ�A��������Aû�У����������ڵ�
void AUB(LinkList& A, LinkList& B)
{
	LNode* a = A->next;
	LNode* b = B->next;
	LNode* pre = B;

	while (b)
	{
		a = A->next;
		while (a)
		{
			if (b->data == a->data)
			{
				break;
			}
			a = a->next;
		}
		if (a == NULL)
		{
			LNode* s = b;
			b = b->next;
			pre->next = b;
			s->next = A->next;
			A->next = s;
		}
		else
		{
			pre = b;
			b = b->next;
		}
	}
}
//��������
void reverse(LinkList& L)
{
	LNode* p = L->next;
	L->next = NULL;
	LNode* s;
	while (p)
	{
		s = p;
		p = p->next;
		s->next = L->next;
		L->next = s;
	}
}
int main()
{
	LinkList A;
	//InitList(L);

	CreateList_R(A, 5);
	LNode* p = A->next;
	while (p)
	{
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
	reverse(A);
	p = A->next;
	while (p)
	{
		cout << p->data << ' ';
		p = p->next;
	}

	Destroy(A);
	return 0;
}