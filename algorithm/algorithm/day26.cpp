#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int inDegree[10];
const int n = 7;
vector<int> a[10];

void topologySort() {
	int result[10];
    queue<int> q;
	
	for (int i = 1; i <= n; i++)
	{
		if (inDegree[i] == 0) q.push(i);
	}

	for (int i = 1; i <= n; i++)
	{
		if (q.empty())
		{
			printf("사이클이 발생했습니다");
			return;
		}

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

	a[1].push_back(2);
	inDegree[2]++;
	a[1].push_back(5);
	inDegree[5]++;
	a[2].push_back(3);
	inDegree[3]++;
	a[3].push_back(4);
	inDegree[4]++;
	a[4].push_back(6);
	inDegree[6]++;
	a[5].push_back(6);
	inDegree[6]++;
	a[6].push_back(7);
	inDegree[7]++;
	topologySort();
}