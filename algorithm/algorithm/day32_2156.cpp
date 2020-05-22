#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int arr[10001];
int d[10001];
int n;
int ans = 0;
int max(int a, int b)
{

	if (a > b)
	{
		return a;
	}
	else return b;
}
int dp(int point)
{
	if (point == 0) return arr[0];
	if (point == 1) return max(arr[0] + arr[1], arr[1]);
	if (point == 2) return max(arr[0] + arr[2], arr[1] + arr[2]);

	if (d[point] != 0)return d[point];
	int temp1 = arr[point] + arr[point - 1] + dp(point - 3);
	int temp2 = arr[point] + dp(point - 2);
	d[point] = max(temp1, temp2);
	d[point] = max(dp(point - 1), d[point]);
	ans = max(ans, d[point]);
	return d[point];
}
int main(void)
{

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int result = 0;
	int temp;
	for (int i = 3; i <= n+3; i++)
	{
		temp = dp(i);
		if (result < temp)
			result = temp;
	}
	printf("%d\n", result);
}