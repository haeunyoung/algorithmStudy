#include<stdio.h>
#include<iostream>
#include<stack>

using namespace std;

int rgb[1001][3];
int result[1001][3];


int dp(int start, int s_rgb)
{

	if (result[start][s_rgb] != -1)return result[start][s_rgb];
	int min = 100000000;
	int temp;
	for (int i = 0; i < 3; i++)
	{
		if (s_rgb != i)
		{
			temp = dp(start - 1, i);
			if (min > temp)
				min = temp;

		}

	}
	return result[start][s_rgb] = min + rgb[start][s_rgb];
}
int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
			result[i][j] = -1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
			scanf("%d", &rgb[i][j]);
	}

	for (int j = 0; j < 3; j++)
		result[0][j] = rgb[0][j];
	int min = 100000000;
	for (int i = 0; i < 3; i++)
	{
		int x = dp(n - 1, i);
		if (min > x)
			min = x;
	}
	printf("%d\n", min);

	return 0;
}
