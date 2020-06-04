#include<iostream>
#include<algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	int arr[1001];

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	
	sort(arr, arr + n);
	int plus[10000000] = { 0, };
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n ; j++)
		{
			if (i == 0)
			{
				plus[j] = arr[j];
			}
			else
			{
				if (j + i >= n)
				{
					plus[n * i + j] = arr[j + i - n] + plus[n * (i - 1) + j];
				}
				else
					plus[n * i + j] = arr[j + i] + plus[n * (i - 1) + j];
			}
		}

	}
	sort(plus, plus + 10000000);

	int front = plus[0];
	int back = plus[1];
	int answer = (front + back) / 2;
	int front_index = 0, back_index = 1;

	while (front - back < 2)
	{
		front_index++;
		back_index++;
		front = plus[front_index];
		back = plus[back_index];
		answer = (front + back) / 2;
	}
	
	printf("%d\n", answer);

}