#include<stdio.h>

int node = 8;
int size;
int sorted[8];
int count = 0;

void merge(int a[], int m, int middle, int n)
{
	int i = m;
	int j = middle + 1;
	int k = m;
	//작은 순서대로 배열의 삽입
	while (i <= middle && j <= n)
	{
		if (a[i] <= a[j])
		{
			sorted[k] = a[i];
			i++;
		}
		else {
			sorted[k] = a[j];
			j++;
		}
		k++;

	}
	//남은 데이터도 삽입
	if (i > middle)
	{
		for (int t = j; t <= n; t++)
		{
			sorted[k] = a[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= middle; t++)
		{
			sorted[k] = a[t];
			k++;
		}
	}
	//정렬된 배열은 삽입 
	for (int i = m; i <= n; i++)
		a[i] = sorted[i];
}

void mergeSort(int a[], int m, int n)
{
	//이외의 경우는 크기가 1개인 경우
	if (m < n)
	{
		int middle = (m + n) / 2;
		mergeSort(a, m, middle);
		mergeSort(a, middle + 1, n);
		merge(a, m, middle, n);
	}
}

int main(void)
{

	int array[] = { 7,6,5,8,3,5,9,1 };
	mergeSort(array, 0, node - 1);

	for (int i = 0; i < node; i++)
		printf("%d ", array[i]);

}