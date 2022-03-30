#include <iostream>
#include <stdlib.h>
//这个版本是先将前缀表达式转换为后缀表达式，再进行求值
using namespace std;

#define MaxOptrNum 7
#define MaxSize 20

struct
{
	char data[MaxSize];	//存放运算符
	int top;			//栈指针
} op;				//定义运算符栈

struct
{
	float data[MaxSize];	//存放数值
	int top;			    //栈指针
} st;				        //定义数值栈

struct {
	char ch;   //运算符
	int pri;	//优先级
}lpri[] = { {'=',0},{'(',1},{'*',5},{'/',5},{'+',3}, {'-',3},{')',6} },
rpri[] = { {'=',0},{'(',6},{'*',4},{'/',4},{'+',2}, {'-',2},{')',1} };

//求左运算符op的优先级
int GetLeftpri(char op)
{
	for (int i = 0; i < MaxOptrNum; i++)
		if (lpri[i].ch == op)  return lpri[i].pri;
}

//求右运算符op的优先级
int GetRightpri(char op)
{
	int i;
	for (i = 0; i < MaxOptrNum; i++)
		if (rpri[i].ch == op) return rpri[i].pri;
}


//判断ch是否为运算符
bool IsOperator(char ch)
{
	if (ch == '(' || ch == ')' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
		return true;
	else
		return false;
}


//op1和op2运算符优先级的比较结果
int Precede(char op1, char op2)
{
	if (GetLeftpri(op1) == GetRightpri(op2))
		return 0;
	else if (GetLeftpri(op1) < GetRightpri(op2))
		return -1;
	else
		return 1;
}


//将算术表达式exp转换成后缀表达式postexp
void TransToPostexp(char* exp, char postexp[])
{
	int i = 0;				//i作为postexp的下标
	op.top = -1;
	op.data[++op.top] = '=';   //将'='进栈
	while (*exp != '\0')		//exp表达式未扫描完时循环
	{
		if (!IsOperator(*exp))		//为数字字符的情况
		{
			while (*exp >= '0' && *exp <= '9') //判定为数字
			{
				postexp[i++] = *exp;
				exp++;
			}
			postexp[i++] = '#';	//用#标识一个数值串结束
		}
		else {	//为运算符的情况
			switch (Precede(op.data[op.top], *exp))
			{
			case -1:		   //栈顶运算符的优先级低:进栈
				op.data[++op.top] = *exp;
				exp++;	   //继续扫描其他字符
				break;
			case 0:		   //只有括号满足这种情况
				op.top--;	   //将(退栈
				exp++;	   //继续扫描其他字符
				break;
			case 1:             //退栈并输出到postexp中
				postexp[i++] = op.data[op.top--];
				break;
			}
		}
	}

	while (op.data[op.top] != '=')    //此时exp扫描完毕,退栈到'='为止
		postexp[i++] = op.data[op.top--];
	postexp[i] = '\0';	//给postexp表达式添加结束标识
}

float CompExpValue(char exp[])	//计算后缀表达式的值
{
	float d; char ch; int t = 0; //t作为exp的下标
	st.top = -1; ch = exp[t]; t++;
	while (ch != '\0')	//exp字符串未扫描完时循环
	{
		switch (ch)
		{
		case'+':
			st.data[st.top - 1] = st.data[st.top - 1] + st.data[st.top];
			st.top--;
			break;
		case '-':
			st.data[st.top - 1] = st.data[st.top - 1] - st.data[st.top];
			st.top--;
			break;
		case '*':
			st.data[st.top - 1] = st.data[st.top - 1] * st.data[st.top];
			st.top--; break;
		case '/':
			try
			{
				if (st.data[st.top] == 0) throw 0;
				st.data[st.top - 1] = st.data[st.top - 1] / st.data[st.top];
			}
			catch (int)
			{
				cout << "除数不能等于零!" << endl;
				exit(0);		//异常退出
			}
			st.top--;
			break;
		default:
			d = 0; //将数字字符转换成数值存放到d中
			while (ch >= '0' && ch <= '9')   //为数字字符
			{
				d = 10 * d + ch - '0';
				ch = exp[t];
				t++;
			}
			st.top++;
			st.data[st.top] = d;
		}
		ch = exp[t]; t++;
	}
	return st.data[st.top];
}


void main()
{
	char exp[] = "(56-20)/(4+2)";
	char postexp[MaxSize];
	TransToPostexp(exp, postexp);
	cout << "中缀表达式:" << exp << endl;
	cout << "后缀表达式:" << postexp << endl;
	cout << "表达式的值:" << CompExpValue(postexp) << endl;

	return;
}