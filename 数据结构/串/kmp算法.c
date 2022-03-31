#include"´®.h"
using namespace std;
//typedef struct {
//	char ch[15];
//	int length;
//}String;
void match(int* next, SString p)
{
	next[1] = 0; int i = 1; int j = 0;

	while (i < p[0])
	{
		if (j == 0 || p[i] == p[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
}
int kmp(SString s, SString p)
{
	int i = 1;
	int j = 1;

	int* next = (int*)malloc((p[0] + 1) * sizeof(int));
	match(next, p);
	while (i <= s[0] && j <= p[0])
	{
		if (j == 0 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	free(next);
	if (j > p[0])return i - p[0];
	else return 0;
}
int main()
{
	SString s;
	SString p;

	char m[] = "abcde";
	StrAssign(s, m);
	char n[] = "cde";
	StrAssign(p, n);
	cout << kmp(s, p);
	return 0;
}