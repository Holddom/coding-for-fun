#include"串.h"
using namespace std;
//typedef struct {
//	char ch[15];
//	int length;
//}String;
//void match(int* next,SString p)
//{
//	next[1] = 0; int i = 1; int j = 0;
//
//	while (i < p[0])
//	{
//		if (j == 0 || p[i] == p[j])
//		{
//			i++;
//			j++;
//			next[i] = j;
//		}
//		else {
//			j = next[j];
//		}
//	}
//}
//int kmp(SString s, SString p)
//{
//	int i = 1;
//	int j = 1;
//
//	int* next =(int*) malloc((p[0] + 1)*sizeof(int));
//	match(next,p);
//	while (i <= s[0] && j <=p[0])
//	{
//		if (j == 0 || s[i] == p[j])
//		{
//		    i++;
//			j++;
//		}
//		else
//		{
//			j = next[j];
//		}
//	}
//	free(next);
//	if (j > p[0])return i - p[0];
//	else return 0;
//}
void match(char* p, int* next)
{
	int m = strlen(p);
	next[0] = -1;
	int i;
	int j;
	for (j = 1; j < m; j++)
	{
		i = next[j - 1];
		while (p[i] != p[j])
			i = next[i];
		if (p[i] == p[j])   next[j] = i;
		else   next[j] = -1;
	}
}
int kmp(char* s, char* p)
{
	int n = strlen(s);
	int m = strlen(p);
	if (n < m)return -1;
	int* next;
	next = (int*)malloc(m * sizeof(int));
	int i; int j;
	i = j = 0;
	while (i < n && j < m)
	{
		if (s[i] == p[j]) {
			i++;
			j++;
		}
		else if (j > 0)
		{
			j = next[j - 1] + 1;
		}
		else
		{
			i++;
		}
	}
	return j == m ? i - m : -1;
}
int main()
{
	//SString s;
	//SString p;
	//
	//char m[] = "abcde";
	//StrAssign(s,m );
	//char n[] = "cde";
	//StrAssign(p, n);
	//cout << kmp(s, p);
	//char ch;
	//int num;
	//ch=getchar();
	//if (ch >= '0' && ch <= '9')
	//{
	//	num = ch - '0';
	//	printf("%d", num);
	//}
	//else
	//{
	//	printf("%d", ch);
	//}
	char s[] = "abcde";
	char p[] = "cde";
	cout << kmp(s, p);    //从0开始计数
	return 0;
}