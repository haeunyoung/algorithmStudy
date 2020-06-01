#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n;
int arr[1002];
int d[1002];
int dp(int a)
{
	if (a == 1) return arr[1];

	if (d[a] != 0) return d[a];
	int temp = 0;
	for (int i = 1; i <= a; i++)
	{
		if (i == a - i + 1)break;
		int t = arr[i] + dp(a - i);
		if (temp < t)
			temp = t;

	}
	d[a] = max(arr[a], temp);
	return d[a];
}
int main(void)
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	int result = dp(n);

	printf("%d\n", result);

}