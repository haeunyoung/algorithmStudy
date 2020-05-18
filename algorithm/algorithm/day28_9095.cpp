#include<iostream>
#include<stdio.h>

using namespace std;
int d[12];
int dp(int num)
{
	if (num == 1) return 1;
	if (num == 2) return 2;
	if (num == 3) return 4;
	if (d[num] != 0) return d[num];
	return d[num] = dp(num - 1) + dp(num - 2) + dp(num - 3);

}

int main(void)
{
	int t;
	int n;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		printf("%d\n",dp(n));
	}
}