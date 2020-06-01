#include<iostream>
#include<algorithm>
#include<cmath>
#include<stdlib.h>

using namespace std;
int main(void)
{
	string n;
	cin >> n;

	int arr[100001];

	for (int i = 0; i < n.size(); i++)
	{
		arr[i] = n[i] - '0';
	}
	sort(arr, arr + n.size());

	if (arr[0] != 0)
		printf("-1\n");
	else
	{
		string temp;
		long long int sum = 0;

		for (int i = 0; i < n.size(); i++)
		{
			sum += arr[i];
		}
		if (sum % 3 == 0)
		{
			for (int i = n.size() - 1; i >= 0; i--)
			{
				printf("%d", arr[i]);
			}
		}
		else
			printf("-1\n");

	}
}