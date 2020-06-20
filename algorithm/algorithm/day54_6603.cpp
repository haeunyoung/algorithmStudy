#include<iostream>

using namespace std;

int main(void)
{
	while (1)
	{
		int n;
		cin >> n;
		if (n == 0) break;

		int arr[15];
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}
      
		for (int a = 0; a <= n-6; a++)
		{
			for (int b = a + 1; b <= n - 5; b++)
			{
				for (int c = b + 1; c <= n - 4; c++)
				{
					for (int d = c + 1; d <= n - 3; d++)
					{
						for (int e = d + 1; e <= n - 2; e++)
						{
							for (int f = e + 1; f <= n - 1; f++)
							{
								printf("%d %d %d %d %d %d\n", arr[a], arr[b], arr[c], arr[d], arr[e], arr[f]);
							}
						}
					}
				}
			}
		}

		printf("\n");
	}
}