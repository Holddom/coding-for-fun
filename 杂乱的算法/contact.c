
#include "contact.h"

void Initcontact(Contact* pc)  //动态版本
{
	pc->data = (PeoInFo)malloc(sizeof(struct PeoInFo));  //这是一个头指针
	if (pc->data == NULL)
	{
		perror("Initcontact");
		return;
	}
	pc->sz = 0;
	pc->data->next = NULL;
	//加载文件
	LoadContact(pc);
}
void LoadContact(Contact* pc) //加载文件里保存的通讯录
{
	FILE* pf = fopen("contact.txt", "r");
	if (pf == NULL)
	{
		perror("LoadContact");
		return;
	}
	//读文件
	PeoInFo tmp = (PeoInFo)malloc(sizeof(struct PeoInFo));
	if (tmp == NULL)
	{
		perror("申请空间失败");
		return;
	}
	while (fread(tmp, sizeof(struct PeoInFo), 1, pf))
	{
		PeoInFo node = pc->data;
		while (node->next != NULL)
		{
			node = node->next;
		}
		node->next = tmp;
		tmp->next = NULL;
		pc->sz++;
		tmp = (PeoInFo)malloc(sizeof(struct PeoInFo));
		if (tmp == NULL)
		{
			perror("申请空间失败");
			return;
		}
	}
	free(tmp);
	tmp = NULL;
	//关闭文件
	fclose(pf);
	pf = NULL;
}


void AddContact(Contact* pc)  //动态版本
{

	//增加一个人的信息  (可批量)
	printf("你想要添加几个人>:\n");
	int n;
	scanf("%d", &n);
	printf("请按照姓名 年龄 性别 电话 地址 的方式输入（每个元素中间有一个空格）\n");
	for (int i = 0; i < n; i++)
	{
		char tname[MAX_NAME];
		char tsex[MAX_SEX];
		int tage;
		char ttele[MAX_TELE];
		char taddr[MAX_ADDR];
		if (scanf("%s %d %s %s %s", tname, &tage, tsex, ttele, taddr) != 5)
		{
			printf("输入的数据有误\n");
			fflush(stdin);
			return;
		}
		PeoInFo node = (PeoInFo)malloc(sizeof(struct PeoInFo));
		if (node == NULL)
		{
			perror("申请空间失败");
			return;
		}
		{strcpy(node->name, tname); strcpy(node->sex, tsex);
		node->age = tage; strcpy(node->tele, ttele); strcpy(node->addr, taddr); }
		PeoInFo p = pc->data;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = node;
		node->next = NULL;
		pc->sz++;
	}

	printf("增加成功\n");
}
void PrintContact(const Contact* pc)
{
	int i = 0;
	//打印标题
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
	//打印数据
	PeoInFo p = pc->data;
	for (i = 0; i < pc->sz; i++)
	{
		p = p->next;
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n",
			p->name,
			p->age,
			p->sex,
			p->tele,
			p->addr);
	}

}
static int Findbyname(Contact* pc, char name[])
{
	int i = 0;
	PeoInFo p = pc->data;
	for (i = 0; i < pc->sz; i++)
	{
		p = p->next;
		if (strcmp(p->name, name) == 0)
			return i;
	}
	return -1;//找不到
}
void DelContact(Contact* pc) //删除联系人
{
	char name[MAX_NAME];
	if (pc->sz == 0)
	{
		printf("通讯录为空，无需删除\n");
		return;
	}
	//查找要删除的人
	printf("请输入要删除人的名字：\n");
	scanf("%s", name);
	int pos = Findbyname(pc, name);
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	//删除
	int i = 0;
	PeoInFo p = pc->data->next;
	PeoInFo pre = pc->data;
	for (i = 0; i < pos; i++)
	{
		pre = p;
		p = p->next;
	}
	pre->next = p->next;
	free(p);
	pc->sz--;
	printf("删除成功\n");
}
void FindContact(Contact* pc)   //查找指定的联系人
{
	char name[MAX_NAME];
	printf("请输入要查找人的名字：\n");
	scanf("%s", name);
	int pos = Findbyname(pc, name);
	if (pos == -1)
	{
		printf("要查找的人不存在\n");
		return;
	}
	else
	{
		PeoInFo p = pc->data;
		int i = 0;
		do {
			p = p->next;

		} while (i++ != pos);
		//打印标题
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		//打印数据
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n",
			p->name,
			p->age,
			p->sex,
			p->tele,
			p->addr);
	}
}
void ModifyContact(Contact* pc)  //修改指定的联系人
{
	char name[MAX_NAME];
	printf("请输入要修改人的名字：\n");
	scanf("%s", name);
	int pos = Findbyname(pc, name);
	if (pos == -1)
	{
		printf("要修改的人不存在\n");
		return;
	}
	else
	{
		PeoInFo p = pc->data;
		int i = 0;
		do {
			p = p->next;

		} while (i++ != pos);
		printf("请输入人的名字:>\n");
		scanf("%s", p->name);
		printf("请输入人的年龄:>\n");
		scanf("%d", &(p->age));
		printf("请输入人的性别:>\n");
		scanf("%s", p->sex);
		printf("请输入人的电话:>\n");
		scanf("%s", p->tele);
		printf("请输入人的地址:>\n");
		scanf("%s", p->addr);
		printf("修改成功\n");
	}
}
void SortContact(Contact* pc)
{
	static PeoInFo sortbyname(PeoInFo head);
	static PeoInFo sortbyage(PeoInFo head);
	printf("按哪种方式排序：1.姓名  2.年龄\n");
	int flag;
	scanf("%d", &flag);
	switch (flag)
	{
	case 1:  //字典序排序
		pc->data = sortbyname(pc->data);
		break;
	case 2:  //年龄排序
		pc->data = sortbyage(pc->data);
		break;
	default:
		printf("输入错误，退回主菜单\n");
	}

}
static PeoInFo sortbyname(PeoInFo head)
{
	if (head == NULL)
		return NULL;
	if (head->next == NULL)
		return NULL;

	PeoInFo pre = head; //用于链表的插入
	PeoInFo p = pre->next;//用来维护已经排好序的链表
	PeoInFo q = p->next;         //未排序的
	PeoInFo m = q->next;         //保存未排序的链表
	p->next = NULL;  //断掉
	while (q)
	{
		q->next = NULL;  //断掉
		pre = head;
		p = pre->next;

		while (p != NULL && strcmp(q->name, p->name) > 0)
		{
			pre = p;
			p = p->next;
		}
		pre->next = q;
		q->next = p;
		q = m;
		if (m != NULL)
			m = m->next;
	}
	return head;
}

