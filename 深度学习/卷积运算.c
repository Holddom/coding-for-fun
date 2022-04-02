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
	for (i = 1; i <= n; i++)   //输入矩阵数据
	{
		for (j = 1; j <= m; j++)
		{
			cin >> matrix[i][j];
		}
	}
	for (j = 0; j <= m + 1; j++)   //填充0
	{
		matrix[0][j] = 0;
	}
	for (j = 0; j <= m + 1; j++)   //填充0
	{
		matrix[n + 1][j] = 0;
	}
	for (i = 0; i <= n + 1; i++)   //填充0
	{
		matrix[i][0] = 0;
	}
	for (i = 0; i <= n + 1; i++)   //填充0
	{
		matrix[i][m + 1] = 0;
	}
	int x, y;             //卷积核大小
	cin >> x >> y;
	for (i = 1; i < x; i++)  //卷积核数据
	{
		for (j = 1; j < y; j++)
		{
			cin >> Kernel[i][j];
		}
	}
	int size;                       //步长
	cin >> size;
	//卷积运算
	//用i，j表示代求矩阵的行和列
	//用a，b表示卷积核的对应位置
	int a, b;
	int sum = 0;//sum表示一次卷积运算的值
	//int ret[200][200];//ret为输出矩阵
	//int row = 0; int col = 0;  //row col 表示 输出矩阵的行和列
	int ret[400];
	int count = 0;
	for (i = 0; i <= n + 1; i++)
	{
		for (j = 0; j <= m + 1; j++)
		{
			//进行一次卷积运算
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
