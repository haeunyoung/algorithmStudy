#include<stdio.h>

int d[31];
int dp(int i)
{
	if (i&2==1)return 0;
	if (i == 0) return 1;
	if (i == 2)return 3;
	if (d[i] != 0)return d[i];
	int temp=0;
	for (int t = 1; t <= i - 4; t+=2)
	{
		temp += 2 * dp(t);
	}
	return d[i] = dp(i - 2) * 3+temp;
}

int main()
{
	int n;
	scanf("%d", &n);

	printf("%d\n", dp(n));

	return 0;
}