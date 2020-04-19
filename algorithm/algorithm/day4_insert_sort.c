#include<stdio.h>

int main()
{
	int arr[10] = { 1,10,5,8,7,6,4,3,2,9 };
/*
	for (int i = 1; i < 10; i++)
	{
		int com = 100;
		int count = i-1;
		while (com > arr[i])
		{
			com = arr[i - 1];
			if (com > arr[i])
			{
				count = count - 1;
				com = arr[count];
			}


		}
		int temp = 0;
		if (com <= arr[i])
		{
			temp = arr[i];
			for (int j = i; j > count; j--)
			{
				if (j != count + 1)
					arr[j] = arr[j - 1];
				else
					arr[j] = temp;

			}
		}
	}

	*/
	int i, j, temp;
	for (i = 0; i < 9; i++)
	{
		j = i;
		while (arr[j] > arr[j + 1])
		{
			temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
			j--;

		}
	}
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	return 0;
}