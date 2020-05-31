#include<iostream>

using namespace std;

int main(void)
{
	int n;
	int arr[11];

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int answer[11] = {0,};
	for (int i = 0; i <n; i++)
	{
		int temp = 0;
		int jump = 0;
		while (temp != arr[i])
		{
			if (arr[temp+jump] == 0)
				temp++;
			else
				jump++;
		}
	
		answer[temp+jump] = i + 1;
		printf("%d ", answer[temp + jump]);
	}
	for (int i = 0; i < n; i++)
		printf("%d ", answer[i]);
}