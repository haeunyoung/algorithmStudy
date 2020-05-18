#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<int> a[32001];
int n, m, inDegree[32000], result[32000];

void topologySort()
{
	queue<int> q;

	for (int i = 1; i <= n; i++)
	{
		if (inDegree[i] == 0) q.push(i);

	}

	for (int i = 1; i <= n; i++)
	{
		int x = q.front();
		q.pop();
		result[i] = x;
		for (int j = 0; j < a[x].size(); j++)
		{
			int y = a[x][j];
			inDegree[y]--;
			if (inDegree[y] == 0)
				q.push(y);

		}

	}

	for (int i = 1; i <= n; i++)
		printf("%d ", result[i]);


}
int main(void)
{
	cin >> n >> m;
	int temp_a, temp_b;

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &temp_a, &temp_b);
		a[temp_a].push_back(temp_b);
		inDegree[temp_b]++;
	}

	topologySort();

}