#include<iostream>
#include<algorithm>
#include<stdio.h>

using namespace std;
int sortedArr[5000001];

void merge(int a[], int m, int n, int middle)
{
	int i = m;
	int j = middle+1;
	int k = m;

	while (i <= middle && j <= n)
	{
		if (a[i] <= a[j])
		{
			sortedArr[k] = a[i];
			i++;
		}
		else {
			sortedArr[k] = a[j];
			j++;
		}
		k++;
	}
	if (i > middle)
	{
		for (int t = j; t <= n; t++)
		{
			sortedArr[k] = a[t];
			k++;
		}
	}
	else 
	{
		for (int t = i; t <= middle; t++)
		{
			sortedArr[k] = a[t];
			k++;
		}
	}

	for (int i = m; i <= n; i++)
		a[i] = sortedArr[i];

}

void mergeSort(int a[], int m, int n)
{
	if (m < n)
	{
		int middle = (m + n) / 2;

		mergeSort(a, m, middle);
		mergeSort(a, middle + 1, n);
		merge(a, m, n, middle);

	}
}

int main()
{
	cin.tie(NULL);
	//sync_with_stdio(false);

	int arr[5000001] = { 0, };
	int k, n;

	cin >> n >> k;

	for (int i = 0; i < n; i++)
		scanf("%d",&arr[i]);

	mergeSort(arr, 0, n - 1);

	printf("%d",arr[k - 1]);

	return 0;
}
