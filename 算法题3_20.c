#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
//typedef struct list {
//	int val;
//	struct list* next;
//}*node;

int main()
{
	int a[4][4];
	for (int i = 0; i < 4; i++)   //数据的读入
	{
		for (int j = 0; j < 4; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	int maxi, maxj, max;
	maxi = 0; maxj = 0; max = a[0][0];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (a[i][j] > max)
			{
				maxi = i;
				maxj = j;
				max = a[i][j];
			}
		}
	}
	printf("擂主是a[%d][%d]=%d", maxi, maxj, max);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>
struct  student {
	int num;
	int chi;
	int math;
	int eng;
	int sum;

}stu[305];
//struct stu {
//	int number;
//	int sum;
//};
bool compare(struct student a, struct student b)
{
	if (a.sum != b.sum) return a.sum > b.sum;
	if (a.chi != b.chi)return a.chi > b.chi;
	return a.num < b.num;
}
int main()
{
	int n;
	cin >> n;


	for (int i = 1; i <= n; i++)  //数据的读入
	{
		stu[i].num = i;
		cin >> stu[i].chi >> stu[i].math >> stu[i].eng;
		stu[i].sum = stu[i].chi + stu[i].math + stu[i].eng;
	}
	sort(stu + 1, stu + 1 + n, compare);
	for (int i = 1; i <= 5; i++)
	{
		cout << stu[i].num << ' ' << stu[i].sum << ' ';
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string.h>
int main()
{
	char s[100];
	gets(s);
	char ch;
	cin >> ch;
	int i;
	int n = strlen(s);
	for (i = 0; i < n; i++)
	{
		if (s[i] == ch)
			break;
	}
	if (i != n)
	{
		cout << i + 1;
	}
	else
		cout << "No";
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
int main()
{
	int n, m;
	cin >> n >> m;
	int i, j, p, q, k, u;
	int a[11][11];
	int li, lj;
	int ri, rj;
	int sum;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			for (p = i; p < n; p++)
				for (q = j; q < n; q++)
				{
					li = i + 1; lj = j + 1; sum = 0;
					for (k = i; k <= p; k++)
						for (u = j; u <= q; u++)
						{
							sum += a[k][u];

						}
					if (sum == m) {
						ri = k; rj = u;
						cout << li << ' ' << lj << ' ' << ri << ' ' << rj;
						return 0;
					}

				}
	cout << -1;

	return 0;
}