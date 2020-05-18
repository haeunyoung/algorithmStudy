#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> v[502];
int indegree[502];
int n;
int arr[502];
int result[502];
void topologySort()
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
		{
			result[i] = arr[i];
			q.push(i);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		int x = q.front();
		q.pop();

		for (int j = 0; j < v[x].size(); j++)
		{
			int y = v[x][j];
			result[y] = max(result[y], result[x] + arr[y]);
			indegree[y]--;
			if (indegree[y] == 0) q.push(y);
		}

	}
	for (int i = 1; i <= n; i++)
		printf("%d\n", result[i]);
}
int main(void)
{
	cin >> n;
	int temp;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
		while (1)
		{
			scanf("%d", &temp);
			if (temp == -1)break;
			v[temp].push_back(i);
			indegree[i]++;
		}
	}

	topologySort();
}