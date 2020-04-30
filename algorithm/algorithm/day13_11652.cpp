#include<stdio.h>
#include<algorithm>

using namespace std;
int main()
{
	int n;
	long long arr[100001];
	long long count[100001];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &arr[i]);

	sort(arr, arr + n);

	int a = 0;
	long long c = arr[0];
	int count_num = 0;
	for (int i = 0; i < n; i++)
	{
		if (c == arr[i])
		{
			count_num++;
			if (i == n - 1)
			{
				count[a] = count_num;

			}
		}
		else
		{
			count[a] = count_num;
			count_num = 0;
			a++;
			c = arr[i];
			count_num++;
			if (i == n - 1)
				count[a] = count_num;

		}
	}

	int max_index = 0;
	for (int i = 0; i < a + 1; i++)
	{
		if (count[max_index] < count[i])
			max_index = i;
	}
	int temp = 0;
	for (int i = 0; i < max_index; i++)
	{
		temp += count[i];
	}

	printf("%lld", arr[temp]);
	return 0;
}