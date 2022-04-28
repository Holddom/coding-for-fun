
#include "contact.h"

void Initcontact(Contact* pc)  //��̬�汾
{
	pc->data = (PeoInFo)malloc(sizeof(struct PeoInFo));  //����һ��ͷָ��
	if (pc->data == NULL)
	{
		perror("Initcontact");
		return;
	}
	pc->sz = 0;
	pc->data->next = NULL;
	//�����ļ�
	LoadContact(pc);
}
void LoadContact(Contact* pc) //�����ļ��ﱣ���ͨѶ¼
{
	FILE* pf = fopen("contact.txt", "r");
	if (pf == NULL)
	{
		perror("LoadContact");
		return;
	}
	//���ļ�
	PeoInFo tmp = (PeoInFo)malloc(sizeof(struct PeoInFo));
	if (tmp == NULL)
	{
		perror("����ռ�ʧ��");
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
			perror("����ռ�ʧ��");
			return;
		}
	}
	free(tmp);
	tmp = NULL;
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}


void AddContact(Contact* pc)  //��̬�汾
{

	//����һ���˵���Ϣ  (������)
	printf("����Ҫ��Ӽ�����>:\n");
	int n;
	scanf("%d", &n);
	printf("�밴������ ���� �Ա� �绰 ��ַ �ķ�ʽ���루ÿ��Ԫ���м���һ���ո�\n");
	for (int i = 0; i < n; i++)
	{
		char tname[MAX_NAME];
		char tsex[MAX_SEX];
		int tage;
		char ttele[MAX_TELE];
		char taddr[MAX_ADDR];
		if (scanf("%s %d %s %s %s", tname, &tage, tsex, ttele, taddr) != 5)
		{
			printf("�������������\n");
			fflush(stdin);
			return;
		}
		PeoInFo node = (PeoInFo)malloc(sizeof(struct PeoInFo));
		if (node == NULL)
		{
			perror("����ռ�ʧ��");
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

	printf("���ӳɹ�\n");
}
void PrintContact(const Contact* pc)
{
	int i = 0;
	//��ӡ����
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	//��ӡ����
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
	return -1;//�Ҳ���
}
void DelContact(Contact* pc) //ɾ����ϵ��
{
	char name[MAX_NAME];
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ�����ɾ��\n");
		return;
	}
	//����Ҫɾ������
	printf("������Ҫɾ���˵����֣�\n");
	scanf("%s", name);
	int pos = Findbyname(pc, name);
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	//ɾ��
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
	printf("ɾ���ɹ�\n");
}
void FindContact(Contact* pc)   //����ָ������ϵ��
{
	char name[MAX_NAME];
	printf("������Ҫ�����˵����֣�\n");
	scanf("%s", name);
	int pos = Findbyname(pc, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
		return;
	}
	else
	{
		PeoInFo p = pc->data;
		int i = 0;
		do {
			p = p->next;

		} while (i++ != pos);
		//��ӡ����
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		//��ӡ����
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n",
			p->name,
			p->age,
			p->sex,
			p->tele,
			p->addr);
	}
}
void ModifyContact(Contact* pc)  //�޸�ָ������ϵ��
{
	char name[MAX_NAME];
	printf("������Ҫ�޸��˵����֣�\n");
	scanf("%s", name);
	int pos = Findbyname(pc, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
		return;
	}
	else
	{
		PeoInFo p = pc->data;
		int i = 0;
		do {
			p = p->next;

		} while (i++ != pos);
		printf("�������˵�����:>\n");
		scanf("%s", p->name);
		printf("�������˵�����:>\n");
		scanf("%d", &(p->age));
		printf("�������˵��Ա�:>\n");
		scanf("%s", p->sex);
		printf("�������˵ĵ绰:>\n");
		scanf("%s", p->tele);
		printf("�������˵ĵ�ַ:>\n");
		scanf("%s", p->addr);
		printf("�޸ĳɹ�\n");
	}
}
void SortContact(Contact* pc)
{
	static PeoInFo sortbyname(PeoInFo head);
	static PeoInFo sortbyage(PeoInFo head);
	printf("�����ַ�ʽ����1.����  2.����\n");
	int flag;
	scanf("%d", &flag);
	switch (flag)
	{
	case 1:  //�ֵ�������
		pc->data = sortbyname(pc->data);
		break;
	case 2:  //��������
		pc->data = sortbyage(pc->data);
		break;
	default:
		printf("��������˻����˵�\n");
	}

}
static PeoInFo sortbyname(PeoInFo head)
{
	if (head == NULL)
		return NULL;
	if (head->next == NULL)
		return NULL;

	PeoInFo pre = head; //��������Ĳ���
	PeoInFo p = pre->next;//����ά���Ѿ��ź��������
	PeoInFo q = p->next;         //δ�����
	PeoInFo m = q->next;         //����δ���������
	p->next = NULL;  //�ϵ�
	while (q)
	{
		q->next = NULL;  //�ϵ�
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

	PeoInFo pre = head; //��������Ĳ���
	PeoInFo p = pre->next;//����ά���Ѿ��ź��������
	PeoInFo q = p->next;         //δ�����
	PeoInFo m = q->next;         //����δ���������
	p->next = NULL;  //�ϵ�
	while (q)
	{
		q->next = NULL;  //�ϵ�
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
void DestoryContact(Contact* pc)  //����ͨѶ¼
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
	//д�ļ�
	int i = 0;
	PeoInFo p = pc->data;
	for (i = 0; i < pc->sz; i++)
	{
		p = p->next;
		fwrite(p, sizeof(struct PeoInFo), 1, pf);
	}
	//�ر��ļ�
	fclose(pf);
	pf = NULL;

}
