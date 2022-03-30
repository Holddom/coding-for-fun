#include <iostream>
#include <stdlib.h>
//����汾���Ƚ�ǰ׺���ʽת��Ϊ��׺���ʽ���ٽ�����ֵ
using namespace std;

#define MaxOptrNum 7
#define MaxSize 20

struct
{
	char data[MaxSize];	//��������
	int top;			//ջָ��
} op;				//���������ջ

struct
{
	float data[MaxSize];	//�����ֵ
	int top;			    //ջָ��
} st;				        //������ֵջ

struct {
	char ch;   //�����
	int pri;	//���ȼ�
}lpri[] = { {'=',0},{'(',1},{'*',5},{'/',5},{'+',3}, {'-',3},{')',6} },
rpri[] = { {'=',0},{'(',6},{'*',4},{'/',4},{'+',2}, {'-',2},{')',1} };

//���������op�����ȼ�
int GetLeftpri(char op)
{
	for (int i = 0; i < MaxOptrNum; i++)
		if (lpri[i].ch == op)  return lpri[i].pri;
}

//���������op�����ȼ�
int GetRightpri(char op)
{
	int i;
	for (i = 0; i < MaxOptrNum; i++)
		if (rpri[i].ch == op) return rpri[i].pri;
}


//�ж�ch�Ƿ�Ϊ�����
bool IsOperator(char ch)
{
	if (ch == '(' || ch == ')' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
		return true;
	else
		return false;
}


//op1��op2��������ȼ��ıȽϽ��
int Precede(char op1, char op2)
{
	if (GetLeftpri(op1) == GetRightpri(op2))
		return 0;
	else if (GetLeftpri(op1) < GetRightpri(op2))
		return -1;
	else
		return 1;
}


//���������ʽexpת���ɺ�׺���ʽpostexp
void TransToPostexp(char* exp, char postexp[])
{
	int i = 0;				//i��Ϊpostexp���±�
	op.top = -1;
	op.data[++op.top] = '=';   //��'='��ջ
	while (*exp != '\0')		//exp���ʽδɨ����ʱѭ��
	{
		if (!IsOperator(*exp))		//Ϊ�����ַ������
		{
			while (*exp >= '0' && *exp <= '9') //�ж�Ϊ����
			{
				postexp[i++] = *exp;
				exp++;
			}
			postexp[i++] = '#';	//��#��ʶһ����ֵ������
		}
		else {	//Ϊ����������
			switch (Precede(op.data[op.top], *exp))
			{
			case -1:		   //ջ������������ȼ���:��ջ
				op.data[++op.top] = *exp;
				exp++;	   //����ɨ�������ַ�
				break;
			case 0:		   //ֻ�����������������
				op.top--;	   //��(��ջ
				exp++;	   //����ɨ�������ַ�
				break;
			case 1:             //��ջ�������postexp��
				postexp[i++] = op.data[op.top--];
				break;
			}
		}
	}

	while (op.data[op.top] != '=')    //��ʱexpɨ�����,��ջ��'='Ϊֹ
		postexp[i++] = op.data[op.top--];
	postexp[i] = '\0';	//��postexp���ʽ��ӽ�����ʶ
}

float CompExpValue(char exp[])	//�����׺���ʽ��ֵ
{
	float d; char ch; int t = 0; //t��Ϊexp���±�
	st.top = -1; ch = exp[t]; t++;
	while (ch != '\0')	//exp�ַ���δɨ����ʱѭ��
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
				cout << "�������ܵ�����!" << endl;
				exit(0);		//�쳣�˳�
			}
			st.top--;
			break;
		default:
			d = 0; //�������ַ�ת������ֵ��ŵ�d��
			while (ch >= '0' && ch <= '9')   //Ϊ�����ַ�
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
	cout << "��׺���ʽ:" << exp << endl;
	cout << "��׺���ʽ:" << postexp << endl;
	cout << "���ʽ��ֵ:" << CompExpValue(postexp) << endl;

	return;
}