#include<stdio.h>
#include<iostream>

using namespace std;

long long int d[103];
long long int testcase(int a) {
	if (a == 1) return 1;
	if (a == 2)return 1;
	if (a == 3) return 1;
	if (d[a] != 0)return d[a];

	return d[a] = testcase(a - 3) + testcase(a - 2);
}
int main()
{
	int t;

	cin >> t;
	int n;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		printf("%lld\n", testcase(n));
		for (int j = 0; j <= n + 1; j++)
			d[j] = 0;

	}
	return 0;
}