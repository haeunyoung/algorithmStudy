#include<iostream>
#include<vector>
using namespace std;
int arr[20][2];
int n;
int d[20];
int dp(int x)
{
	int max = 0;
	if (d[x] != 0)return d[x];
	if (arr[x][0] + x <= n + 1)
	{
		for (int i = arr[x][0] + x; i <= n; i++)
		{
			int temp = dp(i);
			if (temp > max)
			{
				max = temp;
			}
		}
		return d[x] = arr[x][1] + max;

	}
	else
		return 0;


}
int main(void)
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &arr[i][0], &arr[i][1]);

	}
	int MAX = -1;
	for (int i = 1; i <= n; i++)
	{
		int t = dp(i);
		if (MAX < t)
			MAX = t;
	}
	printf("%d\n", MAX);
}