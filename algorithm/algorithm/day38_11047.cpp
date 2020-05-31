#include<iostream>

using namespace std;

int main(void)
{
	int arr[11];
	int n, k, count = 0;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	int c = n - 1;
	while (k != 0)
	{
		if (arr[c] > k)
		{
			c--;
			continue;
		}

		count += k / arr[c];
		k %= arr[c];
		c--;
	}
	printf("%d\n", count);
}