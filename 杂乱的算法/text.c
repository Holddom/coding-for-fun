#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//  ͨѶ¼�Ĺ���
//  ��ӵ���Ϣ 1
//  ���� ���� �Ա� �绰 ��ַ
//  �����˵���Ϣ 2
//  ɾ��ָ���˵���Ϣ 3
//  �޸�ָ���˵���Ϣ 4
//  ����ָ���˵���Ϣ 5
//  ����ͨѶ¼����Ϣ 6
#include "contact.h"
void menu()         //�û�����
{
	printf("******************************\n");
	printf("*******1.ADD   2.DEL    ******\n");
	printf("*******3.FIND  4.MODIFY ******\n");
	printf("*******5.SORT  6.PRINT  ******\n");
	printf("*******0.EXIT           ******\n");
	printf("******************************\n");
}
enum Option
{
	EXIT,
	ADD,
	DEL,
	FIND,
	MODIFY,
	SORT,
	PRINT

};
int main()
{
	int input;
	Contact con;     //����ͨѶ¼
	//��ʼ��ͨѶ¼
	//��ʼ�����ͨѶ¼�� data�Ǹ�ͷ�ڵ�
	//sz��ʼ��Ϊ0   ����ÿ���˵����ݶ�������һ����� ���������ʽ���뵽data֮��
	Initcontact(&con);

	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case ADD:  //����һ���˵���Ϣ
			AddContact(&con);
			break;
		case DEL:  //������ɾ��һ���˵���Ϣ
			DelContact(&con);
			break;
		case FIND:  //�����ֲ���һ���˵���Ϣ
			FindContact(&con);
			break;
		case MODIFY:  //�������޸�һ���˵���Ϣ
			ModifyContact(&con);
			break;
		case SORT:  //δ����
			SortContact(&con);
			break;
		case PRINT:    //��ӡ����ͨѶ¼������
			PrintContact(&con);
			break;
		case EXIT:
			//������Ϣ���ļ�
			SaveContact(&con);
			DestoryContact(&con);//����ͨѶ¼
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;

		}

	} while (input);




	return 0;

}
