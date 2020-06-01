#include<iostream>
#include<queue>
using namespace std;

int main(void)
{
	int n;
	int arr[11];
	queue<int> q;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int answer[11] = {0,};
	int check[11] = { 0, };
	for (int i = 0; i <n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (check[j] == 0)
			{
				q.push(j);
			}
		}
		for (int j = 0; j < arr[i]; j++)
		{
			q.pop();
		}
		check[q.front()] = 1;
		answer[q.front()] =i+1;
		while (!q.empty())
		{
			q.pop();
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d ", answer[i]);
}