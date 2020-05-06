#include<stdio.h>
long long int d[1000001];

int dp(int i)
{
	if (i == 0) return 1;
	if (i == 1) return 2;
	if (i == 2) return 7;
	if (d[i] != 0) return d[i];
 
	int result = 3 * dp(i - 2) + 2 * dp(i - 1);

	for (int t = 3; t <= i; t++)
	{
		result += (2*dp(i - t))%1000000007;
	}
	return d[i]=result;
}

int main(void)
{
	int n;

	scanf("%d", &n);
	printf("%d\n", dp(n));
}