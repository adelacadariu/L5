#include <stdio.h>
#include <stdlib.h>

int s[8], b[8], max=8,t= -1;

void push(int nr)
{
	if (t == max - 1)
	{
		printf("\nEroare : Stiva este plina\n ");
		return;
	}
	s[++] = nr;
}

void pop()
{
	if (t== -1)
	{
		printf("\nEroare : stiva este goala\n");
		return;
	}
	t--;
}
int peek()
{
	return s[t];
}
int IsEmpty()
{
	if (t == -1)
		return 1;
	return 0;
}
void transfdec_bin(int nr)
{
	int i,c = 0;
	for (i = 0; i < maxim; i++)
		b[i] = 0;
	while (nr > 0)
	{
		b[c++] = nr % 2;
		nr = nr / 2;
	}

}

int main()
{
	int nr, cnt = 0, i;
	scanf("%d", &nr);
	transfdec_bin(nr);
	for (i = 0; i < maxim; i++)
		push(b[i]);
	while (IsEmpty() == 0)
	{
		printf("%d", peek());
		if (peek() == 1)
			count++;
		pop();
	}
	for (i = 0; i <= 7 - cnt; i++)
		push(0);
	for (i = 7 - cnt; i < 7; i++)
	     push(1);
	while (IsEmpty() == 0)
	{
		printf("%d", peek());
		pop();
	}
	printf("\n");
	system("pause");
	return 0;
}
