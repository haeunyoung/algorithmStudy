#include<iostream>

using namespace std;
int n;
long long d[91];
long long dp(int a) {
	if (a == 1) return 1;
	if (a == 2) return 1;

	if (d[a] != 0) return d[a];
	return d[a] = dp(a - 2) + dp(a - 1);
}

int main(void)
{
	cin >> n;
	printf("%lld\n",dp(n));
}