#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int sorted[100001];
char name[100001][100];
char sortedName[100001][100];
void merge(int a[], int m, int middle, int n)
{
	int i = m;
	int j = middle + 1;
	int k = m;

	while (i <= middle && j <= n)
	{
		if (a[i] <= a[j])
		{
			sorted[k] = a[i];
			strcpy(sortedName[k], name[i]);
			i++;
		}
		else {
			sorted[k] = a[j];
			strcpy(sortedName[k], name[j]);
			j++;
		}
		k++;
	}

	if (i > middle)
	{
		for (int t = j; t <= n; t++)
		{
			sorted[k] = a[t];
			strcpy(sortedName[k], name[t]);
			k++;
		}
	}
	else
	{
		for (int t = i; t <= middle; t++)
		{
			sorted[k] = a[t];
			strcpy(sortedName[k], name[t]);
			k++;
		}
	}

	for (int i = m; i <= n; i++)
	{
		a[i] = sorted[i];
		strcpy(name[i], sortedName[i]);
	}
}

void mergeSort(int a[], int m, int n)
{
	int middle = (m + n) / 2;
	if (m < n)
	{
		mergeSort(a, m, middle);
		mergeSort(a, middle + 1, n);
		merge(a, m, middle, n);
	}
}
int main()
{
	int n;
	int age[100001];

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &age[i]);
		scanf("%s", name[i]);
	}
	mergeSort(age, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", age[i]);
		printf("%s\n", name[i]);
	}

	return 0;
}