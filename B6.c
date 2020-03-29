#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 8
int stack[MAX_SIZE], b[MAX_SIZE], top = -1;

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
int peek()
{
	return stack[top];
}
int IsEmpty()
{
	if (top == -1)
		return 1;
	return 0;
}
void transfdec_bin(int nr)
{
	int i, k = 0;
	for (i = 0; i < MAX_SIZE; i++)
		b[i] = 0;
	while (nr > 0)
	{
		b[k++] = nr % 2;
		nr = nr / 2;
	}

}

int main()
{
	int nr, count = 0, i;
	scanf("%d", &nr);
	transfdec_bin(nr);
	for (i = 0; i < MAX_SIZE; i++)
		push(b[i]);
	printf("Forma binara : \n\t");
	while (IsEmpty() == 0)
	{
		printf("%d", peek());
		if (peek() == 1)
			count++;
		pop();
	}
	for (i = 0; i <= 7 - count; i++)
		push(0);
	for (i = 7 - count; i < 7; i++)
		push(1);
	printf("\nForma binara maxima :\n\t ");
	while (IsEmpty() == 0)
	{
		printf("%d", peek());
		pop();
	}
	printf("\n");
	system("pause");
	return 0;
}
