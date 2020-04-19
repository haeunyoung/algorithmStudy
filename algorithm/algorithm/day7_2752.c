#include<stdio.h>

int main()
{
	int arr[3];
	for (int i = 0; i < 3; i++)
		scanf_s("%d", &arr[i]);

	int i, j, temp,min_index,min;
	for (i = 0; i < 3; i++)
	{
		min = 1000001;
		for (j = i; j < 3; j++)
		{
			if (min > arr[j])
			{
				min_index = j;
				min = arr[j];
			}
		}
		temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
	}
	for (int i = 0; i < 3; i++)
		printf("%d ", arr[i]);

	return 0;
}