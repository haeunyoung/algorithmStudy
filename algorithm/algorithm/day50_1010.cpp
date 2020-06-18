#include<iostream>
using namespace std;

int main(void)
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n, m;
		cin >> n >> m;

		long long a = 1;
		long long b = 1;

		if (m - n < n) n = m - n;
		for (int i = m; i > m - n; i--)
		{
			a = a * i;
		}

		for (int i = n; i >= 1; i--)
		{
			b = b * i;
		}

		printf("%lld\n", a / b);
	}
}