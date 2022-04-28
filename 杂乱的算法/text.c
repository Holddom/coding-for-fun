#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//  通讯录的功能
//  添加的信息 1
//  名字 年龄 性别 电话 地址
//  增加人的信息 2
//  删除指定人的信息 3
//  修改指定人的信息 4
//  查找指定人的信息 5
//  排序通讯录的信息 6
#include "contact.h"
void menu()         //用户界面
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
	Contact con;     //创建通讯录
	//初始化通讯录
	//初始化后的通讯录中 data是个头节点
	//sz初始化为0   而后每个人的数据都将会是一个结点 以链表的形式插入到data之后
	Initcontact(&con);

	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case ADD:  //增加一个人的信息
			AddContact(&con);
			break;
		case DEL:  //按名字删除一个人的信息
			DelContact(&con);
			break;
		case FIND:  //按名字查找一个人的信息
			FindContact(&con);
			break;
		case MODIFY:  //按名字修改一个人的信息
			ModifyContact(&con);
			break;
		case SORT:  //未完善
			SortContact(&con);
			break;
		case PRINT:    //打印整个通讯录的内容
			PrintContact(&con);
			break;
		case EXIT:
			//保存信息到文件
			SaveContact(&con);
			DestoryContact(&con);//销毁通讯录
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;

		}

	} while (input);




	return 0;

}
