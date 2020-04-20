#include<stdio.h>
int sorted[1000001][2];
//-1000000~1000000


int  merge(int a[][2], int m, int middle, int n, int array_index) {
	int i = m;
	int j = middle + 1;
	int k = m;
	while (i <= middle && j <= n)
	{
		if (a[i][array_index] <= a[j][array_index])
		{

			sorted[k][0] = a[i][0];
			sorted[k][1] = a[i][1];
			i++;
		}
		else {
			sorted[k][0] = a[j][0];
			sorted[k][1] = a[j][1];
			j++;
		}
		k++;
	}
	if (i > middle)
	{
		for (int t = j; t <= n; t++)
		{
			sorted[k][0] = a[t][0];
			sorted[k][1] = a[t][1];
			k++;
		}
	}
	else {
		for (int t = i; t <= middle; t++)
		{
			sorted[k][0] = a[t][0];
			sorted[k][1] = a[t][1];
			k++;
		}
	}


	for (int i = m; i <= n; i++)
	{
		a[i][0] = sorted[i][0];
		a[i][1] = sorted[i][1];

	}

	return 0;
}


int mergeSort(int a[][2], int m, int n, int index)
{
	int middle;
	if (m < n)
	{
		middle = (m + n) / 2;
		mergeSort(a, m, middle, index);
		mergeSort(a, middle + 1, n, index);
		merge(a, m, middle, n, index);

	}

	return 0;
}

int main()
{
	int n;
	int arr[1000001][2];
	int y_arr[2000001] = { 0, };

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			scanf("%d", &arr[i][j]);

		}

	}

	for (int i = 0; i < n; i++)
	{
		y_arr[arr[i][0] + 1000000] = y_arr[arr[i][0] + 1000000] + 1;

	}


	mergeSort(arr, 0, n - 1, 0);
	int number = n;
	int start = 0;

	while (number > 0)
	{
		mergeSort(arr, start, start + (y_arr[arr[start][0] + 1000000] - 1), 1);
		number = number - y_arr[arr[start][0] + 1000000];
		start += y_arr[arr[start][0] + 1000000];
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
			printf("%d ", arr[i][j]);
		printf("\n");

	}
	return 0;
}