static PeoInFo sortbyage(PeoInFo head)
{
	if (head == NULL)
		return NULL;
	if (head->next == NULL)
		return NULL;

	PeoInFo pre = head; //用于链表的插入
	PeoInFo p = pre->next;//用来维护已经排好序的链表
	PeoInFo q = p->next;         //未排序的
	PeoInFo m = q->next;         //保存未排序的链表
	p->next = NULL;  //断掉
	while (q)
	{
		q->next = NULL;  //断掉
		pre = head;
		p = pre->next;

		while (p != NULL && q->age > p->age)
		{
			pre = p;
			p = p->next;
		}
		pre->next = q;
		q->next = p;
		q = m;
		if (m != NULL)
			m = m->next;
	}
	return head;
}
void DestoryContact(Contact* pc)  //销毁通讯录
{
	PeoInFo p = pc->data;
	PeoInFo s = p->next;
	while (s != NULL)
	{
		free(p);
		p = s;
		s = s->next;
	}
	free(p);
	pc->data = NULL;
	pc->sz = 0;
}
void SaveContact(Contact* pc)
{
	FILE* pf = fopen("contact.txt", "w");
	if (pf == NULL)
	{
		perror("SaveContact");
		return;
	}
	//写文件
	int i = 0;
	PeoInFo p = pc->data;
	for (i = 0; i < pc->sz; i++)
	{
		p = p->next;
		fwrite(p, sizeof(struct PeoInFo), 1, pf);
	}
	//关闭文件
	fclose(pf);
	pf = NULL;

}
