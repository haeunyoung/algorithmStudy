#include<stdio.h>
#include<iostream>

using namespace std;
int d[1000001];
int dp(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (d[n] != 0) return d[n];
	return d[n]= (dp(n - 2) + dp(n - 1) )% 15746;

}
int main(void)
{
	int n;
	cin >> n;

	printf("%d\n", dp(n));
}