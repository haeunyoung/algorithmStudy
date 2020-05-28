#include<iostream>
#include<stdio.h>

using namespace std;
int n, k = 0;
int arr[501][501];
int d[501][501];

int dp(int i,int j)
{
	if (d[i][j] != 0) return d[i][j];
	else
	{
		int count[4] = { 0, };
		if (j + 1 != n)
		{
			if (arr[i][j] < arr[i][j + 1])
			{
				count[0]++;
				count[0] += dp(i, j + 1);

			}

		}
		if (i + 1 != n)
		{
			if (arr[i][j] < arr[i + 1][j])
			{
				count[1]++;
				count[1] += dp(i + 1, j);
			}
		}
		if (i - 1 != -1)
		{
			if (arr[i][j] < arr[i - 1][j])
			{
				count[2]++;
				count[2] += dp(i - 1, j);

			}
		}
		if (j - 1 != -1)
		{
			if (arr[i][j] < arr[i][j - 1])
			{
				count[3]++;
				count[3] += dp(i, j - 1);

			}

		}
		int m = 0;
		for (int i = 0; i < 4; i++)
		{
			if (m < count[i])
				m = count[i];
		}
		if (m == 0)
			return 1;
		return d[i][j]=m;
	}
}
int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{

			int temp=dp(i, j);
			if (temp > max)
				max = temp;
		}
	}
	cout << max;
}