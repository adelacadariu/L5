#include <stdio.h>
#include <stdlib.h>



int s[8], t = -1, b[8], maxim=8,cnt;

void transfdec_bin(int nr)
{
	int i;
	cnt= 0;
	for (i = 0; i < 8; i++)
		b[i] = 0;
	while (nr > 0)
	{
		b[k] = nr % 2;
		nr = nr / 2;
		cnt++;
	}

}
void invers(int nr)
{
	nr = nr ^ 255;
	transfdec_bin(nr);
}

void push(int nr)
{
	if (t == maxim - 1)
	{
		printf("\nEroare : Stiva este plina\n ");
		return;
	}
	s[++t] = nr;
}

void pop()
{
	if (t == -1)
	{
		printf("\nEroare : stiva este goala\n");
		return;
	}
	t--;
}
int main()
{
	int n,i, j, a;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a);
		transfdec_bin(a);
		for (j = 7; j >= 0; j--)
			printf("%d", b[j]);
		printf("\n");
		invers(a);
		for (j = 0; j <= 7; j++)
			push(b[j]);
		while (t != -1)
		{
			printf("%d", s[t]);
			pop();
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
