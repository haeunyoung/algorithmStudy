#include<stdio.h>
#include<algorithm>

using namespace std;
int main(void)
{
	int n, c;
	int arr[100001];
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + n);
	int max = 0;
	c = n;
	int weight;
	for (int i = 0; i < n; i++)
	{
		weight = arr[i] * c;
		if (max < weight)
			max = weight;
		c--;
	}

	printf("%d\n", max);
}