/*#include<stdio.h>

int main()
{
	int n;
	int arr[1000001];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	quickSort(arr, 0, n-1);
	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);

	return 0;
}

void quickSort(int* data, int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int i = start + 1, j = end,temp;
	int key = start;
	while (i <= j)
	{
		while (data[key] >= data[i] && i <= end)
			i++;
		while (data[key]<=data[j] && j>start)
			j--;
		if (i > j)
		{
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else
		{
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	quickSort(data, start, j - 1);
	quickSort(data, j+1,end);
}

*/

#include<stdio.h>
#include<algorithm>

int data[1000000];

int main(void)
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
		scanf("%d", &data[i]);
	
	std::sort(data, data + num);

	for (int i = 0; i < num; i++)
		printf("%d\n", data[i]);
	return 0;

}