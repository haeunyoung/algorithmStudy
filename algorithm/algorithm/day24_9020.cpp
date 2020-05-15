#include<stdio.h>
#include<iostream>

using namespace std;
int g[10001];
int n;
void gold()
{
	for (int i = 2; i <= n; i++)
		g[i] = i;

	for (int i = 2; i <= n; i++)
	{
		if (g[i] == 0) continue;

		for (int j = i*2; j <= n; j += i)
		{
			g[j] = 0;
		}
	}

	int prime[10000] = { 0, };
	int prime_count = 0;

	for (int i = 2; i <= n; i++)
	{ 
		
		if (g[i] != 0)
		{
			prime[prime_count] = i;
			prime_count++;
		}

	}

	int partition[2] = {0,};
	int partition_m =100000;
	int temp_p;
	for (int i = 0; i < prime_count; i++)
	{
		for (int j = i; j < prime_count; j++)
		{
			if (prime[i] + prime[j] == n)
			{
				temp_p = abs(prime[i] - prime[j]);
				if (partition_m > temp_p)
				{
			
						partition[0] = prime[i];
						partition[1] = prime[j];
					partition_m = temp_p;

				}

				break;
			}
		}
	}

	printf("%d %d\n", partition[0],partition[1]);
}
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		if (i != 0)
		{
			for (int j = 0; j <= n; j++)
				g[j] = 0;

		}
		gold();
		
	}
	
	return 0;
}