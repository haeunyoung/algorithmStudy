#include<stdio.h>

int main()
{
	int n;
	int arr[1000];
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &arr[i]);
	int i, j, temp;

	for (i = 0; i < n; i++)
	{
		j = i;
		while(j > 0 && arr[j] <arr[j-1])
		{
			temp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] =temp;
			j--;
		}

	}
	for (int i = 0; i < n; i++)
		printf("%d\n",arr[i]);
	return 0;
}