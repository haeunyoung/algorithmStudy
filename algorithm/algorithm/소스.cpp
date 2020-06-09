#include<stdio.h>

int main(void)
{
	int arr[10] = { 3,20,60,34,42,13,2,5,7,99 };
	int i, j, temp;
	for (int i = 0; i < 9; i++)
	{
		j = i;
		while (j >= 0 && arr[j] > arr[j + 1])
		{
			temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
			j--;
		}
	}
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);


	
}