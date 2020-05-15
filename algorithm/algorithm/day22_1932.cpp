#include<iostream>
#include<stdio.h>
using namespace std;

int arr[503][503];
int d[503][503];
int n;
//그때까지의 최댓값 
//내려오면서 
int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
int dp(int i,int j)
{
	if (i > 0 && j > 0)
	{
		if ((i == 1) && (j == 1)) return d[1][1];
		if (d[i][j] != 0) return d[i][j];
		if (i == j) return d[i][j] = dp(i - 1, j - 1) + arr[i][j];
		return d[i][j] = max(dp(i - 1, j - 1), dp(i - 1, j)) + arr[i][j];
	}
	else return 0;
}
int main(void)
{
	cin >> n;

	for (int i = 1; i <=n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			scanf("%d", &arr[i][j]);
		}

	}
	d[1][1] = arr[1][1];
	int max = 0;
	int temp;
	for (int i = 1; i <= n; i++)
	{
		temp = dp(n, i);
		if (max < temp)
			max = temp;
	}

	printf("%d ", max);
}