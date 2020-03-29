#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 8

int stack[MAX_SIZE], top = -1, b[MAX_SIZE], k;

void transfdec_bin(int nr)
{
	int i;
	k = 0;
	for (i = 0; i < MAX_SIZE; i++)
		b[i] = 0;
	while (nr > 0)
	{
		b[k] = nr % 2;
		nr = nr / 2;
		k++;
	}

}
void invers(int nr)
{
	nr = nr ^ 255;
	transfdec_bin(nr);
}

void push(int nr)
{
	if (top == MAX_SIZE - 1)
	{
		printf("\nEroare : Stiva este plina\n ");
		return;
	}
	stack[++top] = nr;
}

void pop()
{
	if (top == -1)
	{
		printf("\nEroare : stiva este goala\n");
		return;
	}
	top--;
}
int main()
{
	int N, i, j, x;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &x);
		transfdec_bin(x);
		for (j = 7; j >= 0; j--)
			printf("%d", b[j]);
		printf("\n");
		invers(x);
		for (j = 0; j <= 7; j++)
			push(b[j]);
		while (top != -1)
		{
			printf("%d", stack[top]);
			pop();
		}
		printf("\n");
	}
	system("pause");
	return 0;
}