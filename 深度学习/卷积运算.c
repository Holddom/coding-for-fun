#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>

int main()
{
	int matrix[202][202];
	int Kernel[11][11];
	int n, m;
	int i, j;
	cin >> n >> m;
	for (i = 1; i <= n; i++)   //�����������
	{
		for (j = 1; j <= m; j++)
		{
			cin >> matrix[i][j];
		}
	}
	for (j = 0; j <= m + 1; j++)   //���0
	{
		matrix[0][j] = 0;
	}
	for (j = 0; j <= m + 1; j++)   //���0
	{
		matrix[n + 1][j] = 0;
	}
	for (i = 0; i <= n + 1; i++)   //���0
	{
		matrix[i][0] = 0;
	}
	for (i = 0; i <= n + 1; i++)   //���0
	{
		matrix[i][m + 1] = 0;
	}
	int x, y;             //����˴�С
	cin >> x >> y;
	for (i = 1; i < x; i++)  //���������
	{
		for (j = 1; j < y; j++)
		{
			cin >> Kernel[i][j];
		}
	}
	int size;                       //����
	cin >> size;
	//�������
	//��i��j��ʾ���������к���
	//��a��b��ʾ����˵Ķ�Ӧλ��
	int a, b;
	int sum = 0;//sum��ʾһ�ξ�������ֵ
	//int ret[200][200];//retΪ�������
	//int row = 0; int col = 0;  //row col ��ʾ ���������к���
	int ret[400];
	int count = 0;
	for (i = 0; i <= n + 1; i++)
	{
		for (j = 0; j <= m + 1; j++)
		{
			//����һ�ξ������
			for (a = 1; a <= x; a += size)
			{
				for (b = 1; b <= y; b++)
				{
					sum += matrix[i + a][j + b] * Kernel[a][b];
				}
				ret[count++] = sum;
				sum = 0;
			}
		}
	}
	for (i = 0; i < count; i++)
	{
		cout << ret[i] << ' ';
	}

	return 0;
}
