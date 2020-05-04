#include<stdio.h>

long long int dp[100];
int d(int x)
{
	if (x == 1)return 1;
	if (x == 2)return 1;
	if (dp[x] != 0) return dp[x];
	return dp[x]=d(x - 1) + d(x - 2);
}

int main()
{

	printf("%lld \n", d(50));
}