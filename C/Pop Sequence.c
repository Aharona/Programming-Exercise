/*
1051 Pop Sequence (25)��25 point(s)��

Given a stack which can keep M numbers at most. Push N numbers in the order of 1, 2, 3, ..., N and pop randomly. You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack. For example, if M is 5 and N is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.

Input Specification:

Each input file contains one test case. For each case, the first line contains 3 numbers (all no more than 1000): M (the maximum capacity of the stack), N (the length of push sequence), and K (the number of pop sequences to be checked). Then K lines follow, each contains a pop sequence of N numbers. All the numbers in a line are separated by a space.

Output Specification:

For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the stack, or "NO" if not.

Sample Input:

5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2
Sample Output:

YES
NO
NO
YES
NO
*/

#include <stdio.h>
#include <stdlib.h>
#define Maxsize 1000
typedef struct SNode *Stack;
struct SNode 
{
	int Data[Maxsize];
	int Top;
};

void Push(Stack Ptrs, int item)
{
	if (Ptrs->Top == Maxsize - 1)
	{
		printf("��ջ��");
		return ;
	}
	else
	{
		Ptrs->Data[++(Ptrs->Top)] = item;
		return ;
	}
}

int Pop(Stack Ptrs)
{
	if (Ptrs->Top == -1)
	{
		printf("��ջ��");
		return -1;
	}
	else
		return Ptrs->Data[(Ptrs->Top)--];
}
int main()
{
	Stack s ;
	s= (Stack)malloc(sizeof(struct SNode));
	s->Top = -1;
	int M, N, K;
	int j,cnt;
	int a[1001];
	scanf("%d%d%d", &M, &N, &K);
	int flag ;
	for (; K!=0; K--)
	{
		flag = 1;
		cnt = 1;
		Push(s, cnt++); 
		for (j = 1; j <= N; j++)
		{
			scanf("%d", a+j);
		}
		for (j = 1; j <= N; j++)
		{
			if (s->Data[s->Top]>a[j])
			{
				flag = 0; break;
				
			}
			else
			{
				while (s->Data[s->Top] != a[j])
				{
					Push(s, cnt++);
				}
				if (s->Top > M - 1)
				{
					flag = 0; break;
				}
				else
				{
					Pop(s);
				}
			}
		}
		if(flag)
		{ 
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
			s->Top = -1;
		}
	}
	return 0;
}
