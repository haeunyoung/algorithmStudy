#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int arr[1001];

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + n);
	int time = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j >= 0; j--)
		{
			time += arr[j];
		}
	}

	cout << time;
	return 0;
}