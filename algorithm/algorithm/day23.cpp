#include<stdio.h>

int v = 8;
int a[100001];

void primeNumberSieve()
{
	for (int i = 2; i <= v; i++)
		a[i] = i;

	for (int i = 2; i <= v; i++)
	{
		if (a[i] == 0) continue;

		for (int j = i * 2; j <= v; j += i)
		{
			a[j] = 0;
		}
	}
}

int main()
{
	primeNumberSieve();
	for (int i = 2; i <= v; i++)
	{
		if (a[i] != 0)
			printf("%d ", a[i]);

	}
}