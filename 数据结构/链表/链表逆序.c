#include "模板.h"
//1、已知一个非空的带头结点的有序单链表 L，试设计一个高效算法删除单链表 L
//中元素的值在[x, y]的结点，使得 L 仍为有序链表。
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
//2、设 A = (a1, a2, …, an)，B = (b1, b2, …, bm)是两个递增有序的线性表（其中 n, m 均大
//于 1），且每个集合中数据元素均不相同。若 A 和 B 均采用带头结点的单链表存
//储，设计一个尽可能高效的算法判断 B 是否为 A 的一个连续子序列，并分析你
//设计的算法的时间复杂度。
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
//3、已知一个带头结点的单链表，在不改变链表的前提下，设计一个高效的算法，
//查找链表中倒数第 k 个位置上的结点
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
//求两链表的差集A-B A的每一个元素在B里遍历，若存在与其相等的元素，则在A中将其删除。
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
//求集合A与B的交集    将A的每一个元素放到B里遍历，若有相同则保留A，若B中没有则在A中将其删除
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
//求A与B的并集    借用A的头节点，将B中的每一个元素放到A遍历，若A没有，则插入这个节点
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
//链表逆序
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